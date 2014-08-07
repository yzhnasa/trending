#ifndef BiTreeData_H
#define BiTreeData_H

#include <stdlib.h>
#include <string.h>

typedef struct BiTreeData_ {
	char *word;
	int startWordCount;
	int endWordCount;
} BiTreeData;

BiTreeData *makeData(char *key, int keyLength);
int getResult(BiTreeData *data);
char *getWord(BiTreeData *data);
int getStartWordCount(BiTreeData *data);
int getEndWordCount(BiTreeData *data);
void startWordCountPlusOne(BiTreeData *data);
void endWordCountPlusOne(BiTreeData *data);
void freeData(BiTreeData *data);
#endif
