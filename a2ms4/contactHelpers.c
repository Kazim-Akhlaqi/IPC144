/* -------------------------------------------
Name: Kazim Akhlaqi
Student number: 103638177
Email: kakhlaqi
Section: IPCSRR A2MS4 contactHelpers.c
Date: 29 march, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard

void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:

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

// getIntInRange:

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

// yes:

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

// menu:

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

// ContactManagerSystem:

void ContactManagerSystem(void)
{
	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	{
		{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } }, }
	;
	int	choice;
	int condition = 0;
	do {
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
			printf("\n");
			clearKeyboard();
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n");
			clearKeyboard();
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:

			printf("\n");
			clearKeyboard();
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n");
			clearKeyboard();
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n");
			clearKeyboard();
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n");
			clearKeyboard();
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		}
	} while (choice != 0 || condition != 1);
}
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:

void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
	int i = 0;
	for (i = 0; i < size; i++) {
		int find = strcmp(contacts[i].numbers.cell, cellNum);
		if (find == 0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader

void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter

void displayContactFooter(int totalContactSum) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalContactSum);
}

// displayContact:

void displayContact(const struct Contact *dcpointer) {
	if (dcpointer->name.middleInitial[0] != '\0') {
		printf(" %s %s %s\n", dcpointer->name.firstName,
			dcpointer->name.middleInitial, dcpointer->name.lastName);
	}
	else printf(" %s %s\n", dcpointer->name.firstName, dcpointer->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n",
		dcpointer->numbers.cell, dcpointer->numbers.home, dcpointer->numbers.business);
	printf("       %d %s, ", dcpointer->address.streetNumber, dcpointer->address.street);
	if (dcpointer->address.apartmentNumber > 0) {
		printf("Apt# %d, ", dcpointer->address.apartmentNumber);
	}
	printf("%s, %s\n", dcpointer->address.city, dcpointer->address.postalCode);
}


// displayContacts:

void displayContacts(const struct Contact contact[], int contactArraysize) {

	int i;
	int validContacts = 0;
	displayContactHeader();

	for (i = 0; i < contactArraysize; i++) {
		if (strlen(contact[i].numbers.cell) > 0) {
			displayContact(&contact[i]);
			validContacts++;
		}
	}
	displayContactFooter(validContacts);
}

// searchContacts:

void searchContacts(const struct Contact contact[], int contactArraysize) {
	char phoneNum[11];
	int contactList = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	contactList = findContactIndex(contact, contactArraysize, phoneNum);

	if (contactList == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		displayContact(&contact[contactList]);
		printf("\n");
	}
}

// addContact:

void addContact(struct Contact contact[], int contactArraysize) {
	char emptyIndex[11] = { '\0' };
	struct Contact newContact = { { { 0 } } };
	int slot = findContactIndex(contact, contactArraysize, emptyIndex);
	if (slot != -1) {
		getContact(&newContact);
		contact[slot] = newContact;
		printf("--- New contact added! ---\n");
	}
	else {
		printf("*** ERROR: The contact list is full! ***\n");
	}
}

// updateContact:

void updateContact(struct Contact contact[], int contactArraysize) {
	char getContact[11] = { '\0' };
	int updateName = 0;
	int updateAddress = 0;
	int updatePhoneNumber = 0;

	int contactList;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(getContact);
	contactList = findContactIndex(contact, contactArraysize, getContact);

	if (contactList == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[contactList]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		updateName = yes();

		if (updateName == 1) {
			getName(&contact[contactList].name);
		}
		printf("Do you want to update the address? (y or n): ");
		updateAddress = yes();
		if (updateAddress == 1) {
			getAddress(&contact[contactList].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		updatePhoneNumber = yes();
		if (updatePhoneNumber == 1) {
			*contact[contactList].numbers.cell = '\0';
			*contact[contactList].numbers.home = '\0';
			*contact[contactList].numbers.business = '\0';
			getNumbers(&contact[contactList].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}

}

// deleteContact:

void deleteContact(struct Contact contact[], int contactArraysize) {
	char getContact[11] = { '\0' };
	int delContact = 0;
	int contactList;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(getContact);
	contactList = findContactIndex(contact, contactArraysize, getContact);
	if (contactList == -1)
		printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contact[contactList]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		delContact = yes();
		if (delContact == 1) {
			contact[contactList].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:

void sortContacts(struct Contact contact[], int contactArraysize) {

	int i, j;
	struct Contact temp;
	for (i = contactArraysize - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(contact[j].numbers.cell, contact[j + 1].numbers.cell) > 0) {
				temp = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}
