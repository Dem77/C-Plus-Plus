// references.cpp 
#include <iostream>
using namespace std;

void square_val(int n)
{	n*=n;
}
void square_ptr(int* n)
{	*n *= *n;
}
void square_ref(int& n)
{	n*=n;
}

int x= 3;
void main()
{
	cout << "Pointers and References!\n";

	cout << "x=" << x<< endl;
	square_val(x);
	cout << "After square_val x=" << x << endl;
	square_ptr(&x);
	cout << "After square_ptr x=" << x << endl;
	square_ref(x);
	cout << "After square_ref x=" << x << endl;
}

