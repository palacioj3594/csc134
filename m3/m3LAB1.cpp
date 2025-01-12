//CSC 134
//m3LAB1
//Julian Palacio
//1/12/25

#include <iostream>
using namespace std;

// beginning of the main() method
int main() {

  // declare the variable we need
  int choice; 

  // ask the question
  cout << "You friend tells you to drink some milk." << endl;
  cout << "Do you choose to drink it (1), not to drink it (2), or throw it at them(3)?" << endl;
  cout << "Type 1, 2, or 3: "; 
  cin >> choice;

  // using if, make a decision based on the user's choice

  if (1 == choice) {
  	cout << "You chose to drink the milk." << endl;
    cout << "You forgot you wer lactose intolerant and rush to the bathroom, making your friend feel bad about themselves." << endl;
    cout << "Your friend turns into a milk monster and destroys the town." << endl;
  }
  else if (2 == choice) {
  	cout << "You didn't drink the milk and now your friend is sad, which turns him into a milk monster." << endl;
    cout << "The milk monster proceeds to destroy the town." << endl;
  }
  else if (3 == choice) {
    cout << "You threw the milk at your friend." << endl;
    cout << "He suddenly transforms into a milk monster and destroys the town." << endl;
  }
  else {
  	cout << "I'm sorry, that is not a valid choice, your friend gets mad and turns into a milk monster and destroys the town." << endl;
  }

  // finish up
  cout << "Thanks for playing!" << endl; // this runs no matter what they choose
  return 0; // exit without error

} // end of the main() method