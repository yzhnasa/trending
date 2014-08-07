#ifndef TreeHeap_H
#define TreeHeap_H

#include <stdlib.h>
#include "biTreeNode.h"

typedef struct TreeHeap_ {
	BiTreeNode **array;
	int size;
	int currentSize;
} TreeHeap;

TreeHeap *makeHeap(int size);
void setHeapElement(TreeHeap *heap, BiTreeNode *treeNode);
/*static int heapNodeParent(int i);
static int heapNodeLeft(int i);
static int heapNodeRight(int i);
static void swapTreeNodeInHeap(BiTreeNode *firstTreeNode, BiTreeNode *secondTreeNode);*/
int heapNodeParent(int i);
int heapNodeLeft(int i);
int heapNodeRight(int i);
void swapTreeNodeInHeap(BiTreeNode *firstTreeNode, BiTreeNode *secondTreeNode);
void heapSort(TreeHeap *heap);
void makeMaxHeapify(TreeHeap *heap);
/*static void maxHeapify(TreeHeap *heap, int i);
static void initHeapArray(TreeHeap *heap);*/
void maxHeapify(TreeHeap *heap, int i);
void initHeapArray(TreeHeap *heap);
void freeHeap(TreeHeap *heap);
#endif
