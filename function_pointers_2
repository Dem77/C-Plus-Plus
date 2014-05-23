/********************************************
*  Function pointers                        *
*  A struct array with a function pointer   *
********************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;

///// PROTOTYPE of local function /////
char * delcommas(char *,const char *);
char * disp(char *,const char *);


struct {
	char *fname;					// the name of a function
	char * (*fptr)(char *,const char *);	// a function pointer
} cmd[] = {
	"COPY" , strcpy,
	"CONCAT" , strcat,
	"DELC" , delcommas,
	"DISPLAY", disp,
	NULL, NULL
};

char dest[80], source[80];
char buff[128];


void getcs(char *s)
{ string w;
	cin.getline(s,100);
//	strcpy(s,w.c_str());
}

int main()
{ int i;
  char *p;
  string w;
	while (1)
	{	system("notepad K:\\UNDERGRADUATE\\cpp.txt");
		ifstream in("K:\\UNDERGRADUATE\\cpp.txt");
		while (getline(in,w))	// while there are more lines to read from the file
		{
			p=strtok((char *)w.c_str()  ," ") ;
			strcpy(buff,p);
			if ((p=strtok(NULL," "))==NULL)
				return 1;
			strcpy(dest,p);
			if ((p=strtok(NULL," "))!=NULL)
				strcpy(source,p);
			else
				source[0]='\0';

			for (i=0 ; cmd[i].fname ; ++i)
				if (strcmp(cmd[i].fname,buff)==0)
				{	(*cmd[i].fptr)(dest,source);
					cout << "result = " << dest << endl ;
					break;
				}
			if (cmd[i].fname==NULL)
			cout << "Function does not exist !\n" ;
			cout << "\n\n";
		}
		cout << "\n--------------------- Continue ? (y-n) ";
			if (toupper(getch())!='Y')
				break;
	}
	return 0;
}


char * delcommas(char *dest,const char *srce)
{char *p, *q;
	for (p=(char *)srce, q=dest ; *p ; p++)
		if (*p!=',')
			*q++=*p;
	*q='\0';
	return dest;
}

char * disp(char *s1,const char *s2)
{	printf("%s %s\n",s1,s2);
	return NULL;
}
