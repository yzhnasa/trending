#include "biTreeData.h"

BiTreeData *makeData(char *key, int keyLength){
	BiTreeData *tempTreeData = NULL;
	tempTreeData = (BiTreeData *)malloc(sizeof(BiTreeData));
	char *tempWord = (char *)malloc(keyLength*sizeof(char));
	//strncpy(tempWord, key, strlen(key) - 1);
	strcpy(tempWord, key);
	tempTreeData->word = tempWord;
	tempTreeData->startWordCount = 1;
	tempTreeData->endWordCount = 0;
	return tempTreeData;
}

int getResult(BiTreeData *data){
	return data->endWordCount - data->startWordCount;
}

char *getWord(BiTreeData *data){
	return data->word;
}

int getStartWordCount(BiTreeData *data){
	return data->startWordCount;
}

int getEndWordCount(BiTreeData *data){
	return data->endWordCount;
}
void startWordCountPlusOne(BiTreeData *data){
	data->startWordCount++;
}

void endWordCountPlusOne(BiTreeData *data){
	data->endWordCount++;
}

void freeData(BiTreeData *data){
	free(data->word);
	free(data);
}
