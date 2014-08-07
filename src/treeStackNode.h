#ifndef TreeStackNode_H
#define TreeStackNode_H

#include <stdlib.h>
#include "biTreeNode.h"

typedef struct TreeStackNode_ {
	BiTreeNode *node;
	struct TreeStackNode_ *next;
//	struct StackNode_ *prev;
} TreeStackNode;

TreeStackNode *makeTreeStackNode(BiTreeNode *treeNode, TreeStackNode *next);
BiTreeNode *getStackTreeNode(TreeStackNode *treeStackNode);
void freeTreeStackNode(TreeStackNode *treeStackNode);
#endif
