//CSC 134
//
//Julian Palcio
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

//Functions here
void NEWGAME();
void STORYSTART();
void saveGame(string&,string&);
void loadGame(string&,string&);

//Main menu
int main() {
    string main_menu_choice;
    cout << "Welcome to (GAMENAME)" << endl;
    cout << "NEW GAME" << endl;
    cout << "LOAD GAME" << endl;
    cout << "OPTIONS" << endl << endl;
    cin >> main_menu_choice;
    while (main_menu_choice != "NEWGAME" && main_menu_choice != "LOADGAME") {
        cout << "Please enter a valid option!" << endl;
        cin >> main_menu_choice;
    }
    if (main_menu_choice == "NEWGAME") {
        NEWGAME();
    }
    else if (main_menu_choice == "LOADGAME") {
        string filename = "save.txt";
        string name = "name";
        loadGame(filename, name);
    }
}

void NEWGAME() {
    cout << "\033[2J\033[1;1H"; //Clears the screen
    cout << "Starting a new game!" << endl;
    STORYSTART();
}

void loadGame(string& filename, string& name) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> name;
        inFile.close();
        cout << "Game loaded successfully!" << endl;
        cout << name;
    } else {
        cerr << "Unable to open file for loading." << endl;
    }
}

//Start of story
void STORYSTART() {
    cout << "What will your name be?" << endl;
    cout << "Enter name: ";
    string name;
    cin >> name;
    string filename = "save.txt";
    saveGame(filename, name);
    cout << "Welcome, " << name << endl;
    

}
void saveGame(string& filename, string& name) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << name << endl;
        outFile.close();
        cout << "Game saved successfully!" << endl;
    } else {
        cerr << "Unable to open file for saving." << endl;
    }
    return;
}
