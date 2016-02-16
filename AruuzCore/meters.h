#include<wchar.h>
#include "globals.h"
#ifndef _meters_h
#define _meters_h

typedef struct
{
	int id;
	bool usage;
	char **patterns;
	char *original_pattern;
	wchar_t *name;
	int length;
	int numPatterns;
	int type;
}meter;

typedef struct
{
	char *name;
	char *pattern;
	int length;
}foot;

typedef struct
{
	meter *meters;
	int length;
}meters_list;

meter *meter_new(int id, bool usage, char **patterns, char *orig_pattern, wchar_t *name, int *length, int numPatterns, int type);
void meter_delete(meter *met);
meters_list meters_list_new(void);


extern meters_list METERS;



#endif