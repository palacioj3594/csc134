#include <iostream>

using namespace std;

int main(){
    double mealPrice = 5.99;
    double taxRate = 0.08;
    double taxAmount, total;

    //calculate
    taxAmount = mealPrice * taxRate;
    total = taxAmount + mealPrice;

    //print output
    cout << "Thank you for dining with us!" << endl;
    cout << "Your meal total is " << mealPrice << endl;
    cout << "Your tax is $" << taxAmount << endl;
    cout << "Your total is $" << total << endl;
    cout << "Please come again!"<< endl;

}