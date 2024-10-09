#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// CSC 134
// M4LAB2 - Craps
// Julian Palacio
// 10/9/24

int roll() {

    //get a random number
    int die = (rand() % 6) + 1;
    return die;
}

//if we define a function after main, we need to declare it first
bool play_round();


int main() {

    // Set up variables
    int seed;
    bool is_winner;


    cout << "Welcome to the table!" << endl;

    // Set up the game
    seed = time(0);
    srand (seed); //set a random seed

    //play a round of craps
    is_winner = play_round();
    if (is_winner) {
        cout << "You won!" << endl;
    }
    else {
        cout << "You lost." << endl;
    }
    return 0;
}

bool play_round() {
    bool is_winner = false; //house wins by default
    int point;
    // Roll 2 random numbers
    int die1 = roll();
    int die2 = roll();

    // Give the total
    int total = die1 + die2;
    cout << "You rolled: " << die1 << " + " << die2 << " = " << total << "." << endl;
    cout << "Your total is " << total << "." << endl;

    // Did they win or lose
    if (total == 2 || total == 3 || total == 12){
        is_winner = false;
    }
    else if (total == 7){
        is_winner = true;
    }
    else {
        // TODO
        cout << "You point is: " << total << endl;
        point = total;
        //roll again
        //keep rolling until you get point (win) or 7 (lose)
        do{
            total = roll() + roll();
            cout << "Come on lucky number " << point << "!" << endl;
            cout << "Rolled: " << total << endl;
            if (total == 7){
                is_winner = false;
            }
            if (total == point) {
                is_winner = true;
            }
         } while (total != 7 && total != point);

    }

    return is_winner;

}
