CC = gcc
CFLAGS = -Wall -g

trending: trending.o biTree.o biTreeNode.o biTreeData.o treeStack.o treeStackNode.o treeHeap.o
	${CC} ${CFLAGS} trending.o biTree.o biTreeNode.o biTreeData.o treeStack.o treeStackNode.o treeHeap.o -o trending
trending.o: trending.c biTree.h
	${CC} ${CFLAGS} -c trending.c
biTree.o: biTree.c biTree.h biTreeNode.h biTreeData.h treeStack.h treeHeap.h
	${CC} ${CFLAGS} -c biTree.c
biTreeNode.o: biTreeNode.c biTreeNode.h biTreeData.h
	${CC} ${CFLAGS} -c biTreeNode.c
biTreeData.o: biTreeData.c biTreeData.h
	${CC} ${CFLAGS} -c biTreeData.c
treeHeap.o: treeHeap.c treeHeap.h biTreeNode.h
	${CC} ${CFLAGS} -c treeHeap.c
treeStack.o: treeStack.c treeStack.h biTreeNode.h treeStackNode.h
	${CC} ${CFLAGS} -c treeStack.c
treeStackNode.o: treeStackNode.c treeStackNode.h
	${CC} ${CFLAGS} -c treeStackNode.c

clean:
	/bin/rm trending.o biTree.o biTreeNode.o biTreeData.o treeStack.o treeStackNode.o treeHeap.o
	
