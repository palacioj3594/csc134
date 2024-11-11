//CSC 134
//
//Julian Palcio
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

//Functions here
void NEWGAME();
void STORYSTART();
void saveGame(string&,string&,int&,int&,int&,int&,int&,int&,string&);
void loadGame(string&,string&,int&,int&,int&,int&,int&,int&,string&);
void draw(string);
void FIGHT(string);

//Main menu
int main() {
    string main_menu_choice;
    cout << "Welcome to (GAMENAME)" << endl;
    cout << "1. NEW GAME" << endl;
    cout << "2. LOAD GAME" << endl;
    cin >> main_menu_choice;
    while (main_menu_choice != "1" && main_menu_choice != "2") {
        cout << "Please enter a valid option!" << endl;
        cin >> main_menu_choice;
    }
    if (main_menu_choice == "1") {
        NEWGAME();
    }
    else if (main_menu_choice == "2") {
        string filename = "save.txt";
        string name = "name";
        int player_str = player_str;
        int player_agi = player_agi;
        int player_spd = player_spd;
        int player_luck = player_luck;
        int player_HP = player_HP;
        int player_MP = player_MP;
        string player_armor = player_armor;
        loadGame(filename, name, player_str, player_agi, player_spd, player_luck, player_HP, player_MP, player_armor);
    }
}

void NEWGAME() {
    cout << "\033[2J\033[1;1H"; //Clears the screen
    cout << "Starting a new game!" << endl;
    STORYSTART();
}

void loadGame(string& filename, string& name, int& player_str, int& player_agi, int& player_spd, int& player_luck, int& player_HP, int& player_MP, string& player_armor) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> name;
        inFile >> player_str;
        inFile >> player_agi;
        inFile >> player_spd;
        inFile >> player_luck;
        inFile >> player_HP;
        inFile >> player_MP;
        inFile >> player_armor;
        inFile.close();
        cout << "Game loaded successfully!" << endl;
        cout << name;
    } 
    else {
        cerr << "Unable to open file for loading." << endl;
    }
}

void saveGame(string& filename, string& name, int& player_str, int& player_agi, int& player_spd, int& player_luck, int& player_HP, int& player_MP, string& player_armor) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << name << endl;
        outFile << player_str << endl;
        outFile << player_agi << endl;
        outFile << player_spd << endl;
        outFile << player_luck << endl;
        outFile << player_HP << endl;
        outFile << player_MP << endl;
        outFile << player_armor << endl;
        outFile.close();
        cout << "Game saved successfully!" << endl;
    } 
    else {
        cerr << "Unable to open file for saving." << endl;
    }
    return;
}
//Start of story
void STORYSTART() {
    cout << "What is the hero's name?" << endl;
    cout << "Enter name: ";
    string name;
    cin >> name;
    int level = 1;
    int player_str = 10;
    int player_agi = 10;
    int player_spd = 10;
    int player_luck = 10;
    int player_HP = 10;
    int player_MP = 10;
    string player_armor = "TUNIC";
    string filename = "save.txt";
    saveGame(filename, name, player_str, player_agi, player_spd, player_luck, player_HP, player_MP, player_armor);
    cout << "\033[2J\033[1;1H";
    cout << "Welcome, " << name << endl;
    cout << "You are a hero in a fantasy setting, and you have lived in the same city for your entire life." << endl;
    cout << "You have been helping feed the animals, tend to the crops, and helping around your land." << endl;
    cout << "In this world, there exists magic, which almost anyone can use, but few can master." << endl;
    cout << "The hero's life is about to change.. as a great calamity approaches the town he lives in..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    string screen = "1";
    draw(screen);
    cout << "\033[2J\033[1;1H";
    cout << "This is the prologue, of which i havent written yet (TODO)" << endl;
    //Other text and things will go here, leading up to the hero leaving toen and going to a temple
    FIGHT(screen);

}

void FIGHT(string screen){
    bool fight1 = true;
    screen = "SLIME";
    cout << "Fight 1 goes here and explains the actions and the game" << endl;
    draw(screen);
}

void draw(string screen) {
    if (screen == "1") {   
        cout << "\033[2J\033[1;1H";
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "|   ------   |     |            /|                                         |" << endl;
        cout << "|  /         |     |           / |                                         |" << endl;
        cout << "| |          |_____|          /  |                                         |" << endl;
        cout << "| |          |     |             |                                         |" << endl;
        cout << "| |          |     |             |                                         |" << endl;
        cout << "|  \\______   |     |   @     ____|____                                     |" << endl;
        cout << "|                                                                          |" << endl;
        cout << "|                                                                          |" << endl;
        cout << "|                                           The Prologue                   |" << endl;
        cout << "|                                                                          |" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return;
    }
    if (screen == "SLIME") {
        cout << "\033[2J\033[1;1H";
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "|                                                                          |" << endl;
        cout << "|                      __________________________                          |" << endl;
        cout << "|                     /                          \\                         |" << endl;
        cout << "|                    /        _           _       \\                        |" << endl;
        cout << "|                   |        | |         | |       |                       |" << endl;
        cout << "|                   |        |_|         |_|       |                       |" << endl;
        cout << "|                   |               M              |                       |" << endl;
        cout << "|                   \\                             /                        |" << endl;
        cout << "|                    \\___________________________/                         |" << endl;
        cout << "|    FIGHT     ITEM     MAGIC     FLEE                                     |" << endl;
        cout << "----------------------------------------------------------------------------" << endl;

    }
}