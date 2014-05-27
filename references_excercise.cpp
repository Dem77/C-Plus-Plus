// ref_exercise.cpp 

/////////////////////// REFERENCES //////////////////////////
#include <iostream>
using namespace std;
double varA, varB;

double meanval(double& a, double& b)
{	return (a+b)/2;
}
	
int main()
{
	cout << "Demo of the meanval( )\n";
	cout << "value of varA ? "; cin >> varA; // %lf specifies double precision
	cout << "value of varB ? "; cin >> varB; //    floating point number

	cout << "\nMean value of varA , varB = " << meanval(varA,varB) << endl;

	return 0;
}

///  TO DO
///  Rewrite the function and  modify main() as required
///   so as to accept two reference arguments instead of two pointers

