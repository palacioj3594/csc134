//CSC 134
//Halloween++
//Julian Palacio
//10/2/24

#include <iostream>
#include "stdio.h" // for getchar()
#include <random>

using namespace std;

void seed_generation(int);
void move(int,int,int,int,int,int);

int main() {

    string difficulty;
    int starting_point;
    cout << "Starting..." << endl;

    //Set difficulty and set-up
    cout << "Select your difficulty level (EASY, MEDIUM, HARD): ";
    cin >> difficulty;
    while (difficulty != "EASY" && difficulty != "MEDIUM" && difficulty != "HARD"){

        cout << "Please enter EASY, MEDIUM, or HARD!" << endl;
        cout << "Select your difficulty (EASY, MEDIUM, HARD): ";
        cin >> difficulty;

    }

    //Set variables
    int MAX_ENEMIES;
    if (difficulty == "EASY") {

        MAX_ENEMIES = 3;

    }
    else if (difficulty == "MEDIUM") {

        MAX_ENEMIES = 5;

    }
    else {

        MAX_ENEMIES = 7;

    }
    cout << "You have selected '" << difficulty << "' mode!" << endl;
    cout << "Please select a place to start at on the grid (1-100)... " << endl;
    cin >> starting_point;
    cout << "You have selected point " << starting_point << "." << endl;
    cout << "Starting....." << endl;
    seed_generation(starting_point);

    //Set up movement
    char direction;
    char dir;
    int X_LOC;
    int Y_LOC;
    int E_X_LOC, E_Y_LOC;
    int moves = 0;
    int spawned;
    X_LOC = 0;
    Y_LOC = 0;
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, MAX_ENEMIES, spawned); 
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
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, MAX_ENEMIES, spawned);
    }// end loop
}

//For grid building
void move(int X_LOC, int Y_LOC, int E_X_LOC, int E_Y_LOC, int MAX_ENEMIES, int spawned) {
    int place = 1;
    int size = 100;
    
    if (spawned != 1) {
        for (int k = 0; k < MAX_ENEMIES; k++) {

        } 
    }
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
                place++;
            }
        }
        cout << endl;
    }
}


void seed_generation(int starting_point) {
    int seed;
    seed = starting_point;
    std::mt19937 gen(seed); // Got this from AI
    
}