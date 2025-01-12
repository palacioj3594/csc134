//CSC 134
//m3LAB2
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

int main() {

    //set up variables
    int grade;
    cout << "What is your grade?" << endl;
    cin >> grade;
    if (grade >= 90) {
        cout << "Grade: A" << endl;
    }
    else if (grade >= 80) {
        cout << "Grade: B" << endl;
    }
    else if (grade >= 70) {
        cout << "Grade: C" << endl;
    }
    else if (grade >= 60) {
        cout << "Grade: D" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }
}