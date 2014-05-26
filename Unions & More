// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

typedef union WRK {
	char s[4];
	short k;
	long x;
} AnyNumber;


int main()
{
	int i;
	AnyNumber x;

	printf("Enter a number: ");
	scanf_s("%d", &x.x);
	
	if (x.s[0] == x.x)
		printf("LITTLE ENDIANS\n");
	else
		printf("BIG ENDIANS");
	
	for (int i = 0; i < 4; i++) {
		printf("%02.2x ", x.s[i]);
	}

	return 0;
}

