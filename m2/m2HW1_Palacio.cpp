//CSC 134
//M2HW1 - Gold
//Julian Palacio
//1/12/25

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main() {

    //Part 1
    cout << "Part 1 - Banking" << endl;
    cout << "_______________________________" << endl;

    //Set up variables
    string name;
    double startingBalance,depositAmount,withdrawlAmount;
    int accountNumber = rand()%1000000;

    //Ask questions
    cout << setprecision(2) << fixed;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your starting balance?" << endl;
    cin >> startingBalance;
    cout << "what is the amount you are withdrawling?" << endl;
    cin >> withdrawlAmount;
    cout << "What is your deposit amount?" << endl;
    cin >> depositAmount;
    cout << "___________________________________" << endl;

    //calculate
    double finalBalance = startingBalance - (withdrawlAmount + depositAmount);

    //output info and such
    cout << "Hello, " << name << endl;
    cout << "Your account number is #" << accountNumber << endl;
    cout << "Your final balance is $" << finalBalance << endl;

    cout << "______________________________________" << endl;
    cout << "Part 2 - Box Company" << endl;
    cout << "______________________________________" << endl;

    // Set up variables
    int volume, length, width, height;
    double cost, customer_price;
    const double cost_per_cu_ft = 0.3;
    const double customer_price_per_cu_ft = 0.5;
    double profit;

    // Start the program
    cout << "Let's get the crate's dimensions!\n";

    // Get the measurements
    cout << "What is the length of the box (in feet)?\n";
    cin >> length;
    cout << "What is the width of each box?\n";
    cin >> width;
    cout << "What is the height of the box?\n";
    cin >> height;

    // Do calculations
    volume = length * width * height;
    cost = volume * cost_per_cu_ft;
    customer_price = volume * customer_price_per_cu_ft;

    // Display the charges
    cout << setprecision(2) << fixed;
    cout << "The cost of making the box is going to be $" << cost << " and the total you will be charged is $" << customer_price << ".\n";
    profit = customer_price - cost;
    cout << "We made $" << profit << " in this transaction.\n";

    cout << "______________________________________" << endl;
    cout << "Part 3 - Pizza Party" << endl;
    cout << "______________________________________" << endl;

    //Set up variables
    int numPizza, numSlices, numPeople;

    //Ask questions
    cout << "How many people are going to the party?" << endl;
    cin >> numPeople;
    cout << "How many pizzas are you ordering?" << endl;
    cin >> numPizza;
    cout << "How many slices are in each pizza?" << endl;
    cin >> numSlices;
    
    //Calculate
    int amountEaten = numPeople * 3;
    int totalSlices = numPizza * numSlices;
    int leftover = totalSlices - amountEaten;

    //Output
    cout << "Every guest gets 3 slices of pizza, so there will be " << leftover << " slices of pizza left over." << endl;

    cout << "______________________________________" << endl;
    cout << "Part 4 - Chant" << endl;
    cout << "______________________________________" << endl;

    //Set up variables
    string school,team;

    //Ask questions
    cout << "What is the name of your school?" << endl;
    cin >> school;
    cout << "What is the name of your school's team?" << endl;
    cin >> team;

    //Output
    for (int i = 0; i <= 2; i++) {
        cout << "Let's go " << school << "!" << endl;
    }
    cout << "Let's go " << team << "!" << endl;

}