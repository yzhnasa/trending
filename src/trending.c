#include <stdio.h>
#include "biTree.h"

void usage(char *progName, FILE *file);
int main(int argc, char *argv[]){
	if(argc != 3){
		usage(argv[0], stderr);
		exit(1);
	}

	FILE *inputFile1 = fopen(argv[1], "r");
	if(NULL == inputFile1){
		fprintf(stderr, "File %s not exit.\n", argv[1]);
	}

	FILE *inputFile2 = fopen(argv[2], "r");
	if(NULL == inputFile2){
		fprintf(stderr, "File %s not exit.\n", argv[2]);
	}

	BiTree *tree = makeBiTree(inputFile1, inputFile2);
	printTrend(tree);

	fclose(inputFile1);
	fclose(inputFile2);

	freeBiTree(tree);

	return 0;
}

void usage(char *progName, FILE *file){
	fprintf(file, "%s inputFile outputFile.\n", progName);
}
