//CSC 134
//Halloween++
//Julian Palacio
//

#include <iostream>
#include "stdio.h" // for getchar()
#include <random>

using namespace std;

void seed_generation(int,int);
void move(int,int,int,int);
void spawn(int, int);

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
    int spawn_check;
    int e_num_mod;
    int e_spawn_time_mod;
    if (difficulty == "EASY") {

        e_num_mod = 3;
        e_spawn_time_mod = 10;

    }
    else if (difficulty == "MEDIUM") {

        e_num_mod = 5;
        e_spawn_time_mod = 5;

    }
    else {

        e_num_mod = 7;
        e_spawn_time_mod = 0;

    }

    int MAX_ENEMIES = 5 + e_num_mod;

    int respawn_time = 5 + e_spawn_time_mod;

    //Set up movement
    char direction;
    char dir;
    int X_LOC;
    int Y_LOC;
    int E_X_LOC, E_Y_LOC;
    X_LOC = 0;
    Y_LOC = 0;
    spawn_check = 0;
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC); 
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

    if (X_LOC > 9) {
        X_LOC = 9;
    }
    else if (X_LOC < 0) {
        X_LOC = 0;
    }
    if (Y_LOC > 9) {
        Y_LOC = 9;
    }
    else if (Y_LOC < 0) {
        Y_LOC = 0;
    }
    
    //Enemy spawn check
    if (respawn_time == 0) {
        if (spawn_check == 0) {
            seed_generation(X_LOC, Y_LOC);
            spawn_check++;
        }
        spawn(X_LOC, Y_LOC);
        respawn_time = e_spawn_time_mod + 5;
    }
    else {
        respawn_time--;
        move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC);
    }
    }// end loop
}

//For grid building
void move(int X_LOC, int Y_LOC, int E_X_LOC, int E_Y_LOC) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (X_LOC == j && Y_LOC == i) {
                cout << "O ";
            }
            else if (E_X_LOC == j && E_Y_LOC == i){
                cout << "X ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

//For enemy spawning
void spawn(int X_LOC, int Y_LOC) {
    int E_X_LOC, E_Y_LOC;
    E_X_LOC = rand() % 9;
    if (E_X_LOC == X_LOC) {
        while (E_X_LOC == X_LOC) {
            E_X_LOC = rand() % 9;
        }
    }
    E_Y_LOC = rand() % 9;
    if (E_Y_LOC == Y_LOC) {
        while (E_Y_LOC == Y_LOC) {
            E_Y_LOC = rand() % 9;
        }
    }
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC);
}

void seed_generation(int X_LOC, int Y_LOC) {
    int seed;
    seed = X_LOC * 10 + Y_LOC;
    std::mt19937 gen(seed); // Got this from AI
    
}