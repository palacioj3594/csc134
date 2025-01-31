//CSC 134
//M6LAB1 - Buckshot Roulette
//Julian Palacio
//11/13/24

#include <iostream>
#include <vector>
#include <random>

using namespace std;

//Constants
const int NUM_ROUNDS = 3;
const int RED = 1; //live
const int BLACK = 0; //blank


int main() {
    int chamber[] = {RED, BLACK, RED};
    for (int round: chamber) {
       if (round == RED) {
            cout << "RED ";
        }
        if (round == BLACK) {
            cout << "BLACK ";
        }
    }
    cout << endl;
}