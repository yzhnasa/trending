#ifndef BiTree_H
#define BiTree_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biTreeNode.h"
#include "biTreeData.h"
#include "treeStack.h"
#include "treeHeap.h"

typedef struct BiTree_ {
	BiTreeNode *root;
	int size;
} BiTree;

BiTree *makeBiTree(FILE *inputFile1, FILE *inputFile2);
BiTreeNode *searchBiTree(BiTreeNode *node, char *key);
void biTreeInsert(BiTree *tree, char *key, int keyLength, int fileFlag);
//int biTreeRemove(BiTree *tree, char *key);
//BiTreeNode *searchBiTree(BiTree *tree, char *key);
//static void initTempLine(char *tempLine, int length);
void initTempLine(char *tempLine, int length);
void printTrend(BiTree *tree);
void freeBiTree(BiTree *tree);
#endif
