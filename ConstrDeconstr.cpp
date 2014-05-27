/*****************************
* ConstrDestr.cpp            *
* CONSTRUCTORS - DESTRUCTORS *
*****************************/
#include <iostream>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 

class Text {
	char *s;
public:
	void assign(char *);
	int input();
	void display();
	Text();		//  the default constructor  !!!  TO DO: An overloaded constructor
	~Text();
};

Text::Text()
{
	s=NULL;
}
Text::~Text()
{
	if (s)
		delete s;
}
void Text::display()
{
	if (s)
		cout << s << endl;
	else
		cout << "[empty]" << endl;
}
void Text::assign(char *s)
{
	if (this->s)
		delete this->s;
	this->s = new char[strlen(s)+1];
	strcpy(this->s,s);
}


//////////////////////////////////////////////////////////////////////////

int main()
{
	Text t;
	cout<<"Demo of Constructors - Destructors!\n\n" ;
	cout << "1st pass\n";
	t.display();
	t.assign("Hello");
	cout << "\n2nd pass\n";
	t.display();
	return 0;
}

