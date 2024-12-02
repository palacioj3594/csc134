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
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//Seed Generation
void seed_generation(int time) {
int seed = time;
srand(seed);
}

//Functions here
void seed_generation(int);
void NEWGAME();
void STORYSTART();
void saveGame(string&,string&,int&,int&,int&,int&,int&,int&,int&,string&,string&,vector<string>&);
void loadGame(string&,string&,int&,int&,int&,int&,int&,int&,int&,string&,string&,vector<string>&);
void draw(string);
void FIGHT(string,string,bool,int,int,int,int,int,int,int,int,string,string);

//Int Functions here
int damage_roll(int,string);
int enemy_turn(string);
int enemy_damage_calculation(string);
int FIGHT_ITEM_MENU();

//String Functions here



//Enemy array values
int ev_x_size = 1;
int ev_y_size = 3;
int ENEMY_VALUES[3][1] = {
    {5}, //HP
    {1}, //ATTACK
    {1}  //
};




//Weapon values
int wv_x_size = 1;
int wv_y_size = 2;
int WEAPON_VALUES[3][1] = {
    {1},
    {0},
    {1}
};
int wt_size = 1;
string WEAPON_TYPES[1] = {"STICK"};



//Main menu
int main() {
    seed_generation(time(0));
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
        int level = level;
        int player_str = player_str;
        int player_agi = player_agi;
        int player_spd = player_spd;
        int player_luck = player_luck;
        int player_HP = player_HP;
        int player_MP = player_MP;
        string player_armor = "player_armor";
        string player_weapon = "player_weapon";
        vector<string> ITEMS;
        loadGame(filename, name, level, player_str, player_agi, player_spd, player_luck, player_HP, player_MP, player_armor, player_weapon, ITEMS);
    }
}

//This function claculates things
int damage_roll(int player_str, string player_weapon) {
    double PLAYER_STR_MOD = floor((player_str - 10)/2);
    int quality;
    int bonus_damage;
    for (int i = 0; i <= wt_size; i++) {
        if (player_weapon == WEAPON_TYPES[i]) {
            int weapon_file_check = i;
            int damage = WEAPON_VALUES[0][i];
            quality = WEAPON_VALUES[2][i];
            bonus_damage = WEAPON_VALUES[1][i];
        }
    }
    int dice_roll;
    if (quality == 1) {
        dice_roll = rand() % 4;
    }
    else if (quality == 2) {
        dice_roll = rand() % 6;
    }
    else if (quality == 3) {
        dice_roll = rand() % 8;
    }
    else if (quality == 4) {
        dice_roll = rand() % 10;
    }
    else if (quality == 5) {
        dice_roll = rand() % 12;
    }
    else if (quality == 6) {
        dice_roll = rand() % 20;
    }
    else if (quality == 7) {
        dice_roll = rand() % 100;
    }
    int total = PLAYER_STR_MOD + (dice_roll + 1) + bonus_damage;
    int crit = (rand() % 100) + 1;
    if (crit == 100) {
        total = total * 2;
    }
    return(total); 
}

//This is the start of a new game
void NEWGAME() {
    system("clear"); //Clears the screen
    cout << "Starting a new game!" << endl;
    STORYSTART();
}

void loadGame(string& filename, string& name, int& level, int& player_str, int& player_agi, int& player_spd, int& player_luck, int& player_HP, int& player_MP, string& player_armor, string& player_weapon, vector<string>& ITEMS) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> name;
        inFile >> level;
        inFile >> player_str;
        inFile >> player_agi;
        inFile >> player_spd;
        inFile >> player_luck;
        inFile >> player_HP;
        inFile >> player_MP;
        inFile >> player_armor;
        inFile >> player_weapon;
        int size_of_items = ITEMS.size() - 1;
        inFile >> size_of_items;
        for (int i = 0; i <= size_of_items; i++) {
            inFile >> ITEMS[i];
        }
        //inFile >> ITEMS;
        inFile.close();
        cout << "Game loaded successfully!" << endl;
        cout << name;
        cout << ITEMS[0];
    } 
    else {
        cerr << "Unable to open file for loading." << endl;
    }
}

void saveGame(string& filename, string& name, int& level, int& player_str, int& player_agi, int& player_spd, int& player_luck, int& player_HP, int& player_MP, string& player_armor, string& player_weapon, vector<string>& ITEMS) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << name << endl;
        outFile << level << endl;
        outFile << player_str << endl;
        outFile << player_agi << endl;
        outFile << player_spd << endl;
        outFile << player_luck << endl;
        outFile << player_HP << endl;
        outFile << player_MP << endl;
        outFile << player_armor << endl;
        outFile << player_weapon << endl;
        int size_of_items = ITEMS.size() - 1;
        for (int i = 0; i <= size_of_items; i++) {
            outFile << ITEMS[i] << endl;
        }
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
    bool fight1 = true;
    int NUM_ENEMIES = NUM_ENEMIES;
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
    string player_weapon = "STICK";
    string filename = "save.txt";
    vector<string> ITEMS;
    ITEMS.push_back("DREAM");
    ITEMS.push_back("TEST");
    saveGame(filename, name, level, player_str, player_agi, player_spd, player_luck, player_HP, player_MP, player_armor, player_weapon, ITEMS);
    system("clear");
    cout << "Welcome, " << name << endl;
    cout << "You are a hero in a fantasy setting, and you have lived in the same city for your entire life." << endl;
    cout << "You have been helping feed the animals, tend to the crops, and helping around your land." << endl;
    cout << "In this world, there exists magic, which almost anyone can use, but few can master." << endl;
    cout << "The hero's life is about to change.. as a great calamity approaches the town he lives in..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    string screen = "1";
    draw(screen);
    system("clear");
    cout << "This is the prologue, of which i havent written yet (TODO)" << endl;
    //Other text and things will go here, leading up to the hero leaving toen and going to a temple
    FIGHT(screen, name, fight1, NUM_ENEMIES, level, player_str, player_agi, player_spd, player_luck, player_HP, player_MP, player_armor, player_weapon);

}

void FIGHT(string screen, string name, bool fight1, int NUM_ENEMIES, int level, int player_str, int player_agi, int player_spd, int player_luck, int player_HP, int player_MP, string player_armor, string player_weapon){
    bool fight = true;
    if (bool fight1 = true) {
        NUM_ENEMIES = 1;
        screen = "SLIME";
        draw(screen);
        cout << "Welcome to the fighting screen!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "You have 4 actions you can take in your turn." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "These actions are FIGHT, ITEM, MAGIC, and FLEE." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Fighting will allow you to attack the enemy." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "After choosing the attack option, you'll be prompted to choose which enemy to attack from left to right." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "You will have to use the number that corresponds to which enemy you want to attack." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Item will allow you to use and item from your inventory." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "You will need to type the item number for which item you want to use in order to use it." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Magic will bring up the magic menu." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Different magics have different instructions on how to use them." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Flee will let you flee the fight." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "You cannot flee from this battle, however." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        draw(screen);
        cout << "Each action is case sensitive, so make sure to use caps lock!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
    }
    int damage;
    int target_enemy;
    int enemy_HP;
    int enemy_attack;
    string enemy;
    int enemy_generation = rand()%1;
    for (int i = 0; i <= 100; i++) {
        if (enemy_generation == ENEMY_VALUES[2][i]) {
            enemy = "SLIME";
        }
    }
    if (enemy == "SLIME") {
        enemy_HP = ENEMY_VALUES[0][0];
        enemy_attack = ENEMY_VALUES[1][0];
    }
    vector<int> ENEMY_FIGHT_VALUES;
    for (int i = 0; i <= NUM_ENEMIES; i++) {
        ENEMY_FIGHT_VALUES.push_back(enemy_HP);
    }
    
    while (fight = true) {
        //Player Turn
        cout << "Player turn!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        bool action_taken = false;
        draw(screen);
        cout << name << " HP: " << player_HP << "\t" << name << " MP: " << player_MP << endl;
        cout << "Choose an action: ";
        string action;
        cin >> action;
        while (action != "FIGHT" && action != "ITEM" && action != "MAGIC" && action != "FLEE") {
            cout << "(INVALID ACTION)" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("clear");
            draw(screen);
            cout << name << "HP: " << player_HP << "\t" << name << "MP: " << player_MP << endl;
            cout << "Choose an action: ";
            cin >> action;
        }
        if (action == "FIGHT") {
            cout << "Who is your target? (1-" << NUM_ENEMIES << "): ";
            cin >> target_enemy;
            damage = damage_roll(player_str, player_weapon); 
            if (target_enemy == 1) {
                ENEMY_FIGHT_VALUES[target_enemy - 1] = ENEMY_FIGHT_VALUES[target_enemy - 1] - damage;
            }
            cout << "Dealt " << damage << " damage against slime " << target_enemy << "." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            action_taken = true;
        }
        else if (action == "ITEM") {
            FIGHT_ITEM_MENU();
        }
        else if (action == "MAGIC") {

        }
        else if (action == "FLEE") {
            
        }
        if (ENEMY_FIGHT_VALUES[target_enemy - 1] <= 0) {
            ENEMY_FIGHT_VALUES.erase(ENEMY_FIGHT_VALUES.begin() + target_enemy);
            NUM_ENEMIES--;
            if (NUM_ENEMIES <= 0) {
                fight = false;
                return;
            }
        }
        //Enemy Turn
        system("clear");
        draw(screen);
        cout << "Enemy Turn!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        draw(screen);
        cout << name << " HP: " << player_HP << "\t" << name << " MP: " << player_MP << endl;
        //Check what action the enemy will take
        if (enemy_turn(enemy) == 1) {
            int enemy_damage = enemy_damage_calculation(enemy);
            cout << enemy_damage << " damage." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            player_HP = player_HP - enemy_damage;
        }
    }
}

int enemy_turn(string enemy) {
    int actions;
    if (enemy == "SLIME") {
        actions = 1;
        //Can take attack action
        int will_attack = rand() % 1;
        if (will_attack = 1) {
            cout << "Slime bounces towards you and slams its body into you, dealing ";
            return will_attack;
        }
    }
}

//Enemy damage calculations
int enemy_damage_calculation(string enemy) {
    int damage;
    if (enemy == "SLIME") {
        damage = 1;
    }
    return damage;
}

//Item menu for battles
int FIGHT_ITEM_MENU() {
    system("clear");

}

void draw(string screen) {
    if (screen == "1") {   
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
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return;
    }
    if (screen == "SLIME") {
        system("clear");
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "|                       ________________________                           |" << endl;
        cout << "|                      /                        \\                          |" << endl;
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