/* -------------------------------------------
Name: Kazim Akhlaqi
Student number: 103638177
Email: kakhlaqi@myseneca.ca
Section: IPC144 - A2 - contactHelpers.c
Date: March 20, 2018
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer

void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose

}

// pause function definition goes here:

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:

int getInt(void)
{
	char NL = 'x';
	int value = 0;
	while (NL != '\n') {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}

	return value;
}

// getIntInRange function definition goes here:

int getIntInRange(int lowerBound, int upperBound)
{
	int input;
	input = getInt();
	while (input < lowerBound || input > upperBound) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
		input = getInt();
	} 
	return input;
}

// yes function definition goes here:

int yes(void)
{
	char condition = 'x';
	char NL = 'x';
	int value = 0;
	do {
		scanf(" %c%c", &condition, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (NL != '\n');

	if (condition == 'Y' || condition == 'y') {
		value = 1;
	}
	else if (condition == 'N' || condition == 'n') {
		value = 0;
	}

	return value;
}

// menu function definition goes here:

int menu(void)
{
	int option = -1;
	
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n"); 
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
	while (option < 0 || option > 6) {
		scanf("%d", &option);
		if (option < 0 || option > 6) {
			clearKeyboard();
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	}
	return option;

}

// ContactManagerSystem function definition goes here:

void ContactManagerSystem(void)
{
	int	choice;
	int condition = 0;
	do  {
		choice = menu();
		switch (choice) {
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			condition = yes();
			if (condition) {
				printf("\nContact Management System: terminated\n");
			}
			else {
				printf("\n");
			}
			break;

		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;

		case 3:

			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			clearKeyboard();
			pause();
			printf("\n");
			break;
		}
	} while (choice != 0 || condition !=1);
}

