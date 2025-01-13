//Csc134
//M5 Homework1
// Julian Palacio
//11/4/24

#include <iostream>
#include <iomanip>

using namespace std;

// Functions here
void do_choice(int);
void average_rainfall();
void volume();
void roman_numeral();
void geometry_calculator();
void distance_traveled();
void exit();

int main() {
    cout << "Which question would you like to see?" << endl;
    cout << "1 - Average Rainfall" << endl;
    cout << "2 - Volume" << endl;
    cout << "3 - Roman Numerals" << endl;
    cout << "4 - Geometry Calculator" << endl;
    cout << "5 - Distance Traveled" << endl;
    cout << "6 -  EXIT" << endl;
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 6) {
        while (choice <1 || choice > 6) {
            cout << "Please enter a number between 1 and 6!" << endl;
            cin >> choice;
        }
    }
    do_choice(choice);
    return 0;
}
void do_choice(int choice) {
    if (choice == 1) {
        average_rainfall();
    }
    else if (choice == 2) {
        volume();
    }
    else if (choice == 3) {
        roman_numeral();
    }
    else if (choice == 4) {
        geometry_calculator();
    }
    else if (choice == 5) {
        distance_traveled();
    }
    else if (choice == 6) {
        exit();
    }
}
void average_rainfall() {
    string month1, month2, month3;
    double rainfall1, rainfall2, rainfall3;
    cout << "elcome to the average rainfall calculator!" << endl;
    cout << "Please enter month # 1: ";
    cin >> month1;
    cout << "Please enter the rainfall for the month of " << month1 << ": ";
    cin >> rainfall1;
    cout << "Please enter month # 2: ";
    cin >> month2;
    cout << "Please enter the rainfall for the month of " << month2 << ": ";
    cin >> rainfall2;
    cout << "Please enter month # 3: ";
    cin >> month3;
    cout << "Please enter the rainfall for the month of " << month3 << ": ";
    cin >> rainfall3;
    double total = rainfall1 + rainfall2 + rainfall3;
    double average_rain = total/3;
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average_rain << endl;
    cout << "Thank you for using the average rainfall calculator" << endl;
    return;
    }
void volume(){


    double length, width, height, volume;    cout << "Welcome to the box volume calculator!" << endl;
    cout << "Please enter the length of the box: ";
    cin >> length;
    cout << "Please enter the width of the box: ";
    cin >> width;
    cout << "Please enter the height of the box: ";
    cin >> height;
    volume = length * width * height;
}
void roman_numeral() {
    
    int number;
    cout << "Please enter a number 1-10: ";
    cin >> number;
    while (number < 1 || number > 10) {
        cout << "Invalid number!" << endl;
        cout << "Please enter a number between 1 and 10: ";
        cin >> number;
    }
    if (number == 1) {
        cout << "The roman numeral version of 1 is I" << endl;
    }
    else if (number == 2) {
        cout << "The roman numeral version of 2 is II" << endl;
    }
    else if (number == 3) {
        cout << "The roman numeral version of 3 is III" << endl;
    }
    else if (number == 4) {
        cout << "The roman numeral version of 4 is IV" << endl;
    }
    else if (number ==5) {
        cout << "The roman numeral version of 5 is V" << endl;
    }
    else if (number == 6) {
        cout << "The roman numeral version of 6 is VI" << endl;
    }    
    else if (number == 7) {
        cout << "The roman numeral version of 7 is VII" << endl;
    }
    else if (number == 8) {
        cout << "The roman numeral version of 8 is VIII" << endl;
    }
    else if (number == 9) {
        cout << "The roman numeral version of 9 is IX" << endl;
    }
    else if (number == 10) {
        cout << "The roman numeral version of 10 is X" << endl;
    }
}
void geometry_calculator(){
    cout << "Welcome to Geometry Calculator!" << endl;
    cout << "What would you like to calculate?" << endl;
    cout << "1. Calculate the area of a circle" << endl;
    cout << "2. Calculat e the area of a rectangle" << endl;
    cout << "3. Calculate the area of a triangle" << endl;
    cout << "4. Quit" << endl;
    cout <<  "Enter your choice (1-4): ";
    int cal_area;
    cin >> cal_area;
    if (cal_area < 1 || cal_area > 4) {
        while (cal_area <1 || cal_area > 4) {
            cout << "Please enter a number between 1 and 4!" << endl;
            cin >> cal_area;
        }
     } else if(cal_area==1) {
        cout << "What is the radius of the circle" << endl;
        int radius;
        cin >> radius;
        int c_area=3.14159*(radius*radius);
        cout << "The area of the circle is " << c_area << endl;
     } else if(cal_area==2){
        cout << "What is the length of the rectangle?" << endl;
        int length;
        cin >> length;
        cout << "What is the width of the rectangle?" << endl;
        int width;
        cin >> width;
        int r_area=length*width;
        cout << "The area of the rectangle is " << r_area << endl;
     } else if(cal_area==3) {
        cout << "What is the base of the triangle?" << endl;
        int base;
        cin >> base;
        cout << "What is the height of the triangle?" << endl;
        int height;
        cin >> height;
        double area = (base /2) * height;
        cout << "The area of the triangle is " << area << endl;
     } else{
        cout << "Goodbye" << endl;
        return;
     }
    
    
    
}
void distance_traveled(){
    
    int speed, time;
    cout << "What is the speed of the vehicle in mph?: ";
    cin >> speed;
    while (speed < 0) {
        cout << "Please enter a positive number!" << endl;
        cout << "What is the speed of the car in mph?: ";
        cin >> speed;
    }
    cout << "How many hours has the vehicle been traveling for?: ";
    cin >> time;
    while (time < 1) {
        cout << "Please enter a time greater than 1!: ";
        cin >> time;
    }
    cout << "HOUR\tDISTANCE TRAVELED" << endl;
    cout << "_______________________________________" << endl;
    for (int i = 0; i < time ;i ++) {
        cout << i + 1 << "\t\t" << time * (i+1) * speed << endl;
    }
}
void exit(){
    cout << "Thank you for visiting this assignment." << endl;
    cout << "Visit again soon." << endl;
    cout << "Goodbye!" << endl;
    return;
}