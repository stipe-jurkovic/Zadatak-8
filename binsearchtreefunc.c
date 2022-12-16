#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binsearchtreefunc.h"

int initNode(Position P) 
{
	P->value=0;
	P->right=NULL;
	P->left=NULL;
	return PROGRAM_SUCCESS;
}
int initStog(Poz S) {
	S->adr = NULL;
	S->next = NULL;
	return PROGRAM_SUCCESS;
}
Position newNode(Position P, int val) 
{
	Position Q;
	Q = malloc(sizeof(Node));
	if (Q == NULL)
	{
		printf("Insufficient ram space!");
		return P;
	}
	initNode(Q);
	Q->value = val;
	P = insertNode(P, Q);
	return P;
}
Position insertNode(Position P, Position Q) {
	if (P == NULL) return Q;
	if (Q->value > P->value) {
		P->right = insertNode(P->right, Q);
		return P;
	}
	else if (Q->value < P->value) {
		P->left = insertNode(P->left, Q);
		return P;
	}
	else {
		printf("Value already in tree!");
		free(Q);
	}
	return P;
}
int printNode(Position P) 
{
	printf(" %i", P->value);
	return PROGRAM_SUCCESS;
}
int printTreeinorder(Position P) {
	if (P == NULL) return PROGRAM_SUCCESS;
	printTreeinorder(P->left);
	printNode(P);
	printTreeinorder(P->right);
	return PROGRAM_SUCCESS;
}
int printTreepreorder(Position P) {
	if (P == NULL) return PROGRAM_SUCCESS;
	printNode(P);
	printTreepreorder(P->left);
	printTreepreorder(P->right);
	return PROGRAM_SUCCESS;
}
int printTreepostorder(Position P) {
	if (P == NULL) return PROGRAM_SUCCESS;
	printTreepostorder(P->left);
	printTreepostorder(P->right);
	printNode(P);
	return PROGRAM_SUCCESS;
}
int printTreelevelorder(Position P) {
	Poz stack;
	stack = malloc(sizeof(Stog));
	initStog(stack);
	if (stack == NULL) {
		printf("Insufficient ram space!\n");
		return PROGRAM_FAIL;
	}

	pushtree(stack, P);
	push(stack, P);
	printStack(stack);
	free(stack);
	return PROGRAM_SUCCESS;
}
int printMenu() {

	printf("\n");
	printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n");
	printf("Unesite broj one opcije koju zelite odabrati.\n");
	printf("(0)  Prekinuti program.\n");
	printf("(1)  Dodati novu vijednost u stablo.\n");
	printf("(2)  Izbrisati element iz stabla.\n");
	printf("(3)  Pronaci element te ispisati njegovu dubinu u stablu.\n");
	printf("(4)  Ispisati stablo (inorder).\n");
	printf("(5)  Ispisati stablo (preorder).\n");
	printf("(6)  Ispisati stablo (postorder).\n");
	printf("(7)  Ispisati stablo (level order).\n");
	printf("(8) Izbrisati stablo.\n");
	printf("\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
	printf("   Unos:    ");
	return PROGRAM_SUCCESS;
}
int switchCase(Position *Padr, int choice) {
	int val = 0;
	Position P;
	P = *Padr;

	switch (choice)
	{
	default:
	case 0 : 
		break;
	case 1:
		if (!getInput(&val)) {
			*Padr = newNode(P, val);
		}
		else {
			printf("Incorrect input!");
		}
		break;
	case 2:
		break;
	case 3:
		val = 0;

		if (!getInput(&val)) 
		{
			findNode(P, val, 0);
		}
		else {
			printf("Incorrect input!");
		}
		break;
	case 4:
		printf("\tInorder ispis:  ");
		printTreeinorder(P);
		printf("\n");
		break;
	case 5:
		printf("\tPreorder ispis:  ");
		printTreepreorder(P);
		printf("\n");
		break;
	case 6:
		printf("\tPostorder ispis:  ");
		printTreepostorder(P);
		printf("\n");
		break;
	case 7:
		printf("\tPostorder ispis:  ");
		printTreelevelorder(P);
		printf("\n");
		break;
	case 8:
		break;
	}
	return choice;
}
int push(Poz stack, Position P)
{
	if (P == NULL) {
		return PROGRAM_FAIL;
	}
	Poz Q;
	Q = malloc(sizeof(Stog));
	if (Q == NULL)
	{
		return PROGRAM_FAIL;
	}
	initStog(Q);

	Q->next = stack->next;
	stack->next = Q;
	Q->adr = P;

	return PROGRAM_SUCCESS;
}
int pushtree(Poz stack, Position P) {
	if (P == NULL) {
		return PROGRAM_SUCCESS;
	}
	pushtree(stack, P->right);
	pushtree(stack, P->left);
	push(stack, P->right);
	push(stack, P->left);
	return PROGRAM_SUCCESS;
}
Position pop(Poz stack)
{
	Poz temp;
	Position adr;
	adr = NULL; temp = NULL;

	temp = stack->next;
	stack->next = temp->next;
	adr = temp->adr;
	initStog(temp);
	free(temp);
	return adr;
}
int printStack(Poz stack)
{
	while (stack->next != NULL) {
		printf(" %i", pop(stack)->value);
	}
	return PROGRAM_SUCCESS;
}
int findNode(Position P, int val, int D) {
	
	if (val > P->value) {
		findNode(P->right, val, ++D);
	}
	else if (val < P->value) {
		findNode(P->left, val, ++D);
	}
	else {
		printf("\tValue found! Value:");
		printNode(P);
		printf("\n\tDepth of node: %i\n", D);
	}
	return PROGRAM_SUCCESS;
}
int getInput(int *val) 
{
	*val = 0;
	char input[MAX_NUMBER_INT] = "\0";
	memset(input, 0, MAX_NUMBER_INT);

	printf("\tEnter the value of the node:    ");
	fgets(input, sizeof(input), stdin);
	
	if (sscanf(input, " %i", val) == 1) {
		return PROGRAM_SUCCESS;
	}
	return PROGRAM_FAIL;
}