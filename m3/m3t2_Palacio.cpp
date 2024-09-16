#include <iostream>

using namespace std;

//CSC 134
//m3t2-Area of Two Rectangles
//Julian Palacio
//9/16/24

int main() {

    // Set up variables
    double width1, width2, length1, length2;
    double area1, area2;

    // Give output
    cout << "M3T2 - Area of Two Rectangles\n";
    cout << "What is the width of the first rectangle?\n";
    cin >> width1;
    cout << "What is the length for the first rectangle?\n";
    cin >> length1;
    cout << "What is the width for the second rectangle?\n";
    cin >> width2;
    cout << "What is the length for the second rectangle?\n";
    cin >> length2;

    // Calculate area
    area1 = width1 * length1;
    area2 = width2 * length2;

    // Print answer
    cout << "The first area is: " << area1 << ".\n";
    cout << "The second area is: " << area2 << ".\n";

    // Tell which is larger
    if (area1 > area2) {
        cout << "The first rectangle is larger.\n";
    }
    else if (area2 > area1) {
        cout << "The second rectangle is larger.\n";
    }
    else {
        cout << "The rectangles are the same size.\n";
    }

}