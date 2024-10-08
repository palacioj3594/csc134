//CSC 134
//Halloween++
//Julian Palacio
//10/2/24

#include <iostream>
#include "stdio.h" // for getchar()
#include <random>

using namespace std;

void seed_generation(int);
void move(int,int,int,int);

int main() {

    string difficulty;
    int X_LOC;
    int Y_LOC;
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
    X_LOC = rand() % 10;
    Y_LOC = rand() % 10;
    starting_point = X_LOC * 10 + Y_LOC;
    seed_generation(starting_point);
    cout << "Starting....." << endl;


    //Set up movement
    char direction;
    char dir;
    int E_X_LOC, E_Y_LOC;
    int moves = 0;
    X_LOC = 0;
    Y_LOC = 0;
    E_X_LOC = rand() % 10;
    E_Y_LOC = rand() % 10;
    int dir_x;
    int dir_y;
    
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC); 
    // start game loop
    while (true){
    //Player movement
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
    //Enemy movement
    int rand_dir = rand() % 4;
    const int WEST = 0; // x--
    const int EAST = 1; // x++
    const int NORTH = 2;// y--
    const int SOUTH = 3;// y++
    if (rand_dir == WEST) {
        E_X_LOC--;
        if (E_X_LOC < 0) {
            E_X_LOC = 0;
        }
    }
    else if (rand_dir == EAST){
        E_X_LOC++;
        if (E_X_LOC > 9) {
            E_X_LOC = 9;
        }
    }
    else if (rand_dir == NORTH) {
        E_Y_LOC--;
        if (E_Y_LOC < 0) {
            E_Y_LOC = 0;
        }
    }
    else if (rand_dir == SOUTH) {
        E_Y_LOC++;
        if (E_Y_LOC > 9) {
            E_Y_LOC = 9;
        }
    }
    else {
        // can't get here
        cout << "moved but not WENS!!!";
    }
    move(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC);
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


void seed_generation(int starting_point) {
    int seed;
    seed = starting_point;
    srand(seed); // Got this from AI
    
}