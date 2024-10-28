//CSC 134
// M5T1 - Basic Functions
//Julian Palacio
// 10/28/24

#include <iostream>
using namespace std;

//Function prototypes (short version)
void say_hello();
int give_the_answer();
int double_an_int(int number);

//Main
int main() {
    cout << "Hello from main!" << endl;
    say_hello();
    cout << "The magic number is: ";
    int number = give_the_answer();
    cout << number << endl;
    int twotimes = double_an_int(number);
    cout << "Double that is: " << twotimes << endl;
    return 0;
}

//Function definitions
void say_hello() {
    cout << "Hello from say_hello!" << endl;
}

int give_the_answer() {
    float answer = 42;
    return answer;
}

int double_an_int(int number) {
    int twotimes = number * 2;
    return twotimes;
}