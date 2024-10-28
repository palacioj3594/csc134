//CSC 134
//Halloween++
//Julian Palacio
//10/2/24

#include <iostream>
#include <stdio.h> // for getchar()
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void seed_generation(int);
void draw(int,int,int,int,int);


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
    seed_generation(time(0));
    cout << "Starting....." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));// from AI to add a pause


    //Set up movement
    int jump_check = 0;
    string facing;
    string command;
    int E_X_LOC, E_Y_LOC;
    int moves = 0;
    facing = "RIGHT";
    X_LOC = 0;
    Y_LOC = 0;
    int dir_x;
    int dir_y;
    //Setting up enemies
    int e_x_locs [MAX_ENEMIES];
    int e_y_locs [MAX_ENEMIES];
    for (int x = 0; x < MAX_ENEMIES; x++){
        E_X_LOC = rand() % 10;
        e_x_locs[x] = E_X_LOC;
        E_Y_LOC = rand() % 10;
        e_y_locs[x] = E_Y_LOC;
    }

    
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves); 
    // start game loop
    while (true) {

    //Player control
    cin >> command;
    if (command == "d") {
        X_LOC++;
        facing = "RIGHT";
    }
    else if (command == "w") {
        Y_LOC--;
        facing = "UP";
    }
    else if (command == "a") {
        X_LOC--;
        facing = "LEFT";
    }
    else if (command == "s") {
        Y_LOC++;
        facing = "DOWN";
    }
    else if (command == "JUMP") {
        if (jump_check == 0) {
            if (facing == "UP") {
                Y_LOC--;
                Y_LOC--;
            }
            else if (facing == "DOWN") {
                Y_LOC++;
                Y_LOC++;
            }
            else if (facing == "LEFT") {
                X_LOC--;
                X_LOC--;
            }
            else if (facing == "RIGHT") {
                X_LOC++;
                X_LOC++;
            }
            jump_check = 4;
        }
        else {
            cout << "JUMPING REQUIRES " << jump_check << " MORE TURNS TO USE!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    else {
        cout << "INVALID COMMAND, GHOST GETS A PENALTY TURN" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));// from AI to add a pause
    }
    

    // Keeps player in the screen
    if (X_LOC > 9) {
        X_LOC = 0;
    }
    else if (X_LOC < 0) {
        X_LOC = 9;
    }
    if (Y_LOC > 9) {
        Y_LOC = 0;
    }
    else if (Y_LOC < 0) {
        Y_LOC = 9;
    }
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves);
    cout << "Enemy Move..." << endl;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //Enemy movement
    int rand_dir = rand() % 4;
    const int WEST = 0; // x--
    const int EAST = 1; // x++
    const int NORTH = 2;// y--
    const int SOUTH = 3;// y++
    
    int X_DIS, Y_DIS;
    if (E_X_LOC != X_LOC || E_Y_LOC != Y_LOC) {
        if (E_X_LOC < X_LOC) {
            X_DIS = X_LOC - E_X_LOC;
        }
        else if (E_X_LOC > X_LOC) {
            X_DIS = E_X_LOC - X_LOC;
        }
        if (E_Y_LOC < Y_LOC) {
            Y_DIS = Y_LOC - E_Y_LOC;
        }
        else if (E_Y_LOC > Y_LOC) {
            Y_DIS = E_Y_LOC - Y_LOC;
        }
        if (X_DIS > Y_DIS) {
            if (E_X_LOC < X_LOC) {
                E_X_LOC++;
            }
            else if (E_X_LOC > X_LOC) {
                E_X_LOC--;
            }
        }
        else if (X_DIS < Y_DIS) {
            if (E_Y_LOC < Y_LOC) {
                E_Y_LOC++;
            }
            else if (E_Y_LOC > Y_LOC) {
                E_Y_LOC--;
            }
        }
        else if (X_DIS == Y_DIS) {
            if (E_X_LOC < X_LOC) {
                E_X_LOC++;
            }
            else if (E_X_LOC > X_LOC) {
                E_X_LOC--;
            }
        }
    }
    //Collision
    if (E_X_LOC == X_LOC && E_Y_LOC == Y_LOC) {
        E_X_LOC = rand() % 10;
        E_Y_LOC = rand() % 10;
    }
    /*if (rand_dir == WEST) {
        E_X_LOC--;
        if (E_X_LOC < 0) {
            E_X_LOC = 9;
        }
    }
    else if (rand_dir == EAST){
        E_X_LOC++;
        if (E_X_LOC > 9) {
            E_X_LOC = 0;
        }
    }
    else if (rand_dir == NORTH) {
        E_Y_LOC--;
        if (E_Y_LOC < 0) {
            E_Y_LOC = 9;
        }
    }
    else if (rand_dir == SOUTH) {
        E_Y_LOC++;
        if (E_Y_LOC > 9) {
            E_Y_LOC = 0;
        }
    }
    else {
        // can't get here
        cout << "moved but not WENS!!!";
    }*/
    moves++;
    if (jump_check > 0) {
        jump_check--;
    }
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves);
    }// end loop
}

//For grid building
void draw(int X_LOC, int Y_LOC, int E_X_LOC, int E_Y_LOC, int moves) {
    cout << string(22, '\n');
    cout << "I'M BAD AT NAMES!" << endl;
    cout << "What do you want to do?" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "w,a,s,d  - MOVE" << endl;
    cout << "JUMP - Moves forward 2 spaces (3 move cooldown)" << endl;
    cout << "PRESS ENTER AFTER EVERY MOVE TO CONFIRM INPUT." << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    cout << "Turn: " << moves << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (X_LOC == j && Y_LOC == i) {
                cout << "👨 ";
            }
            else if (E_X_LOC == j && E_Y_LOC == i){
                cout << "👻 ";
            }
            else {
                cout << "🌲 ";
            }
        }
        cout << endl;
    }
}


void seed_generation(int time) {
    int seed;
    seed = time;
    srand(seed); // Got this from AI
}