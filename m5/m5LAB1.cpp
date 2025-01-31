#include <iostream>
using namespace std;

/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Julian Palacio
10/21/24
*/

void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_order_food();
void choice_order_pizza();
void choice_order_McDonalds();
void burger();
void choice_no_burger();
void RONALD();


int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You're in front of a spooky old house..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    // call choice 2 here
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_front_door() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_back_door() {
    cout << "TODO: Write something here" << endl;
}

void choice_go_home() {
    cout << "Safe at home, you: " << endl;
    cout << "1. Order food" << endl;
    cout << "2. Go to bed" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        choice_order_food();
    }
    else if (choice == 2) {
        cout << "You go to bed." << endl;
        cout << "*** GAME OVER ***" << endl;
    }
    else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    choice_go_home();  // try again
    }
}

// any new choices go here
void choice_order_food() {
    cout << "You order food." << endl;
    cout << "What will you order?" << endl;
    cout << "1. Pizza" << endl;
    cout << "2. McDonalds" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        choice_order_pizza();
    }
    else if (choice == 2) {
        choice_order_McDonalds();
    }
    else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    choice_order_food();  // try again
    }
}

void choice_order_McDonalds() {
    cout << "After waiting for half an hour, your food finally arrives." << endl;
    cout << "Consume burger???" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        burger();
    }
    else if (choice == 2) {
        choice_no_burger();
    }
}

void choice_order_pizza() {
    cout << "You order pizza." << endl;
}

void burger() {
    cout << "ARE YOU SURE YOU WANT TO CONSUME BURGER???" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "There is no coming back from this..." << endl;
        cout << "Are you ABSOLUTELY SURE you want to consume burger????" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "You consume the burger." << endl;
            cout << "The burger is very juicy." << endl;
            cout << "After taking a bite from the burger, you feel a strange sensation in your stomach." << endl;
            cout << "You feel your mind escape from your body, as you see the burger fall into pieces." << endl;
            cout << "You observe the burger, as it changes form before your very eyes." << endl;
            cout << "The burger has now changed into a bottle of Windex, which you have now consumed." << endl;
            cout << "You feel like you are dying, as the cleaning solution makes its way through your physical mortal body." << endl;
            cout << "You now feel the Windex burn your insides, and you start to feel like the plastic bottle it tearing your stomach." << endl;
            cout << "You feel your impending demise approach, as you start to feel a terrible headache form." << endl;
            cout << "You start to lose thought, and words no longer make sense." << endl;
            cout << "ohk vfliherg sbvjeporghlkenrgp'jhergn wifjkjnrg o ieglbsrkuygefr hergbdfvh invs oieuf goihg." << endl;
            cout << "The end is nigh..." << endl;
            cout << "1. Give in" << endl;
            cout << "2. Give in" << endl;
            cout << "3. Give in" << endl;
            cout << "4. Seek help from Ronald..." << endl;
            cin  >> choice;
            if (choice == 1 || choice == 2 || choice == 3) {
                cout << "ohnvoiphlknewklbjvbaelkfjnm" << endl;
                cout << "***GAME OVER***" << endl;
                cout << "Play again?" << endl;
                cout << "1.Yes" << endl;
                cout << "2.No" << endl;
                cin >> choice;
                if (choice == 1) {
                    main_menu();
                }
                else if (choice == 2) {
                    return;
                }
                else {
                    cout << "That's not a valid choice, please try again." << endl;
                    cin.ignore(); // clear the user input
                    burger();  // try again
                }
            }
            else if (choice == 4) {
                RONALD();
            }
            else {
                cout << "That's not a valid choice, please try again." << endl;
                cin.ignore(); // clear the user input
                burger();  // try again
            }
        }
        else if (choice == 2) {
            cout << "You have escaped doom..." << endl;
            choice_no_burger();
        }
        else {
            cout << "That's not a valid choice, please try again." << endl;
            cin.ignore(); // clear the user input
            burger();  // try again
        }
    }
    else if (choice == 2) {
        cout << "You have made a wise decision" << endl;
        choice_no_burger();

    }
    else {
        cout << "That's not a valid choice, please try again." << endl;
        cin.ignore(); // clear the user input
        burger();  // try again
    }
}

void choice_no_burger() {
        cout << "Now having wasted your food, you must find something else to eat." << endl;
        cout << "Every food place is now closed, somehow, and you must do something else for food." << endl;
        cout << "What do you do for your next meal?" << endl;
        cout << "1. Look for something at home" << endl;
        cout << "2. Forage for food outside" << endl;
        cout << "3. Go to your mother's house" << endl;
        cout << "4. ???" << endl;
}

void RONALD() {
    cout << "RONALD" << endl;
}
