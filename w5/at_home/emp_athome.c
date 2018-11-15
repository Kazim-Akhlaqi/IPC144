/*
Name: Kazim Akhlaqi
Student number: 103638177
Email: kakhlaqi@myseneca.ca
Workshop: Wk05 Structure
Section: emp_inlab
Date: 24 Feb, 2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4

#define SIZE 4

// Declare Struct Employee 

struct Employee {
	int id;
	int age;
	double salary;
};

/* main program */
int main(void) {

	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	struct Employee emp[SIZE] = { { 0 } };
	int i;
	int validEmp = 0;
	int newEmp = 0;
	int empID = 0;
	int flag;
	double updateSalary = 0;

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);

		printf("\n");

		switch (option) {

		case 0:
			// Exit Program

			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;

		case 1:
			// Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}

			printf("\n");

			break;

		case 2:
			// Adding Emp

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 

			if (validEmp < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[newEmp].id);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[newEmp].age);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[newEmp].salary);

				newEmp = newEmp + 1;
				validEmp = validEmp + 1;
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}

			printf("\n");

			break;

		case 3:
			// Update Emp Info

			printf("Update Employee Salary\n");
			printf("======================\n");

			flag = 0;
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &empID);

				for (i = 0; i < SIZE; i++) {
					if (emp[i].id == empID) {
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &updateSalary);
						emp[i].salary = updateSalary;
						flag = 1;
					}
				}
				if (flag != 1) {
					printf("Employee not found!\n");
				}
				printf("\n");
			} while (flag == 0);

			break;

		case 4:
			// Remove Emp

			printf("Remove Employee\n");
			printf("===============\n");

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &empID);

				for (i = 0; i < SIZE; i++) {
					if (emp[i].id == empID) {
						printf("Employee %d will be removed\n", emp[i].id);
						emp[i].id = 0;
						validEmp = validEmp - 1;
						flag = 1;
					}
				}
				if (flag != 1) {
					printf("Employee not found!\n");
				}
				printf("\n");
			} while (flag == 0);

			break;

		default:
			// Defualt 

			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
