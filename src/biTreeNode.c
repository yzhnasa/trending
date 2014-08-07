#include "biTreeNode.h"

BiTreeNode *makeTreeNode(char *key, int keyLength){
	BiTreeData *tempData = NULL;
	tempData = makeData(key, keyLength);
	BiTreeNode *newTreeNode = NULL;
	newTreeNode = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	newTreeNode->data = tempData;
	newTreeNode->right = NULL;
	newTreeNode->left = NULL;
	return newTreeNode;
}

int getTreeNodeResult(BiTreeNode *node){
	return getResult(node->data);
}

char *getTreeNodeWord(BiTreeNode *node){
	return getWord(node->data);
}

int getTreeNodeStartWordCount(BiTreeNode *node){
	return getStartWordCount(node->data);
}

int getTreeNodeEndWordCount(BiTreeNode *node){
	return getEndWordCount(node->data);
}

void treeNodeStartWordCountPlusOne(BiTreeNode *node){
	startWordCountPlusOne(node->data);
}

void treeNodeEndWordCountPlusOne(BiTreeNode *node){
	endWordCountPlusOne(node->data);
}

//static void freeTreeNode(BiTreeNode *node){
void freeTreeNode(BiTreeNode *node){
	freeData(node->data);
	free(node);
}

void freeAllTreeNode(BiTreeNode *node){
	if(node->right != NULL)
		freeAllTreeNode(node->right);
	if(node->left != NULL)
		freeAllTreeNode(node->left);
	freeTreeNode(node);
}
