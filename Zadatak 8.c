#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binsearchtreefunc.h"



int main() {
	Position P;
	int choice = 1, n = 1;
	char input[MAX_NUMBER_INT] = "\0";
	memset(input, 0, MAX_NUMBER_INT);
	P = NULL;

	while (choice != 0) {
		printMenu(); 
		while(getInput(&choice)!=0) {
			printf("Input not recognised!\n");
			printf("\tUnos: ");
		}
		n = 1;
		if (choice >= 0 && choice <= 8) {
			choice = switchCase(&P, choice);
		}
		else {
			printf("Input is not one of the choices!\n");
		}
	}

	deletetree(P);
	return PROGRAM_SUCCESS;
}