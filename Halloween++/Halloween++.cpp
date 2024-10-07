//CSC 134
//Halloween++
//Julian Palacio
//

#include <iostream>
#include "stdio.h" 
// for getchar()
using namespace std;

void move(int,int);

int main() {

    string difficulty;
    cout << "Starting..." << endl;

    //Set difficulty
    cout << "Select your difficulty level (EASY, MEDIUM, HARD): ";
    cin >> difficulty;
    while (difficulty != "EASY" && difficulty != "MEDIUM" && difficulty != "HARD"){

        cout << "Please enter EASY, MEDIUM, or HARD!" << endl;
        cout << "Select your difficulty (EASY, MEDIUM, HARD): ";
        cin >> difficulty;

    }

    //Set variables
    int e_num_mod;
    int e_spawn_time_mod;
    if (difficulty == "EASY") {

        e_num_mod = 3;
        e_spawn_time_mod = 0;

    }
    else if (difficulty == "MEDIUM") {

        e_num_mod = 5;
        e_spawn_time_mod = 1;

    }
    else {

        e_num_mod = 7;
        e_spawn_time_mod = 2;

    }

    int MAX_ENEMIES = 5 + e_num_mod;

    int respawn_time = 1 + e_spawn_time_mod;

    //cout << MAX_ENEMIES;
    //cout << respawn_time;
    char direction;
    char dir;
    int X_LOC;
    int Y_LOC;
    X_LOC = 0;
    Y_LOC = 0; 
    move(X_LOC, Y_LOC); 
    // start game loop
    while (true){
    direction  = getchar();
    cin.get(dir);
    if (dir == 'd') {
        X_LOC++;
    }
    else if (dir == 'w') {
        Y_LOC--;
    }
    else if (dir == 'a') {
        X_LOC--;
    }
    else if (dir =='s') {
        Y_LOC++;
    }
    move(X_LOC, Y_LOC);
    }// end loop
}

void move(int X_LOC, int Y_LOC) {
    //int X_LOC, Y_LOC;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (X_LOC == j && Y_LOC == i) {
                cout << "👽 ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}