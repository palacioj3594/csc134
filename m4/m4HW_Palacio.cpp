//CSC 134
//m4HW - Gold
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Welcome to the multiplication table for 1-12!" << endl;
    cout << "Please enter a number 1-12: ";
    cin >> number;
    while (number < 1 || number > 12) {
        cout << "Please enter a number between 1 and 12!" << endl;
        cout << "Please enter a number: ";
        cin >> number;
    }

    cout << "NUMBER \t\t TIMES \t\t TOTAL" << endl;
    cout << "_________________________________________________" << endl;
    for(int i = 0; i <= 11; i++) {
        cout << number << "\t\t" << i + 1 << "\t\t" << number * (i+1) << endl;
    }
}