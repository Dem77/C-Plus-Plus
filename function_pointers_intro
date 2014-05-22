

#include <iostream>
using namespace std;

void (*f)(char *);  // A function pointer pointing to 
					// a void function with one argument(=char *)

void say_something(char *text)
{
	cout << text << endl;
}


int main()
{
	f=say_something;   // f points to say_something
	(*f)("Hello world"); // call the function that  f points
	return 0;
}
