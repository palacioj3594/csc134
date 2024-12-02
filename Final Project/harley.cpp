#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct Tile {
    bool traversable = true;
    int event = 0;
} Tile;

typedef struct Enemy {
    int attack;
    int hp;
} Enemy;

Enemy create_enemy(int enemy_type);

const int SLIME = 1;
const int SKELETON = 2;

int main() {


    const int WIDTH = 10;
    const int HEIGHT = 10;
    Tile world[WIDTH][HEIGHT];
    /*
    world[5][5] = (Tile) {
        .traversable = true,
        .event = 0
    };
    */
   /*
   Tile current_tile = world[5][5];
   current_tile.traversable = true;
   current_tile.event = 0;

   cout << world[5][5].traversable << endl;
   */
  /*
  world[5][5].traversable = false;
    if (world[5][5].traversable) {
        cout << "Yeah" << endl;
    }
    */
   world[5][5].traversable = false;
   for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (world[y][x].traversable) {
                cout << "#";
            } else {
                cout << " ";
            }
            
        }
        cout << '\n';
   }

   vector<Enemy> enemyPool;
   enemyPool.push_back(create_enemy(SLIME));
   system("clear");
}

Enemy create_enemy(int enemy_type) {
    Enemy enemy;
    switch (enemy_type) {
        case SLIME:
            enemy.hp = 1;
            enemy.attack = 1;
            break;
        case SKELETON:
            enemy.hp = 10;
            enemy.attack = 5;
            break;
    }
    return enemy;
}