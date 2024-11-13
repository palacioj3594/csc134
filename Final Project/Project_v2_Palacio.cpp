#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <random>


using namespace std;


typedef struct Armor {
    int defense;
} Armor; 

typedef struct Weapon {
    int damage;
    int quality;
    string name;
} Weapon;

typedef struct Player {
    int level;
    int strength;
    int agility;
    int speed;
    int luck;
    int hp;
    int mp;
    string name;
//    Armor armor;
//    Weapon weapon;
} Player;

typedef struct Slime {
    string name = "Slime";
    int hp = 5;
    int attack = 1;
} Slime;

//Functions
void save(const Player& player, const string&);
void load(Player& player, const string&);
void newGame(const Player& player);

int main()  {
    string filename = "savedata";
    Player player;
    cout << "Welcome to [GAMENAME]" << endl;
    cout << "NEW GAME" << endl;
    cout << "LOAD GAME" << endl;
    string main_menu_choice;
    getline(cin, main_menu_choice);
    while (main_menu_choice != "NEW GAME" && main_menu_choice != "LOAD GAME") {
        cout << "INVALID INPUT!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "\033[2J\033[1;1H";
        cout << "Welcome to [GAMENAME]" << endl;
        cout << "NEW GAME" << endl;
        cout << "LOAD GAME" << endl;
        getline (cin, main_menu_choice);
    }
    if (main_menu_choice == "NEW GAME") {
        cout << "\033[2J\033[1;1H";
        cout << "What is the hero's name?" << endl;
        cout << "Enter name: ";
        getline(cin, player.name);
        player.level = 1;
        player.strength = 10;
        player.agility = 10;
        player.speed = 10;
        player.luck = 10;
        player.hp = 10;
        player.mp = 10;
        save(player, filename);
        newGame(player);
    }
    else if(main_menu_choice == "LOAD GAME") {
        load(player, filename);
    }

//    player.weapon.name;
    
    save(player, filename);
}

void save(const Player& player, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << player.name << endl;
        outFile << player.level << endl;
        outFile << player.strength << endl;
        outFile << player.agility << endl;
        outFile << player.speed << endl;
        outFile << player.luck << endl;
        outFile << player.hp << endl;
        outFile << player.mp << endl;
    }
    outFile.close();
}

void load(Player& player, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> player.name;
        inFile >> player.level;
        inFile >> player.strength;
        inFile >> player.agility;
        inFile >> player.speed;
        inFile >> player.luck;
        inFile >> player.hp;
        inFile >> player.mp;
    }
    inFile.close();
}

void newGame(const Player& player) {

}