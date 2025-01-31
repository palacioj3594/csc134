#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string data = "123 45.67 Hello";
    istringstream iss(data);

    int integer;
    float floating;
    string word;

    iss >> integer >> floating >> word;

    std::cout << "Integer: " << integer << std::endl;
    std::cout << "Float: " << floating << std::endl;
    std::cout << "String: " << word << std::endl;

    return 0;
}