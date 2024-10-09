#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// CSC 134
// M3T3 - Craps
// Julian Palacio
// 9/25/24

int roll() {

    //get a random number
    int die = (rand() % 6) + 1;
    return die;
}

int main() {

    // Set up variables
    int die1, die2, total;
    int seed;


    cout << "Welcome to the table!" << endl;

    // Set up the game
    seed = time(0);
    srand (seed); //set a random seed

    // Roll 2 random numbers
    die1 = roll();
    die2 = roll();

    // Give the total
    total = die1 + die2;
    cout << "You rolled: " << die1 << " + " << die2 << " = " << total << "." << endl;
    cout << "Your total is " << total << "." << endl;

    // Did they win or lose
    if (total == 2 || total == 3 || total == 12){

        cout << "You lose! D:";

    }
    else if (total == 7 || total == 11){

        cout << "You win! :D";

    }
    else {
        // TODO
        cout << "You got points." << endl;
        cout << "We do this later." << endl;
    }

    return 0;

}
