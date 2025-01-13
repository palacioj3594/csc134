//CSC 134
//m4T1
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

int main() {
    int number = 0;

    while (number < 5) {
        cout << "Hello!" << endl;
        number ++;
    }
    cout << "That's all!" << endl;

    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 10;

    int num = MIN_NUMBER;

    cout << "Number Number Squared" << endl;
    cout << "___________________________" << endl;

    while (num <= MAX_NUMBER) {
        cout << num << "\t\t" << (num * num) << endl;
        num ++;
    }
    return 0;
}