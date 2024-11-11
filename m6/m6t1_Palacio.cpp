//CSC 134
//M6T1 - Arrays
//Julian Palacio
//11/11/24

#include <iostream>

using namespace std;

//Global Variables
const int NUM_DAYS = 5;

//Prototypes
void partONE();
void partTWO();

int main() {
    string part;
    cout << "What part do you want (1 or 2)?" << endl;
    cin >> part;
    while (part != "1" && part != "2") {
        cout << "Please choose part 1 or 2!" << endl;
        cin >> part;
    }
    if (part == "1") {
        partONE();
    }
    if (part  == "2") {
        partTWO();
    }
}
void partONE() {
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

void partTWO() {
    //Set up variables
    //For each day Monday-Friday
    // - ask how many cars
    // - add them to the total
    //When done, report the total and average
    int cars[NUM_DAYS];
    double total = 0;
    int todays_count = 0;

    for (int day = 1; day <= NUM_DAYS; day++) {
        cout << "PLease enter the count for day " << day << " of " << NUM_DAYS << "." << endl;
        cin >> todays_count;
        cars[day] = todays_count;
        total += todays_count;
    }
    double average = total/NUM_DAYS;

    //Display data
    cout << "For all " << NUM_DAYS << " days: " << endl;
    //Print each day's count
    for (int day = 1; day <= NUM_DAYS; day++) {
        cout << cars[day];
        if (day != NUM_DAYS) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Total cars: " << total << endl;
    cout << "Average: " << average << endl;
}