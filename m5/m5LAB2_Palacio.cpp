//CSC 134
// M5LAB2
// Julian Palacio
//11/4/24

#include <iostream>
using namespace std;


// Declare (Write the prototypes for)
double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);
// the getLength,
// getWidth, getArea, and displayData
// functions here.

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
    double length;    // The rectangle's length
    double  width;     // The rectangle's width
    double  area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}
double getLength(){
    double length;
    cout << "What is the length of rectangle?" << endl;
    cin >> length;
    return length;
}
double getWidth(){
    double width;
    cout << "What is the width of the rectangle?" << endl;
    cin >> width;
    return width;
}
double getArea(double length, double width){
    //double length;
    //double width;
    double area = length * width;
    return area;
}
void displayData(double length, double width, double area){
    cout << "The length of the rectangle is " << length << endl;
    cout << "The width of the rectangle is " << width << endl;
    cout << "The area of the rectangle is " << length << " x " << width << " which equals " << area << endl;
}