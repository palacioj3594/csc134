//CSC 134
//M6LAB1 - Buckshot Roulette
//Julian Palacio
//11/13/24

#include <iostream>
#include <vector>
#include <random>

using namespace std;

//Functions Here
string shuffle(int,int);

//Constants
const int NUM_ROUNDS = 3;
const int RED = 1; //live
const int BLACK = 0; //blank


int main() {

    vector<string> order;
    int number_of_shells = rand() % 10;
    int current_shell_number = number_of_shells;
    int number_of_raspberrys = rand() % number_of_shells;
    int number_of_blanks = number_of_shells - number_of_raspberrys;
    cout << number_of_shells;
    cout << number_of_raspberrys;
    cout << number_of_blanks;
    while (number_of_shells != 0) {
        order.push_back(shuffle(number_of_raspberrys, number_of_blanks));
        number_of_shells--;
    }
    for (int i = 0; i < number_of_shells; i++) {
        cout << order[i] << endl;
    }

//    int chamber[] = {RED, BLACK, RED};
//    for (int round: chamber) {
//        if (round == RED) {
//            cout << "RED ";
//        }
//        if (round == BLACK) {
//            cout << "BLACK ";
//        }
//    }
//    cout << endl;
}

string shuffle(int number_of_raspberrys, int number_of_blanks) {
    int shell = (rand() % 2) + 1;
    if (shell == 1) {
        if (number_of_raspberrys > 0) {
            number_of_raspberrys--;
            return "RASPBERRY";
        }
        else {
            number_of_blanks--;
            return "BLANK";
        }
    }
    else {
        return "TEST FAILED";
    }
}