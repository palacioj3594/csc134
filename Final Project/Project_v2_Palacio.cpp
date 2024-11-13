#include <iostream>
#include <fstream>

using namespace std;


typedef struct Armor {
    int defence;
} Armor; 

typedef struct Weapon {
    int damage;
    int quality;
    string name;
} Weapon;

typedef struct Player {
    int level;
/*    int strength;
    int agility;
    int speed;
    int luck;
    int hp;
    int mp; */
//    string name;
//    Armor armor;
//    Weapon weapon;
} Player;

typedef struct Slime {
    int hp = 100;
} Slime;

//Functions
void save(const Player& player, const string&);


int main()  {
    Player player;
    player.level = 1;
//    player.weapon.name;
    string filename = "data.txt";
    save(player, filename);
}

void save(const Player& player, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << player.level << endl;
    }
    outFile.close();
}