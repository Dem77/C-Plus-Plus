/********************************************************
* scoperes.cpp :  1st step into OOP                     *
* Using the scope resolution operator with structures   *
********************************************************/
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Student {
public:
	long ID;
	char name[40];
	short credits;
	Student();
	Student(int, char *);
	~Student();
	struct Courses {
		char ID[8] ;
		short credits;
		void display_info();
	} crs[8];
	int add_new_course(char course[],int credits);
	void display_info();
} ;

Student::Student()
{
 int i;
	ID=0;
	name[0]='\0';
	credits=0;
	for (i=0 ; i<8 ; i++)
	{	crs[i].ID[0]='\0';
		crs[i].credits=0;
	}
}

Student::~Student() 
{
	cout << "Bye";
}

Student::Student(int _id, char * s)
{
	int i;
	ID=_id;
	strcpy(name,s);
	credits = 0;
	for (i=0 ; i<8 ; i++)
	{	crs[i].ID[0]='\0';
		crs[i].credits=0;
	}
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
{	cout << "Student Name: " << name << "  Credits: " << credits << endl ;
}
void Student::Courses::display_info ()
{	cout << "\tCourse ID: " << ID << "  Credits: " << credits << endl ;
}

Student a;
Student b(1234, "Alex Tripidis");

void main()
{  int i;
   string w;
	cout << "Lesson1:  Encapsulation - Scope Resolution"<< endl ;

	cout <<"Enter Student name : " ; getline(cin,w);	
	strcpy(a.name,w.c_str());
	if (a.name[0]=='\0')  // if the name is empty
		return;
	printf("Enter # of credits : " );	cin >>a.credits ; // scanf("%d", &a.credits );

	a.add_new_course("CS 3397",2);
	a.add_new_course("CS 2410",3);
	a.display_info();
	for (i=0 ; i<8 && a.crs[i].ID[0]; i++ )
		a.crs[i].display_info();
	b.display_info();
}
