/* -------------------------------------------
Name: Kazim Akhlaqi
Student number: 103638177
Email: kakhlaqi@myseneca.ca
Section: IPC144 A1MS2.c
Date: March 7, 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

int main(void)
{
	// Declare variables here:

	struct Name name;
	struct Address address;
	struct Numbers numbers;
	char condition;
	// Display the title

	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf("%s", name.firstName);



	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &condition);

	if (condition == 'Y' || condition == 'y') {

		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name.middleInitial);
	}


	printf("Please enter the contact's last name: ");
	scanf("%s", name.lastName);

	// Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf("%d", &address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%s", address.street);

	printf("Do you want to enter an appartment number? (y or n): ");
	scanf(" %c", &condition);
	if (condition == 'Y' || condition == 'y') {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &address.apartmentNumber);
	}

	while (getchar() != '\n');

	printf("Please enter the contact's postal code: ");
	scanf("%7[^/n]%*c", address.postalCode);

	printf("Please enter the contact's city: ");
	scanf("%s", address.city);

	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &condition);
	if (condition == 'Y' || condition == 'y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", numbers.cell);
	}


	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &condition);
	if (condition == 'Y' || condition == 'y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", numbers.home);
	}


	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &condition);
	if (condition == 'Y' || condition == 'y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", numbers.business);
	}


	// Display Contact Summary Details

	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
    printf("First name: %s\n", name.firstName);
	printf("Middle initial(s): %s\n", name.middleInitial);
	printf("Last name: %s\n", name.lastName);

	printf("\nAddress Details\n");
	printf("Street number: %d\n", address.streetNumber);
	printf("Street name: %s\n", address.street);
	printf("Apartment: %d\n", address.apartmentNumber);
    printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n", address.city);

	printf("\nPhone Numbers:\n");
	printf("Cell phone number: %s\n", numbers.cell);
	printf("Home phone number: %s\n", numbers.home);
	printf("Business phone number: %s\n", numbers.business);

	// Display Completion Message

	printf("\nStructure test for Name, Address, and Numbers Done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888
Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888
Structure test for Name, Address, and Numbers Done!
*/
