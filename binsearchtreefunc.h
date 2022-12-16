#pragma once

#define PROGRAM_FAIL -1
#define PROGRAM_SUCCESS 0
#define MAX_NUMBER_INT 128


typedef struct node* Position;

typedef struct node {
	int value;
	Position right;
	Position left;
} Node;

int initNode(Position P);
Position newNode(Position P, int val);
Position insertNode(Position P, Position Q);
int printNode(Position P);
int printTreeinorder(Position P);
int printTreepreorder(Position P);
int printTreepostorder(Position P);
int printMenu();

int switchCase(Position* Padr, int choice);