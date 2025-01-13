//CSC 134
//m4T2
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

int main() {

    const int MIN_PLAYERS = 7;
    const int MAX_PLAYERS = 12;

    int num;
    cout << "How many players do you wish for each team?: ";
    cin >> num;
    while (num < MIN_PLAYERS || num > MAX_PLAYERS) {
        cout << "lease enter a value between " << MIN_PLAYERS << " and " << MAX_PLAYERS << "!" << endl;
        cout << "How many players do you wish for each team?: ";
        cin >> num;
    }

    int amount;
    cout << "How many players are available?: ";
    cin >> amount;
    while (amount <= 0) {
        cout << "Please enter 0 or greater!" << endl;
        cout << "How many players are available?: ";
        cin >> amount;
    }
}