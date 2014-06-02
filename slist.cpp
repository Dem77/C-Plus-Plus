#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "slistcls.h"

/**************************
        Main Program
**************************/

StudentList slist("Dimou Popi");

void
main()
{
 Student *sptr ;

	printf ("Student List\n\n");

	slist.add_student( "Vergos Paul");

	slist.add_student( "Zorbas Alexis");

	slist.add_student( "Newman Alfred",5,ITC);
	slist.add_student( "Gerrard Steve");
	slist.add_student( "Wood Chris");
	slist.add_student( "Smith Bessy");
	slist.add_student( "Cole Andy");

	if (sptr=slist.get_student("Dimou Popi"))
	{	sptr->ID=1;
		sptr->m =MKT;
	}

	if (sptr=slist.get_student("Vergos Paul"))
	{	sptr->ID=2;
		sptr->m =CIS;
	}

	if (sptr=slist.get_student("Zorbas Alexis"))
	{	sptr->ID=3;
		sptr->m =MKT;
	}
	
/// Display contents
	for (slist.reset() ;  sptr= slist.current() ; slist.next()  )
	{	
		printf("%4d  %-24.24s %-20.20s\n", sptr->ID, sptr->name, maj_name[sptr->m]);
	}
	slist.remove("Vergos Paul");
	printf("\nAfter deleting Vergos\n");
	for (slist.reset() ;  sptr= slist.current() ; slist.next()  )
	{	
		printf("%4d  %-24.24s %-20.20s\n", sptr->ID, sptr->name, maj_name[sptr->m]);
	}
}
