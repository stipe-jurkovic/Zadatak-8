#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binsearchtreefunc.h"



int main() {
	Position P;
	int choice = 1, n = 0;
	char input[MAX_NUMBER_INT] = "\0";
	memset(input, 0, MAX_NUMBER_INT);
	P = NULL;


	while (choice != 0) {
		printMenu(); 
		while(n!=1) {
			fgets(input, sizeof(input), stdin);
			n = sscanf(input, " %i", &choice);
			if (n == 1 && (choice < 0 || choice>8)) {
					printf("Invalid input\n\n");
					n = 0;
					printMenu();
			}
			if (n==0)
			{
				printf("Invalid input\n");
				n = 0;
				printMenu();
			}
		}
		
		choice = switchCase(&P, choice);
		n = 0;
	}

	



	return PROGRAM_SUCCESS;
}