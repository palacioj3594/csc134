#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include "getinputcpp.hpp"
#include <bits/stdc++.h>

//https://www.youtube.com/watch?v=vjU62r-M1CY&t=3595s

using namespace std;


typedef struct Armor {
    int defense;
    string name;
} Armor; 

typedef struct Weapon {
    int damage;
    int quality;
    string type;
    string name;
} Weapon;

typedef struct Player {
    int level;
    int strength;
    int dexterity;
    int speed;
    int luck;
    int hp;
    int mp;
    string name;
    Armor armor;
    Weapon weapon;
    int x, y;
} Player;

typedef struct Ally1 {
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

typedef struct Ally2 {
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

typedef struct Tile {
    bool traversable = true;
    bool event_check = false;
    int event = 0;
} Tile;

typedef struct Enemy {
    string name;
    int hp;
    int attack;
    int defense;
    int speed;
} Enemy;

typedef struct Area {
    string name;
} Area;

typedef struct TurnOrder {
    int speed;
    string name;
    bool friendly;
} TurnOrder;

//Constants
const int SLIME = 1;
const int SKELETON = 2;
const int FLY = 3;


const int WIDTH = 11;
const int HEIGHT = 11;

vector<Enemy> enemyPool;

//Functions
void save(const Player& player, const string&);
void load(Player& player, const string&);
void newGame(Player player);
void draw(string);
void gameState(Player& player);
void Grasslands1(bool, Player player);
void fight(bool, Area area, Enemy enemy, Player player);
Enemy create_enemy(int);
void fight_screen(Player player, Enemy enemy, vector<Enemy> fight_array, bool);
void itemMenu(Player player);
int damageCalc(vector<Enemy> fight_array, int, Player player);
void getWeapon(Player& player);
void drawMap(Player player);

int main()  {
    string filename;
    Player player;
    Armor armor;
    Weapon weapon;
    int seed = time(0);
    srand (seed);
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
        player.dexterity = 10;
        player.speed = 10;
        player.luck = 10;
        player.hp = 10;
        player.mp = 10;
        player.armor.name = "Tunic";
        player.weapon.name = "Stick";
        filename = player.name;
        player.x = 6;
        player.y = 6;
        getWeapon(player);
        save(player, filename);
        newGame(player);
    }
    else if(main_menu_choice == "LOAD GAME") {
        load(player, filename);
    }
}

void save(const Player& player, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << player.name << endl;
        outFile << player.level << endl;
        outFile << player.strength << endl;
        outFile << player.dexterity << endl;
        outFile << player.speed << endl;
        outFile << player.luck << endl;
        outFile << player.hp << endl;
        outFile << player.mp << endl;
        outFile << player.armor.name << endl;
        outFile << player.weapon.name << endl;
        outFile << player.x << endl;
        outFile << player.y << endl;
    }
    outFile.close();
}

void load(Player& player, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> player.name;
        inFile >> player.level;
        inFile >> player.strength;
        inFile >> player.dexterity;
        inFile >> player.speed;
        inFile >> player.luck;
        inFile >> player.hp;
        inFile >> player.mp;
        inFile >> player.armor.name;
        inFile >> player.weapon.name;
        inFile >> player.x;
        inFile >> player.y;
    }
    inFile.close();
}

void getWeapon(Player& player) {
    int lineCounter = 1;
    string line;
    ifstream inFile("weapons.txt");
    while (getline(inFile,line)) {
        istringstream iss(line);
        string weapon_name;
        iss >> weapon_name;
        if (weapon_name == player.weapon.name) {
            int damage, quality;
            string type;
            if (iss >> damage >> quality >> type) {
                player.weapon.damage = damage;
                player.weapon.quality = quality;
                player.weapon.type = type;
            }
        }
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
    gameState(player);
}

void gameState(Player& player) {
    Area area;
    area.name = "Beginning Town";
    drawMap(player);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //Town layout goes here, but I don't know how to make the town rn
    cout << "What to do? (PROGRESS MENU)" << endl;
    string choice;
    getline (cin, choice);
    while (choice != "MENU" && choice != "PROGRESS") {
        cout << "INVALID INPUT" << endl;
        cout << "What to do? (PROGRESS MENU)" << endl;
        getline (cin, choice);
    }
    if (choice == "MENU") {
        itemMenu(player);
    }
    else if (choice == "PROGRESS") {
        system("clear");
    bool leavingtown = true;
    Grasslands1(leavingtown, player);
    }
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
    int turn = 0;
    bool fight = true;
    int NUM_ENEMIES;
    TurnOrder turnorder;
    vector<Enemy> fight_array;
    vector<TurnOrder> turn_order;
    vector<TurnOrder>Sorter;
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
    Sorter.push_back({player.speed, player.name, true});
    for (const auto& enemy : fight_array) {
        Sorter.push_back({enemy.speed, enemy.name, false});
    }
    TurnOrder Sorter1;
    while (Sorter.size() > 0) {
        int index = 0;
        Sorter1 = Sorter[0];
        for (int i = 1; i < Sorter.size(); i++) {
            if (Sorter1.speed < Sorter[i].speed) {
                Sorter1 = Sorter[1];
                index = i;
            }
        }
        turn_order.push_back(Sorter1);
        Sorter.erase(Sorter.begin() + index);
    }
    for (const auto& turnorder : turn_order) {
        cout << turnorder.name << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    while (fight == true) {
        turn++;
        bool playerTurn;
        if (turn_order[(turn_order.size() + 1) % turn].friendly == true) {
            playerTurn = true;
        }
        else {
            playerTurn = false;
        }
        fight_screen(player, enemy, fight_array, playerTurn);
        if (playerTurn == true) {
            string fight_choice;
            getline(cin, fight_choice);
            while (fight_choice != "FIGHT" && fight_choice != "MAGIC" && fight_choice != "ITEM") {
                cout << "INVALID INPUT!" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                fight_screen(player, enemy, fight_array, playerTurn);
            }
            if (fight_choice == "FIGHT") {
                cout << "Who do you want to attack? " << endl;
                int target_enemy = get_input<double>(cin, "Enemy: ");
                // repeat until they make a valid enemy target choice
                bool badChoice = true;
                while (badChoice == true) {
                    if (target_enemy > 0 && target_enemy <= fight_array.size()) {
                        target_enemy -= 1;
                        int damage = damageCalc(fight_array, target_enemy, player);
                        fight_array.at(target_enemy).hp -= damage;
                        cout << player.name << " attacked " << fight_array.at(target_enemy).name << " for " << damage << " damage!" << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        badChoice = false;
                        if (fight_array.at(target_enemy).hp <= 0) {
                            fight_array.erase(fight_array.begin() + target_enemy);
                        }
                    } else {
                        cout << "Who do you want to attack? " << endl;
                        target_enemy = get_input<double>(cin, "Enemy: ");
                    }
                }

            }
            else if (fight_choice == "MAGIC") {

            }
            else if (fight_choice == "ITEM") {

            }
        }
        else {
            player.hp--;
        }
        if (fight_array.size() < 1) {
            fight = false;
            cout << "You Won!" << endl;
            return;
        }
        if (player.hp <= 0) {
            fight = false;
            cout << "You have perished..." << endl;
            cout << "Would you like to LOAD or QUIT?" << endl;
            string lose_option;
            getline(cin, lose_option);
            while (lose_option != "LOAD" && lose_option != "QUIT") {
                cout << "INVALID INPUT!" << endl;
                cout << "Would you like to LOAD or QUIT?" << endl;
            }
            if (lose_option == "LOAD") {
                string filename = player.name;
                load(player, filename);
            }
            else if (lose_option == "QUIT") {
                exit(EXIT_SUCCESS);
            }
        }
    }
}

int damageCalc(vector<Enemy> fight_array, int target_enemy, Player player) {
    int damage;
    if (player.weapon.type == "sword") {
        int strMOD = player.level + player.strength;
        if (player.weapon.quality == 0) {
            damage = (player.weapon.damage * strMOD) / fight_array.at(target_enemy).defense;
        }
        else {
            damage = ((player.weapon.damage * strMOD) / fight_array.at(target_enemy).defense) + ((rand() % player.weapon.quality) + 1);
        }
    }
    else if (player.weapon.type == "fist") {
        int fistMOD = player.level + ((player.strength + player.dexterity) / 2);
        if (player.weapon.quality == 0) {
            damage = (player.weapon.damage * fistMOD) / fight_array.at(target_enemy).defense;
        }
        else {
            damage = ((player.weapon.damage * fistMOD) / fight_array.at(target_enemy).defense) + ((rand() % player.weapon.quality) + 1);
        }
    }
    return damage;
}

void fight_screen(Player player, Enemy enemy, vector<Enemy> fight_array, bool playerTurn) {
    system("clear");
    cout << player.name << " " << player.level << ":" << endl;
    cout << "HP: " << player.hp << "\t MP: " << player.mp << endl;
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
    if (playerTurn == true) {
        cout << "Choose an action: " << endl;
        cout << "FIGHT \t MAGIC \t ITEM" << endl;
    }
    else {
        cout << "Enemy Turn..." << endl;
    }
}

void itemMenu(Player player) {
    system("clear");
    cout << "ITEM MENU" << endl;
    cout << endl;
    cout << player.name << endl;
    cout << player.weapon.name << endl;
    cout << endl;
    cout << "Menu option (WEAPON, CLOSE): ";
    string menu_choice1;
    getline(cin, menu_choice1);
    while (menu_choice1 != "WEAPON" && menu_choice1 != "CLOSE") {
        cout << "INVALID OPTION" << endl;
        cout << "Menu option (WEAPON, CLOSE): ";
        getline(cin, menu_choice1);
    }
    if (menu_choice1 == "WEAPON") {

    }
}

Enemy create_enemy(int enemy_type) {
    Enemy enemy;
    switch (enemy_type) {
        case SLIME:
            enemy.name = "Slime";
            enemy.hp = 5;
            enemy.attack = 1;
            enemy.defense = 3;
            enemy.speed = 10;
            break;
        case SKELETON:
            enemy.name = "Skeleton";
            enemy.hp = 5;
            enemy.attack = 3;
            enemy.defense = 5;
            enemy.speed = 15;
            break;
        case FLY:
            enemy.name = "Fly";
            enemy.hp = 1;
            enemy.attack = 0;
            enemy.defense = 1;
            enemy.speed = 1000;
            break;
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

void drawMap(Player player) {
    system("clear");
    int drawX = player.x;
    int drawY = player.y;
    int lineCheck = drawY - 5;
    int charCheck1 = drawX - 5;
    int charCheck2 = drawX + 5;
    int charCheck3 = 1;
    ifstream inFile("map.txt");
    string line;
    string x;
    char del = ' ';
    int current_line = 1;
    for (int i = 1; i < drawY + 5; i++) {
        int charCheck1 = drawX - 5;
        int charCheck2 = drawX + 5;
        int charCheck3 = 1;
        while (getline(inFile, line)) { 
            if(current_line == lineCheck) {
                stringstream ss(line);
                while (getline(ss,x,del)) {
                    if (charCheck3 >= charCheck1 && charCheck3 <= charCheck2) {
                        cout << x;
                    }
                    charCheck3++;
                }
            }
            current_line++;
            cout << current_line << charCheck1 << charCheck2 << charCheck3;
            //std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        lineCheck++;
    }
}