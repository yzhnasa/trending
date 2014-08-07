#include "treeHeap.h"

TreeHeap *makeHeap(int size){
	TreeHeap *treeHeap = NULL;
	treeHeap = (TreeHeap *)malloc(sizeof(TreeHeap));
	treeHeap->array = (BiTreeNode **)malloc(size*sizeof(BiTreeNode *));
	treeHeap->size = size;
	treeHeap->currentSize = 1;
	initHeapArray(treeHeap);
	return treeHeap;
}

void setHeapElement(TreeHeap *heap, BiTreeNode *treeNode){
	heap->array[heap->currentSize] = treeNode;
	heap->currentSize++;
}

//static int heapNodeParent(int i){
int heapNodeParent(int i){
	return i / 2;
}

//static int heapNodeLeft(int i){
int heapNodeLeft(int i){
	return 2 * i;
}

//static int heapNodeRight(int i){
int heapNodeRight(int i){
	return 2 * i + 1;
}

//static void swapTreeNodeInHeap(BiTreeNode *firstTreeNode, BiTreeNode *secondTreeNode){
void swapTreeNodeInHeap(BiTreeNode *firstTreeNode, BiTreeNode *secondTreeNode){
	BiTreeNode tempTreeNode;
	tempTreeNode = *firstTreeNode;
	*firstTreeNode = *secondTreeNode;
	*secondTreeNode = tempTreeNode;
}

void heapSort(TreeHeap *heap){
	makeMaxHeapify(heap);
	BiTreeNode *largestHeapNode = heap->array[1];
	BiTreeNode *ithHeapNode = NULL;
	int i;
	for(i = heap->size - 1; i > 0; i--){
		ithHeapNode = heap->array[i];
		swapTreeNodeInHeap(ithHeapNode, largestHeapNode);
		heap->currentSize = heap->currentSize - 1;
		maxHeapify(heap, 1);
	}
}

void makeMaxHeapify(TreeHeap *heap){
	int i;
	for(i = (heap->size - 1) / 2; i > 0; i--)
		maxHeapify(heap, i);
}

//static void maxHeapify(TreeHeap *heap, int i){
void maxHeapify(TreeHeap *heap, int i){
	if(i >= heap->size - 1)
		return;
	int l = heapNodeLeft(i);
	int r = heapNodeRight(i);

	if(l >= heap->size -1 || r >= heap->size - 1)
		return;
	int largest;

	BiTreeNode *leftHeapNode = heap->array[l];
	BiTreeNode *rightHeapNode = heap->array[r];
	BiTreeNode *ithHeapNode = heap->array[i];
	BiTreeNode *largestHeapNode = NULL;
	int leftTrendCount = getTreeNodeResult(leftHeapNode);
	int rightTrendCount = getTreeNodeResult(rightHeapNode);
	int ithTrendCount = getTreeNodeResult(ithHeapNode);
	int largestTrendCount;

	if((l <= heap->currentSize) && (leftTrendCount > ithTrendCount))
		largest = l;
	else
		largest = i;
	
	largestHeapNode = heap->array[largest];
	largestTrendCount = getTreeNodeResult(largestHeapNode);
	if((r <= heap->currentSize) && (rightTrendCount > largestTrendCount)){
		largest = r;
		largestHeapNode = heap->array[largest];
	}
	if(largest != i){
		swapTreeNodeInHeap(ithHeapNode, largestHeapNode);
		maxHeapify(heap, largest);
	}
		return;
}

//static void initHeapArray(TreeHeap *heap){
void initHeapArray(TreeHeap *heap){
	int i;
	for(i = 0; i < heap->size; i++)
		heap->array[i] = NULL;
}

void freeHeap(TreeHeap *heap){
	free(heap->array);
	free(heap);
}
