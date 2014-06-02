/*************************
    The StudentList Class  
*************************/

static char *
maj_name[] = {
	"Acc.&Fin.", "CIS", "Information Technology", "Marketing", "Management", "Undecided"
};

enum Major {
	AFN , CIS , ITC, MKT , MNG, UND
};

struct Student{
	char *name;
	long ID;
	Major m;
	struct Student *next;
};

class StudentList
{
private:

Student *s_root ;
Student *CurrentEntry;

public:
	StudentList();			// This is the declaration of a constructor
	StudentList(char []);	// and here's one overloaded constructor
	StudentList(char name[], long ID,	Major m)  ;	// and here's another one
	Student * add_student( char name[]);
	Student * add_student( char name[], long ID,Major m);
	Student * get_student( char name[]);
	Student * current();
	int remove( char name[]);
	void reset();
	void next();

};


/***********************************************
  TO DO : Use default arguments and eliminate  
		the default Constructor             
		and add_student( char name[])  
************************************************/


////////// THE CONSTRUCTOR ///////////////

StudentList::StudentList()    // Create an empty list
{
	s_root = NULL;
	CurrentEntry=NULL;
}

StudentList::StudentList(char name[])  
{
	s_root = NULL;
	CurrentEntry=NULL;
	CurrentEntry=add_student(name);
}

StudentList::StudentList(char name[], long ID,	Major m)  
{
	s_root = NULL;
	CurrentEntry=NULL;
	CurrentEntry=add_student(name, ID, m);
}


Student *
StudentList::add_student( char name[])
{
	add_student(name,0,UND);
	return s_root;  //Always return the address of the root of the list

}

Student *
StudentList::add_student( char name[], long ID,	Major m)
{
  Student *sp, *sptmp, *s_prev=NULL;
	if (s_root)		// If not the  first Student in the list
	{	for (sp=s_root ; sp!=NULL ; sp=sp->next )
		{	if (strcmp(name,sp->name)<0)
				break;
			s_prev=sp;
		}
		sptmp=new Student;
		sptmp->next=sp;
		sp=sptmp;
		if (s_prev)
			s_prev->next=sptmp;
		else
			sp=s_root=sptmp;
	}
	else
	{	sp= s_root=new Student;
		sp->next=NULL;
	}
	// Initialize the fields in s
	sp->ID = ID;
	sp->m= m;
	sp->name= new char[strlen(name)+1];   // We had  forgotten the +1  !!!!
	strcpy(sp->name,name);
//	sp->next=NULL;

	return s_root;  //Always return the address of the root of the list
}

Student *
StudentList::get_student( char name[])
{Student *s ;
	
	for (s=s_root ; s ;s=s->next)
		if (strcmp(s->name,name)==0)
			break;
	return s;
}
int
StudentList::remove( char name[])
{Student *s , *s_prev;
	
	for (s=s_root, s_prev=NULL; s ;s=s->next)
	{
		if (strcmp(s->name,name)==0)
			break;
		s_prev=s;
	}
	if (s)
	{	if (s_prev)
			s_prev->next=s->next;
		else
			s_root=s->next;
		delete [] s->name;
		delete s;
	}
	return 0;
}
void
StudentList::reset()
{
	CurrentEntry=s_root;
}

void
StudentList::next()
{
	if (CurrentEntry)
		CurrentEntry=CurrentEntry->next;
}

Student *
StudentList::current()
{
	return CurrentEntry;
}

