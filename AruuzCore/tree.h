#include"globals.h"
#ifndef _tree_h
#define _tree_h

struct binary_tree
{
	char *value;
	struct binary_tree *left;
	struct binary_tree *right;
};
int insert(struct binary_tree **root, char *key);
#endif