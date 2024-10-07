//CSC 134
//Halloween++
//Julian Palacio
//

#include <iostream>

using namespace std;


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

}