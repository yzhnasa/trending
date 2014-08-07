#include "treeStack.h"

TreeStack *makeStack(){
	TreeStack *treeStack = (TreeStack *)malloc(sizeof(TreeStack));
	treeStack->head = makeTreeStackNode(NULL, NULL);
	treeStack->top = treeStack->head;
	return treeStack;
}

int isStackEmpty(TreeStack *treeStack){
	if(treeStack->head == treeStack->top)
		return 0;
	else
		return 1;
}

void push(TreeStack *treeStack, BiTreeNode *treeNode){
	TreeStackNode *treeStackNode = makeTreeStackNode(treeNode, NULL);
	if(treeStack->head == treeStack->top)
		treeStackNode->next = treeStack->head;
	else
		treeStackNode->next = treeStack->top;
	treeStack->top = treeStackNode;
}

BiTreeNode *pop(TreeStack *treeStack){
	TreeStackNode *tempTreeStackNode = NULL;
	BiTreeNode *tempTreeNode = NULL;
	if(treeStack->head == treeStack->top){
		freeStack(treeStack);
		return NULL;
	}else{
		tempTreeStackNode = treeStack->top;
		tempTreeNode = getStackTreeNode(tempTreeStackNode);
		treeStack->top = tempTreeStackNode->next;
		freeTreeStackNode(tempTreeStackNode);
		return tempTreeNode;
	}
}

void freeStack(TreeStack *treeStack){
	freeTreeStackNode(treeStack->head);
	free(treeStack);
}
