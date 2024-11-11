//CSC 134
//M6T1 - Arrays
//Julian Palacio
//11/11/24

#include <iostream>

using namespace std;

//Global Variables
const int NUM_DAYS = 5;

int main() {
    //Set up variables
    //For each day Monday-Friday
    // - ask how many cars
    // - add them to the total
    //When done, report the total and average
    double total = 0;
    int todays_count = 0;

    for (int day = 1; day <= NUM_DAYS; day++) {
        cout << "PLease enter the count for day " << day << " of " << NUM_DAYS << "." << endl;
        cin >> todays_count;
        total += todays_count;
    }
    double average = total/NUM_DAYS;

    //Display data
    cout << "For all " << NUM_DAYS << " days: " << endl;
    cout << "Total cars: " << total << endl;
    cout << "Average: " << average << endl;
}