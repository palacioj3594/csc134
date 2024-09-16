// CSC 134
// M1HW1 - Movie Talk
// Julian Palacio
// 8/28/24
#include <iostream>
using namespace std;

int main() {

    // Set the variables
    string movie_name = "The Bee Movie";
    int year_made = 2007;
    //string money_made = "$293.51 million USD";
    double money_made = 293.51;

    // Start speaking
    cout << movie_name << " was a movie made in " << year_made << " and made $" << money_made << " million USD when it released.\n";

    // Add some quotes
    cout << "Here is a quote from the movie: \n";
    cout << "\t \"According to all known laws of aviation, there is no way a bee should be able to fly.\n";
    cout << "\t \tIts wings are too small to get its fat little body off the ground.\n";
    cout << "\t \tThe bee, of course, flies anyway\n \t \tbecause bees don't care what humans think is impossible.\"\n";

}