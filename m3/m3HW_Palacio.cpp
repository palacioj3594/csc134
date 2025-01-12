//CSC 134
//m3HW - Gold
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

void question1();
void question2();
void question3();
void question4();

int main() {
    int question;
    cout << "What question do you want (1-4)?" << endl;
    cin >> question;
    while (question != 1 && question != 2 && question != 3 && question != 4) {
        cout << "Invalid input!" << endl;
        cout << "What question do you want (1-4)?" << endl;
        cin >> question;
    }
    if (question == 1) {
        question1();
    }
    else if (question == 2) {
        question2();
    }
    else if (question == 3) {
        question3();
    }
    else if (question == 4) {
        question4();
    }
}

void question1() {

    // set up variables
    string answer;
    cout << "Chat Bot\n" << endl;
    cout << "Hello, I'm a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no." << endl;
    cin >> answer;
    if (answer == "yes") {
        cout << "That's great! I'm sure we'll get along." << endl;
    }
    else if (answer == "no") {
        cout << "Well, maybe you'll learn to like me later." << endl;
    }
    else {
        cout << "if you're not sure... that's OK." << endl;
    }
    return;
}

void question2() {

    //Set up variables
    double mealPrice;
    cout << "What is the price of your meal?" << endl;
    cin >> mealPrice;
    string place;
    cout << "Is your meal dine-in or takeout?" << endl;
    cin >> place;
    while (place != "dine-in" && place != "takeout") {
        cout << "Invalid input!" << endl;
        cout << "Is your meal dine-in or takeout?" << endl;
    }
    double tip;
    if (place == "dine-in") {
        tip = 0.15;
    }
    else {
        tip = 0;
    }
    double taxRate = 0.08;
    double taxAmount, total, tipAmount, totalAfter;

    //calculate
    taxAmount = mealPrice * taxRate;
    total = taxAmount + mealPrice;
    tipAmount = total * tip;
    totalAfter = total + tipAmount;

    //print output
    cout << "Thank you for dining with us!" << endl;
    cout << "Your meal total is " << mealPrice << endl;
    cout << "Your tax is $" << taxAmount << endl;
    cout << "Your total is $" << total << endl;
    if (place == "dine-in") {
        cout << "Your tip is $" << tipAmount << endl;
        cout << "Your total after tip is %" << totalAfter << endl;
    }
    cout << "Please come again!"<< endl;
    return;
}

void question3() {

    //Set up variables
    int choice; 

    // ask the question
    cout << "You friend tells you to drink some milk." << endl;
    cout << "Do you choose to drink it (1) or not to drink it (2)?" << endl;
    cout << "Type 1 or 2" << endl; 
    cin >> choice;

    //Story
    if (1 == choice) {
  	    cout << "You chose to drink the milk." << endl;
        cout << "You forgot you wer lactose intolerant and rush to the bathroom." << endl;
        cout << "Your friend turns into a milk monster without your notice and destroys the town." << endl;
        cout << "Game Over!" << endl;
    }
    else if (2 == choice) {
  	    cout << "You didn't drink the milk and now your friend turns into a milk monster, saying you foiled their plans to destroy the town." << endl;
        cout << "Do you choose to fight them (1), or run away(2)?" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "You successfully saved the town!" << endl;
            cout << "You Win!" << endl;
        }
        else if (choice == 2) {
            cout << "You run away and the monster destroys the town." << endl;
            cout << "You are now regarded as a criminal for not stopping them and are put in prison." << endl;
            cout << "Game Over!" << endl;
        }
        else {
            cout << "You are frozen with fear and the milk monster eats you and destroys the town." << endl;
            cout << "Game Over!" << endl;
        }
    }
    else {
  	    cout << "I'm sorry, that is not a valid choice, your friend gets mad and turns into a milk monster and destroys the town." << endl;
    }

  // finish up
  cout << "Thanks for playing!" << endl; // this runs no matter what they choose
  return;
}

void question4() {

    //Set up variables
    int num1, num2;
    num1 = rand() % 10;
    num2 = rand() % 10;
    int total = num1 + num2;
    int answer;

    // Gice out put
    cout << "What is " << num1 << " + " << num2 << "?" << endl;
    cin >> answer;
    if (answer == total) {
        cout << "Great Job!" << endl;
    }
    else {
        cout << "Wrong answer!" << endl;
    }

    return;
}