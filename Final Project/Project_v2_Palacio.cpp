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
    string name;
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
    Armor armor;
    Weapon weapon;
} Player;

struct Ally1 {
    int level;
    int strength;
    int agility;
    int speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
} Ally1;

struct Ally2 {
    int level;
    int strength;
    int agility;
    int speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
} Ally2;

typedef struct Block {
    int x;
    int y;
    string type;
} Block;

typedef struct Tile {
    int x;
    int y;
    string type;
    Block block;
} Tile;

typedef struct Slime {
    string name = "Slime";
    int hp = 5;
    int attack = 1;
} Slime;

//Functions
void save(const Player& player, const Armor& armor, const Weapon& weapon, const string&);
void load(Player& player, Armor& armor, Weapon& weapon, const string&);
void newGame(Player player);
void draw(string);
void Beginning_Town();

int main()  {
    string filename = "savedata";
    Player player;
    Armor armor;
    Weapon weapon;
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
        player.armor.name = "TUNIC";
        player.weapon.name = "STICK";
        save(player, armor, weapon, filename);
        newGame(player);
    }
    else if(main_menu_choice == "LOAD GAME") {
        load(player, armor, weapon, filename);
    }

//    player.weapon.name;
    
    save(player, armor, weapon, filename);
}

void save(const Player& player, const Armor& armor, const Weapon& weapon, const string& filename) {
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
        outFile << player.armor.name << endl;
        outFile << player.weapon.name << endl;
    }
    outFile.close();
}

void load(Player& player, Armor& armor, Weapon& weapon, const string& filename) {
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
        inFile >> player.armor.name;
        inFile >> player.weapon.name;
    }
    inFile.close();
}

void newGame(Player player) {
    cout << "\033[2J\033[1;1H";
    cout << "Welcome, " << player.name << endl;
    cout << "You are a hero in a fantasy setting, and you have lived in the same city for your entire life." << endl;
    cout << "You have been helping feed the animals, tend to the crops, and helping around your land." << endl;
    cout << "In this world, there exists magic, which almost anyone can use, but few can master." << endl;
    cout << "The hero's life is about to change.. as a great calamity approaches the town he lives in..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    string screen = "1";
    draw(screen);
    cout << "\033[2J\033[1;1H";
    cout << "Story stuff goes here. (WIP)" << endl;
    Beginning_Town();
}

void Beginning_Town() {
    
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
}