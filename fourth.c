#include <stdlib.h>
#include <stdio.h>
#include "fourth.h"
//takes table int array, and val to insert
//will output "inserted" if inserted
//will output "duplicate" if duplicate
void insert(int table[], int val){
	int index;
	index = val % 1000;
	if(table[index] == -1)
	{//space is empty
		table[index] = val;
	}else{//collision
		while(table[index] != -1)
		{
			if(table[index] == val){//duplicate
				printf("duplicate\n");
				return;
			}

			index = (index + 1)%1000;
		}
		table[index] = val;
	}
	printf("inserted\n");
}
void search(int table[], int val){
	int index;
	index = val % 1000;
	if(table[index] == -1)
	{//absent
		printf("absent\n");
	}else{
		while(table[index] != -1)
		{
			if(table[index] == val)
			{//present
				printf("present\n");
				return;
			}
			index = (index + 1)%1000;
		}
		//if not found, absent
		printf("absent\n");
	}
		
}

void printTable(int table[]){
	int counter;
	for(counter = 0; counter < 1000; counter++)
	{
		if(table[counter] != -1)
		{
			printf("%i ", table[counter]);
		}else{
			printf(".");
		}
	}
}

int main(int argc, char**argv){
	char *fileName;
	if(!(argc == 2))
	{
		printf("error\n");
		exit(1);
	}
	fileName = argv[1];
	FILE *filePointer = fopen(fileName, "r");
	if(filePointer == NULL)
	{
		printf("error\n");
		exit(1);
	}
	char instruct;
	int val;
	int table[1000];
	int counter;
	int argCount;
	
	val = -1;
	for(counter = 0; counter < 1000; counter++)
	{
		table[counter] = -1;
	}
	
	argCount = fscanf(filePointer, "%c %i\n", &instruct, &val);
	if(argCount == EOF || argCount == 0)
	{//empty file
		printf("\n");
		fclose(filePointer);
		exit(0);
	}
	if((instruct == '\0' || instruct == '\n') && val == -1)
	{//empty file
		printf("\n");
		fclose(filePointer);
		exit(0);
	}
	while(argCount != EOF)
	{
		if(instruct == 'i')
		{
			//insert val to hash table
			//without duplicates
			//inserted or duplicate
			if(val == -1)
			{//incorrect input
				printf("error\n");
			}else{
				insert(table, val);
			}
		}else if(instruct == 's')
		{
			//search for val
			//present or absent
			if(val == -1)
			{//incorrect input
				printf("error\n");
			}else{
				search(table, val);
			}
		}else{//improper command
			printf("error\n");
		}
		val = -1;
		argCount = fscanf(filePointer, "%c %i\n", &instruct, &val);
	}
	
	if(argCount == EOF)
	{
		//end of file
	}else{
		//error in file structure
		printf("error\n");
	}
	fclose(filePointer);
}
