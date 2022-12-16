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
Position newNode(Position P, int val) 
{
	Position Q;
	Q = malloc(sizeof(Node));
	if (Q == NULL)
	{
		printf("Insufficient ram space!");
		return PROGRAM_FAIL;
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
	char input [MAX_NUMBER_INT] = "\0";
	memset(input, 0, MAX_NUMBER_INT);
	P = *Padr;

	switch (choice)
	{
	default:
	case 0 : 
		break;
	case 1:
		printf("\tEnter the value of the node:    ");
		fgets(input, sizeof(input), stdin);
		if (sscanf(input," %i", &val) == 1) {
			*Padr = newNode(P, val);
		}
		else {
			printf("Incorrect input!");
		}
		break;
	case 2:
		break;
	case 3:
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
		break;
	case 8:
		break;
	}
	return choice;
}