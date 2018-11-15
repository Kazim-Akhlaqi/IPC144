#pragma once

/* -------------------------------------------
Name: Kazim Akhlaqi
Student number: 103638177
Email: kakhlaqi@myseneca.ca
Section: IPC 144 - Assignment1 Contacts.h
Date: 6 March, 2018
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration

struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration

struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};