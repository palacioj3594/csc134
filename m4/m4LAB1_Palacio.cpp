//CSC 134
//m4LAB1
//Julian Palacio
//10/7/24

#include <iostream>
using namespace std;

int main() {

    cout << "M4LAB1" << endl;

    string emoji = "👽";
    //cout << "👽" << endl;
    //Print sideways (row)

    for (int i = 0; i < 9; i++) {

        cout << emoji << " ";

    }
    cout << endl;

    //print down (column)
    for (int j = 0; j < 9; j++) {

        cout << emoji << endl;

    }

    //Put them together
    cout << "FULL VERSION:" << endl;
    const int ROWS = 4;
    const int COLS = 6;
    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            cout << emoji << " ";

        }
        cout << endl;

    }

}