// ItemClass.cpp : Demo of Overloading arguments and return values

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

/////////////////////////// THE CLASS  /////////////////////////////////
class Item {
	long ItemID;
	double UnitPrice;
	char *_description;
public:

	/***  Constructor -Desctructor */
	Item(long ID,char *descr );
	Item(long ID,char *descr, double UnitPrice  );
	~Item();
	/***  Overloaded return values */
	long val()  { return ItemID; };
	double val(int flg) { return flg? UnitPrice*100:UnitPrice; };

	/***  Overloaded Mutator */
	void set(char *descr) ;
	void set(double Uprice ) { UnitPrice= Uprice>0 ? Uprice : 0 ; };

	/***  Accessor ***/
	char *description() { return _description ; };
};

///////////  Class Functions /////////////////
Item::Item(long ID,char *descr )
{	ItemID=ID;
	if (descr)
	{	_description= new char[strlen(descr)+1];
		strcpy(_description,descr);
	}
	else
		_description=NULL;
	UnitPrice =0.0;
}
Item::Item(long ID,char *descr, double UnitPrice  )
{	ItemID=ID;
	if (descr)
	{	_description= new char[strlen(descr)+1];
		strcpy(_description,descr);
	}
	else
		_description=NULL;
	this->UnitPrice=UnitPrice;
}
Item::~Item()
{	if (_description)
		delete _description;
}
void Item::set(char *descr) 
{	if (_description)
		delete _description;
	_description= new char[strlen(descr)+1];
	strcpy(_description,descr);
}

//////////////////////////   MAIN PROGRAM   //////////////////////////////////

int main()
{
 double uprice;
	Item a(123, "Lipton Ice Tea", 1.65);
	cout << "Overloaded Return Values etc." << endl;
	cout << "Item key : " << (long) a.val() << endl;
	cout << "Description : " <<  a.description() << endl ;
	cout << "Unit Price : " << (double) a.val(0) << endl;

	cout << "\n\nAfter changing the values" << endl;
	a.set( "Earl Grey Tea");
	a.set( 1.33);
	uprice=a.val(0);
	cout << "Item key : " << (long) a.val() << endl;
	cout << "Description : " <<  a.description() << endl ;
	cout << "Unit Price : " << uprice << endl;
	return 0;
}

