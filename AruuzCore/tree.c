#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

int insert(struct binary_tree **root, char *key)
{
	if(*root == NULL)
	{
		*root = (struct binary_tree *)malloc(sizeof(struct binary_tree));
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->value = (char*)malloc(sizeof(key));
		memcpy((*root)->value,key,strlen(key) + 1);
	}
	else if((*root)->right == NULL && (*root)->left == NULL)
	{
		if(strcmp(key,UNKNOWN_SYLLABLE) == 0)
		{
			(*root)->left = (struct binary_tree *)malloc(sizeof(struct binary_tree));
			(*root)->left->value= (char*)malloc(sizeof(SHORT_SYLLABLE));
			memcpy((*root)->left->value,SHORT_SYLLABLE,strlen(SHORT_SYLLABLE) + 1);
			(*root)->left->left = NULL;
			(*root)->left->right = NULL;
			(*root)->right = (struct binary_tree *)malloc(sizeof(struct binary_tree));
		    (*root)->right->value= (char*)malloc(sizeof(LONG_SYLLABLE) + 1);
			memcpy((*root)->right->value,LONG_SYLLABLE,strlen(LONG_SYLLABLE) + 1);
			(*root)->right->left = NULL;
			(*root)->right->right = NULL;
		}
		else
		{
			(*root)->left = (struct binary_tree *)malloc(sizeof(struct binary_tree));
			(*root)->left->value= (char*)malloc(sizeof(key));
			memcpy((*root)->left->value,key,strlen(key) + 1);
			(*root)->left->left = NULL;
			(*root)->left->right = NULL;
		}
	}
	else
	{
		if((*root)->right != NULL)
		{
			insert(&(*root)->right,key);
		}
		if((*root)->left != NULL)
		{
			insert(&(*root)->left,key);
		}
	}
	return 0;
}