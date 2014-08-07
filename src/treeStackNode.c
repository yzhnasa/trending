#include "treeStackNode.h"

TreeStackNode *makeTreeStackNode(BiTreeNode *treeNode, TreeStackNode *next){
	TreeStackNode *treeStackNode = NULL;
	treeStackNode = (TreeStackNode *)malloc(sizeof(TreeStackNode));
	treeStackNode->node = treeNode;
	treeStackNode->next = next;
	//StackNode->prev = prev;
	return treeStackNode;
}

BiTreeNode *getStackTreeNode(TreeStackNode *treeStackNode){
	return treeStackNode->node;
}

void freeTreeStackNode(TreeStackNode *treeStackNode){
	free(treeStackNode);
}
