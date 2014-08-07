#ifndef TreeStack_H
#define TreeStack_H

#include <stdlib.h>
#include "biTreeNode.h"
#include "treeStackNode.h"

typedef struct TreeStack_ {
	TreeStackNode *head;
	TreeStackNode *top;
} TreeStack;

TreeStack *makeStack();
int isStackEmpty(TreeStack *treeStack);
void push(TreeStack *treeStack, BiTreeNode *treeNode);
BiTreeNode *pop(TreeStack *treeStack);
void freeStack(TreeStack *treeStack);
#endif
