#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

//https://www.youtube.com/watch?v=vjU62r-M1CY&t=3595s

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
    float speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
} Player;

typedef struct Ally1 {
    int level;
    int strength;
    int agility;
    float speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
} Ally1;

typedef struct Ally2 {
    int level;
    int strength;
    int agility;
    float speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
} Ally2;

typedef struct Tile {
    bool level;
    bool traversable = true;
    int event = 0;
} Tile;

typedef struct Enemy {
    string name;
    int hp;
    int attack;
    int defense;
    float speed;
} Enemy;

typedef struct Area {
    string name;
} Area;

//Constants
const int SLIME = 1;
const int SKELETON = 2;
const int FLY = 3;

vector<Enemy> enemyPool;

//Functions
void save(const Player& player, const Armor& armor, const Weapon& weapon, const string&);
void load(Player& player, Armor& armor, Weapon& weapon, const string&);
void newGame(Player player);
void draw(string);
void Beginning_Town1(Player player);
void Grasslands1(bool, Player player);
void fight(bool, Area area, Enemy enemy, Player player);
Enemy create_enemy(int);

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
        system("clear");
        cout << "Welcome to [GAMENAME]" << endl;
        cout << "NEW GAME" << endl;
        cout << "LOAD GAME" << endl;
        getline (cin, main_menu_choice);
    }
    if (main_menu_choice == "NEW GAME") {
        system("clear");
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
    system("clear");
    cout << "Welcome, " << player.name << endl;
    cout << "You are a hero in a fantasy setting, and you have lived in the same city for your entire life." << endl;
    cout << "You have been helping feed the animals, tend to the crops, and helping around your land." << endl;
    cout << "In this world, there exists magic, which almost anyone can use, but few can master." << endl;
    cout << "The hero's life is about to change.. as a great calamity approaches the town he lives in..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    string screen = "Chapter 1";
    draw(screen);
    system("clear");
    cout << "Story stuff goes here. (WIP)" << endl;
    system("clear");
    Beginning_Town1(player);
}

void Beginning_Town1(Player player) {
    Area area;
    area.name = "Beginning Town";

    //Town layout goes here, but I don't know how to make the town rn
    system("clear");
    bool leavingtown = true;
    Grasslands1(leavingtown, player);
}

void Beginning_Town2() {

}

void Grasslands1(bool leavingtown, Player player) { 
    Area area;
    Enemy enemy;
    area.name = "Grasslands1";
    enemyPool.clear();
    enemyPool.push_back(create_enemy(SLIME));
    enemyPool.push_back(create_enemy(FLY));
    bool fight1 = false;
    if (leavingtown == true) {
        fight1 = true;
        leavingtown = false;
    }
    fight(fight1, area, enemy, player);
}

void fight(bool fight1, Area area, Enemy enemy, Player player) {
    bool fight = true;
    int NUM_ENEMIES;
    vector<Enemy> fight_array;
    fight_array.clear();
    if (fight1 == true) {
        NUM_ENEMIES = 1;
    }
    for (int i = 0; i < NUM_ENEMIES; i++) {
        int option = rand() % enemyPool.size();
        fight_array.push_back(enemyPool[option]);
    }
    cout << "You encounter: ";
    for (const auto& enemy : fight_array) {
        cout << enemy.name << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("clear");
    while (fight == true) {
        cout << player.name << " " << player.level << ":" << endl;
        cout << player.hp << "\t" << player.mp << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Enemies: " << endl;
        for (const auto& enemy : fight_array) {
        cout << enemy.name << "\t";
        }
        cout << endl;
        for (const auto& enemy : fight_array) {
        cout << enemy.hp << "\t";
        }
        cout << endl;
        cout << "Choose an action: " << endl;
        cout << "FIGHT \t MAGIC \t ITEM" << endl;
        fight = false;
    }
}

Enemy create_enemy(int enemy_type) {
    Enemy enemy;
    switch (enemy_type) {
        case SLIME:
            enemy.name = "Slime";
            enemy.hp = 5;
            enemy.attack = 1;
            enemy.defense = 0;
            enemy.speed = 10;
        case SKELETON:
            enemy.name = "Skeleton";
            enemy.hp = 5;
            enemy.attack = 3;
            enemy.defense = 5;
            enemy.speed = 15;
        case FLY:
            enemy.name = "Fly";
            enemy.hp = 1;
            enemy.attack = 0;
            enemy.defense = 0;
            enemy.speed = 1000;
    }
    return enemy;
}

void draw(string screen) {
    if (screen == "Chapter 1") {   
        system("clear");
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
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
}