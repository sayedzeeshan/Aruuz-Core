#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<string.h>
#include"globals.h"
#include"meters.h"
#include"tree.h"
#include"test_bed.h"

void code_test()
{
	meters_list lst = meters_list_new();
	printf("Short: %s\n",SHORT_SYLLABLE);
	printf("Long: %s\n",LONG_SYLLABLE);
	printf("End-Short: %s\n",WORD_END_SHORT);
	printf("Unknown: %s\n",UNKNOWN_SYLLABLE);
	wprintf(L": %s\n",lst.meters[0].name);
}
void tree_test(void)
{
	int i;
    struct 	binary_tree *code_tree = NULL;
	char pattern[] = "x===-==x-=x";
	char *val;
	insert(&code_tree,"root");
	for(i = 0; i < strlen(pattern); i++)
	{
		val = (char*)malloc(2*sizeof(char));
		memcpy(val,&pattern[i],1);
		val[1] = '\0';
		insert(&code_tree,val);
	}
}