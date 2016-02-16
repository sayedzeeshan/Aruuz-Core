// AruuzCore.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"globals.h"
#include"test_bed.h"



int main(int argc, char** argv)
{
	char *locale;
	printf("The thread locale is now set to %s.\n",setlocale( LC_ALL, "URDU" ));
	code_test();
	tree_test();
	while(1)
	{

	}
	return 0;
}

