/********************************************************
* scoperes.cpp :  1st step into OOP                     *
* Using the scope resolution operator with structures   *
********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "var.h"

struct Courses {
	char ID[8] ;
	short credits;
	void display_info();
};
class Student {
	char *_name;
public:
	long ID;
	short credits;
	Student();
	Student(int, char *);
	Student(int,char *,short );
	~Student();
	struct Courses crs[8];
	int add_new_course(char course[],int credits);
	void display_info();
	void name(char *s); // MUTATOR
	char *name();       // ACCESSOR
	char *info();
	long info(char);
} ; 

// Default constructor
Student::Student ()
{
 int i;
	ID=0;
	_name=NULL;
	credits=0;
	for (i=0 ; i<8 ; i++)
	{	crs[i].ID[0]='\0';
		crs[i].credits=0;
	}
}
// Overloaded constructor
Student::Student(int _id,char *s)
{ int i;
	ID=_id;
	_name=new char[strlen(s)+1];
	strcpy(_name,s);
	credits=0;
	for (i=0 ; i<8 ; i++)
	{	crs[i].ID[0]='\0';
		crs[i].credits=0;
	}
}
Student::Student(int _id,char *s,short cr)
{ int i;
	ID=_id;
	_name=new char[strlen(s)+1];
	strcpy(_name,s);
	credits=cr;
	for (i=0 ; i<8 ; i++)
	{	crs[i].ID[0]='\0';
		crs[i].credits=0;
	}
}
Student::~Student()
{
	if (_name)
	{	delete _name;
		_name=NULL;
	}
}

char * Student::name()
{ return _name;
}
void Student::name(char *s)
{
	if (_name)
		delete _name;
	_name=new char[strlen(s)+1];
	strcpy(_name,s);
}

void demo()
{  Student x;
	cout << "----\n";
}


int Student::add_new_course(char course[],int credits)
{
 struct Courses *pcrs;
	if (crs[7].ID[0])
		return -1;
	/// Here is a nice demo of pointer usage
	/// start pointing with pcrs to crs and while the pointed ID if Not empty
	/// move to the next crs element (until you find an unitialized ID)
	for (pcrs=crs ; pcrs->ID[0] ; ++pcrs)
		;
	strcpy(pcrs->ID ,course);
	pcrs->credits =credits;
	return 0;
}

void Student::display_info ()
{	cout << "Student Name: " << _name << "  Credits: " << credits << endl ;

}
void Courses::display_info ()
{	cout << "\tCourse ID: " << ID << "  Credits: " << credits << endl ;
}

char *Student::info()
{
	return _name;
}
long Student::info(char c)
{
	return ID;
}

int main()
{  int i=0;
   string w;

 Student a;
 Student b(1234,"Alfred Newman") ;
	cout << "Lesson1:  Encapsulation - Scope Resolution"<< endl ;
	cout <<"Enter Student name : " ; getline(cin,w);	
	a.name((char *) w.c_str());
 
//	if (a._name[0]=='\0')  // if the name is empty
//		return;
	printf("Enter # of credits : " );	cin >>a.credits ; // scanf("%d", &a.credits );

	a.add_new_course("CS 3397",2);
	a.add_new_course("CS 2410",3);
	a.display_info();
	cout << a.info() << " ID=" << a.info('x');
	for (i=0 ; i<8 && a.crs[i].ID[0]; i++ )
		a.crs[i].display_info();
	b.display_info();

	return 0;
}
