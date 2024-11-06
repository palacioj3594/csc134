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

//Function set-up
void seed_generation(int);
void draw(int,int,int,int,int,int,int,int,int,int,int,int,string);


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

    //Set game difficulty
    int ENEMY_MOVES;
    if (difficulty == "EASY") {
        ENEMY_MOVES = 1;
    }
    else if (difficulty == "MEDIUM") {
        ENEMY_MOVES = 2;
    }
    else {
        ENEMY_MOVES = 3;
    }
    cout << "You have selected '" << difficulty << "' mode!" << endl;
    seed_generation(time(0));
    cout << "Starting....." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));// from AI to add a pause


    //Set up movement and other variables
    int HP = 5;
    int E_HP = 10;
    int jump_check = 0;
    int attack_check = 0;
    string facing;
    string command;
    int E_X_LOC, E_Y_LOC;
    int moves = 0;
    facing = "RIGHT";
    bool hit = false;
    X_LOC = 0;
    Y_LOC = 0;
    int dir_x;
    int dir_y;
    E_X_LOC = rand() % 10;
    E_Y_LOC = rand() % 10;

    //Set up points and other items
    int points = 0;
    int C_X = rand() % 10;
    int C_Y = rand() % 10;
    int H_X = rand() % 10;
    int H_Y = rand() % 10;

    //Draw initial screen
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves, C_X, C_Y, points, HP, H_X, H_Y, E_HP, facing); 

    // start game loop
    while (HP > 0 && moves < 500 && E_HP > 0) {

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
    else if (command == "ATTACK") {
        if (attack_check == 0) {
            if (facing == "UP") {
                if (E_Y_LOC == Y_LOC - 1 && E_X_LOC == X_LOC) {
                    hit = true;
                    E_HP--;
                }
            }
            else if (facing == "DOWN") {
                if (E_Y_LOC == Y_LOC + 1 && E_X_LOC == X_LOC) {
                    hit = true;
                    E_HP--;
                }
            }
            else if (facing == "LEFT") {
                if (E_X_LOC == X_LOC - 1 && E_Y_LOC == Y_LOC) {
                    hit = true;
                    E_HP--;
                }
            }
            else if (facing == "RIGHT") {
                if (E_X_LOC == X_LOC + 1 && E_Y_LOC == Y_LOC) {
                    hit = true;
                    E_HP--;
                }
            }
        attack_check = 4;
        }
        else {
            cout << "ATTACKING REQUIRES " << attack_check << " MORE TURNS TO USE!" << endl;
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
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves, C_X, C_Y, points, HP, H_X, H_Y, E_HP, facing);
    
    //Enemy AI
    int X_DIS, Y_DIS;
    if (hit == false) {
        if (E_X_LOC != X_LOC || E_Y_LOC != Y_LOC) {
            for (int i = 0; i < ENEMY_MOVES; i++) {
                if (E_X_LOC < X_LOC) {
                    X_DIS = X_LOC - E_X_LOC;
                }
                else if (E_X_LOC > X_LOC) {
                    X_DIS = E_X_LOC - X_LOC;
                }
                else if (E_X_LOC == X_LOC) {
                    X_DIS = 0;
                }
                if (E_Y_LOC < Y_LOC) {
                    Y_DIS = Y_LOC - E_Y_LOC;
                }
                else if (E_Y_LOC > Y_LOC) {
                    Y_DIS = E_Y_LOC - Y_LOC;
                }
                else if (E_Y_LOC == Y_LOC) {
                    Y_DIS = 0;
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
        }
    }
    else if (hit == true) {
        E_X_LOC = rand() % 10;
        E_Y_LOC = rand() % 10;
        hit = false;
    }

    //Collision
    if (E_X_LOC == X_LOC && E_Y_LOC == Y_LOC) {
        HP--;
        E_X_LOC = rand() % 10;
        E_Y_LOC = rand() % 10;
    }
    if (C_X == X_LOC && C_Y == Y_LOC) {
        C_X = rand() % 10;
        C_Y = rand() % 10;
        points++;
    }
    if (H_X == X_LOC && H_Y == Y_LOC) {
        H_X = rand() % 10;
        H_Y = rand() % 10;
        HP++;
    }
    moves++;
    if (jump_check > 0) {
        jump_check--;
    }
    if (attack_check > 0) {
        attack_check--;
    }
    draw(X_LOC, Y_LOC, E_X_LOC, E_Y_LOC, moves, C_X, C_Y, points, HP, H_X, H_Y, E_HP, facing);
    }// end loop

    cout << string(22, '\n');
    if (HP == 0) {
        cout << "YOU HAVE BEEN KILLED BY THE GHOST!" << endl;
        cout << "------------------------------------" << endl;
        cout << "GAME OVER!" << endl;
        cout << "------------------------------------" << endl;
        cout << "Turns: " << moves << endl;
        cout << "Your final score: " << points << endl;
    }
    else if (moves == 500) {
        cout << "YOU SURVIVED THE NIGHT!" << endl;
        cout << "------------------------------------" << endl;
        cout << "YOU WIN!" << endl;
        cout << "------------------------------------" << endl;
        cout << "Final HP: " << HP << endl;
        cout << "Your final score: " << points << endl;
    }
    else if (E_HP == 0) {
        cout << "YOU HAVE EXORCIZED THE GHOST!" << endl;
        cout << "------------------------------------" << endl;
        cout << "YOU WIN!" << endl;
        cout << "------------------------------------" << endl;
        cout << "Final HP: " << HP << endl;
        cout << "Turns: " << moves << endl; 
        cout << "Your final score: " << points << endl;
    }
    return 0;
}

//For grid building
void draw(int X_LOC, int Y_LOC, int E_X_LOC, int E_Y_LOC, int moves, int C_X, int C_Y, int points, int HP, int H_X, int H_Y, int E_HP, string facing) {
    cout << string(22, '\n');
    cout << "GHOST GAME!" << endl;
    cout << "Collect as many gems as you can to get points!" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "w,a,s,d  - MOVE" << endl;
    cout << "JUMP - Moves forward 2 spaces (3 move cooldown)" << endl;
    cout << "ATTACK - ATTACK THE GHOST (3 move cooldown)" << endl;
    cout << "^(The ghost must be 1 tile away from you to attack)" << endl;
    cout << "^(You must be facing in the same direction as the ghost)" << endl;
    cout << "PRESS ENTER AFTER EVERY MOVE TO CONFIRM INPUT." << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;
    cout << "Turn: " << moves << endl;
    cout << "HP: " << HP << endl;
    cout << "Ghost HP: " << E_HP << endl;
    cout << "Facing: " << facing << endl;
    cout << "Points: " << points << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (X_LOC == j && Y_LOC == i) {
                cout << "👨 ";
            }
            else if (E_X_LOC == j && E_Y_LOC == i){
                cout << "👻 ";
            }
            else if (C_X == j && C_Y == i) {
                cout << "💎 ";
            }
            else if (H_X == j && H_Y == i) {
                cout << "❤️  ";
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