#include "biTree.h"

BiTree *makeBiTree(FILE *inputFile1, FILE *inputFile2){
	BiTree *tree = NULL;
	tree = (BiTree *)malloc(sizeof(BiTree));
	tree->root = NULL;
	tree->size = 0;
	char tempLine[30];
	//char *enterPtr = NULL;
	initTempLine(tempLine, 30);
	while(!feof(inputFile1)){
		fgets(tempLine, 30, inputFile1);
		//enterPtr = strstr(tempLine, "\n");
		//*enterPtr = '\0';
		biTreeInsert(tree, tempLine, 30, 0);
		initTempLine(tempLine, 30);
	}

	while(!feof(inputFile2)){
		fgets(tempLine, 30, inputFile2);
		//enterPtr = strstr(tempLine, "\n");
		//*enterPtr = '\0';
		biTreeInsert(tree, tempLine, 30, 1);
		initTempLine(tempLine, 30);
	}
	return tree;
}

BiTreeNode *searchBiTree(BiTreeNode *node, char *key){
	if(strcmp(key, getTreeNodeWord(node)) == 0)
		return node;
	if(strcmp(key, getTreeNodeWord(node)) < 0){
		if(node->left != NULL)
			return searchBiTree(node->left, key);
		else
			return node;
	}else{
		if(node->right != NULL)
			return searchBiTree(node->right, key);
		else
			return node;
	}
}

void biTreeInsert(BiTree *tree, char *key, int keyLength, int fileFlag){
	BiTreeNode *tempTreeNode = NULL;
	BiTreeNode *treeNodePtr = NULL;
	if(NULL == tree->root){
		tempTreeNode = makeTreeNode(key, keyLength);
		tree->root = tempTreeNode;
		tree->size++;
		return;
	}
	treeNodePtr = searchBiTree(tree->root, key);
	if(strcmp(key, getTreeNodeWord(treeNodePtr)) == 0){
		if(fileFlag == 0)
			treeNodeStartWordCountPlusOne(treeNodePtr);
		else
			treeNodeEndWordCountPlusOne(treeNodePtr);
	}else{
		tempTreeNode = makeTreeNode(key, keyLength);
		if(strcmp(key, getTreeNodeWord(treeNodePtr)) < 0)
			treeNodePtr->left = tempTreeNode;
		else
			treeNodePtr->right = tempTreeNode;
		tree->size++;
	}
}

void printTrend(BiTree *tree){
	int i;
	BiTreeNode *currentTreeNode = tree->root;
	TreeStack *treeStack = makeStack();
	TreeHeap *treeHeap = makeHeap(tree->size + 1);
	push(treeStack, currentTreeNode);
	while(isStackEmpty(treeStack) != 0){
		currentTreeNode = pop(treeStack);
		setHeapElement(treeHeap, currentTreeNode);
		if(currentTreeNode->right != NULL)
			push(treeStack, currentTreeNode->right);
		if(currentTreeNode->left != NULL)
			push(treeStack, currentTreeNode->left);
	}
	makeMaxHeapify(treeHeap);
	heapSort(treeHeap);
	fprintf(stdout, "Trending Up:\n");
	for(i = treeHeap->size - 1; i >= treeHeap->size - 5; i--)
		fprintf(stdout, "%s (%+d)\n", getTreeNodeWord(treeHeap->array[i]), getTreeNodeResult(treeHeap->array[i]));
	fprintf(stdout, "Trending Down:\n");
	for(i = 1; i < 6; i++)
		fprintf(stdout, "%s (%+d)\n", getTreeNodeWord(treeHeap->array[i]), getTreeNodeResult(treeHeap->array[i]));
	freeHeap(treeHeap);
}

//static void initTempLine(char *tempLine, int length){
void initTempLine(char *tempLine, int length){
	int i;
	for(i = 0; i < length; i++)
		*tempLine++ = 0;
}

void freeBiTree(BiTree *tree){
	freeAllTreeNode(tree->root);	
}
