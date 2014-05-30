class var {
	union {
		long x;
		double d;
		char *value;
	} u;
	char type;
public:
	var(long);
	var(double);
	var(const char *);
	~var();
	void display();
};
var::var(long x)
{   type='L';
	u.x = x;
}
var::var(double x)
{   type='D';
	u.d = x;
}

var::var(const char *s)
{   type='S';
	u.value= new char[strlen(s)+1];
	strcpy(u.value,s);
}
var::~var()
{    if (type=='S')
		delete u.value;
}
void var::display()
{
	switch(type)
	{ case 'L':
		cout << u.x;
		break;
	  case 'D':
		cout << u.d;
		break;
	  case 'S':
		cout << u.value;
	}
}

