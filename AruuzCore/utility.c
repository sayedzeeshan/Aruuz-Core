#include<string.h>
#include"utility.h"

char *remove_char(char *src, char key)
{
	int idxToDel = -1; 
	char *subStr;
	while(strchr(src,key) != NULL)
	{
		subStr = strchr(src,key);
		idxToDel = subStr - src; 
		memmove(&src[idxToDel], &src[idxToDel + 1], strlen(src) - idxToDel);
	}
	return src;
}
char *replace_char(char *src, char to_replace, char replace_with)
{
	int idxToReplace = -1; 
	char *subStr;
	while(strchr(src,to_replace) != NULL)
	{
		subStr = strchr(src,to_replace);
		idxToReplace = subStr - src; 
		src[idxToReplace] = replace_with;
	}
	return src;
}