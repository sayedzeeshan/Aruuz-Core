#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"
#include"error_handling.h"
#include"meters_def.h"
#include"utility.h"
#include"meters.h"

meter *meter_new(int id, bool usage, char **patterns, char *orig_pattern, wchar_t *name, int *length, int numPatterns, int type)
{
	meter *retVal;
	if(length <= 0)
	{
		err_code = E_ZERO_LEN_INIT;
		err_source = S_MET_NEW;
		return NULL;
	}
	retVal = (meter *)malloc(sizeof(meter));
	retVal->id = id;
	retVal->length = length;
	retVal->name = name;
	retVal->numPatterns = numPatterns;
	retVal->patterns = patterns;
	retVal->usage = usage;
	retVal->type = type;
	retVal->original_pattern = orig_pattern;

	return retVal;
}

void meter_delete(meter *met)
{
	int i;
	if(met != NULL)
	{
		for(i = 0; i < met->numPatterns; i++)
		free(met->patterns[i]);
		free(met->name);
		free(met);
	}
}

meters_list meters_list_new()
{
	int i;
	meter met_lst[TOTAL_METERS];
	meters_list lst;
	char *pattern_t,*pattern_o;

	for(i = 0; i < NUM_METERS; i++)
	{
		met_lst[i].id = id[i]; 
		met_lst[i].name = meterNames[i];
		met_lst[i].type = REGULAR_METER;
		met_lst[i].usage = usage[i];
		met_lst[i].original_pattern = meters[i];
		if(strstr(meters[i],"+") != NULL)
		{
			met_lst[i].numPatterns = 4;
			met_lst[i].patterns = (char **)malloc(4*sizeof(char));
			pattern_o = (char *)malloc((strlen(meters[i]))*sizeof(char));
			pattern_o = strcpy(pattern_o,meters[i]);
			pattern_o = remove_char(pattern_o,'/');
			pattern_t = (char *)malloc((strlen(meters[i]) + 1)*sizeof(char));
			pattern_t = strcpy(pattern_t,pattern_o);
			pattern_t = remove_char(pattern_t,'+');
			met_lst[i].patterns[0] = pattern_t;
			met_lst[i].length = (int)strlen(pattern_t);
			pattern_t = (char *)malloc((strlen(meters[i]) + 1)*sizeof(char));
			pattern_t = strcpy(pattern_t,pattern_o);
			pattern_t = remove_char(pattern_t,'+');
			pattern_t =  strcat(pattern_t,"~");
			met_lst[i].patterns[1] = pattern_t; 
			pattern_t = (char *)malloc((strlen(meters[i]) + 1)*sizeof(char));
			pattern_t = strcpy(pattern_t,pattern_o);
			pattern_t = replace_char(pattern_t,'+','~');
			met_lst[i].patterns[2] = pattern_t; 
			pattern_t = (char *)malloc((strlen(meters[i]) + 1)*sizeof(char));
			pattern_t = strcpy(pattern_t,pattern_o);
			pattern_t = replace_char(pattern_t,'+','~');
			pattern_t =  strcat(pattern_t,"~");
			met_lst[i].patterns[3] = pattern_t; 
		}
		else
		{
			met_lst[i].numPatterns = 2;
			met_lst[i].patterns = (char **)malloc(2*sizeof(char));
			pattern_o = (char *)malloc((strlen(meters[i]))*sizeof(char));
			pattern_o = strcpy(pattern_o,meters[i]);
			pattern_o = remove_char(pattern_o,'/');
			met_lst[i].patterns[0] = pattern_o;
			met_lst[i].length = (int)strlen(pattern_o);
			pattern_t = (char *)malloc((strlen(meters[i]) + 1)*sizeof(char));
			pattern_t = strcpy(pattern_t,pattern_o);
			pattern_t =  strcat(pattern_t,"~");
			met_lst[i].patterns[1] = pattern_t; 
		}
	}
	lst.meters =  met_lst;
	lst.length = NUM_METERS;
}