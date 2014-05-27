// Lesson0.cpp 
//

#include <iostream>
#include <string>

using namespace std;

#include "demo.h"

string myname;
int main()
{
	cout << "Enter your name : ";
	cin >> myname;
	cout << "Hello " + myname << endl;
	Triangle a;
	cout << "Enter x for the triangle: " << endl;
	cin >> a.x;
	cout << "Enter the y for the triangle: " << endl;
	cin >> a.y;
	cout << "x=" << a.x << " ,  y=" << a.y << endl; 
	cout << "The area of triangle a is " << a.area() << endl ;

	Rectangular b;
	cout << "Enter x for the rectangular: " << endl;
	cin >> b.x;
	cout << "Enter the y for the rectangular: " << endl;
	cin >> b.y;
	cout << "x=" << b.x << " ,  y=" << b.y << endl;
	cout << "The area of rectangular b is " << b.area() << endl ;

	return 0;
}

