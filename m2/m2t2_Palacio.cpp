#include <iostream>
#include <iomanip>
using namespace std;

int main() { 

  // Set up variables
  string name;
  int num_apples;
  double price_per_apple;

  // Get user input
  cout << "What is your name?\n";
  cin >> name;
  cout << "How many apples are for sale?" << endl;
  cin >> num_apples;
  cout << "What is the price of the apples?\n";
  cin >> price_per_apple;
  cout << "-------------------------\n";
  
  // Say hello
  cout << "Welcome to the "; 
  cout << name << " orchard!\n";
  cout << "We have " << num_apples << "apples for sale." << endl;
  cout << "Each apple costs $" << price_per_apple << ".\n";
  
  // Ask some questions
  cout << "How many apples would you like to buy?\n";
  cin >> num_apples;
  
  // Give the answers
  cout << "You are buying  " << num_apples << " apples.\n";

  // Calculate the total
  double total = num_apples * price_per_apple;
  cout << fixed << setprecision(2);
  cout << "Your total is $" << total << ".\n";
  
}