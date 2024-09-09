#include <iostream>
#include <iomanip>
using namespace std;
// CSC 134
// m2LAB2 - Case Study
// Julian Palacio
// 9/9/24

int main(){

    // Set up variables
    int volume, length, width, height;
    double cost, customer_price;
    const double cost_per_cu_ft = 0.23;
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


}