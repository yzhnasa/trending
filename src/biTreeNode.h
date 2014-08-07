#ifndef BiTreeNode_H
#define BiTreeNode_H

#include <stdlib.h>
#include "biTreeData.h"

typedef struct BiTreeNode_ {
	BiTreeData *data;
	struct BiTreeNode_ *right;
	struct BiTreeNode_ *left;
} BiTreeNode;

BiTreeNode *makeTreeNode(char *key, int keyLength);
int getTreeNodeResult(BiTreeNode *node);
char *getTreeNodeWord(BiTreeNode *node);
int getTreeNodeStartWordCount(BiTreeNode *node);
int getTreeNodeEndWordCount(BiTreeNode *node);
void treeNodeStartWordCountPlusOne(BiTreeNode *node);
void treeNodeEndWordCountPlusOne(BiTreeNode *node);
//static void freeTreeNode(BiTreeNode *node);
void freeTreeNode(BiTreeNode *node);
void freeAllTreeNode(BiTreeNode *node);
#endif
