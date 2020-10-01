#include <stdio.h>

// Name: Kazim Akhlaqi
// Student Number: 103638177
// Email: kakhlaqi@myseneca.ca
// Section: IPC144SRR
// Workshop: 3 in_lab Temp.c

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3

int main(void) {

		int i = 0, highTemp = 0, lowTemp = 0;
		double totalTemp = 0.0;
	
		printf("---=== IPC Temperature Analyzer ===---\n");

		for (i = 0; i < NUMS; i++)
		{
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);

			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);

			while (highTemp < lowTemp || highTemp > 40 || highTemp < -40 || lowTemp < -40 || lowTemp > 40) {

				printf("\n");

				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

				printf("\n");

				printf("Enter the high value for day %d: ", i + 1);

				scanf("%d", &highTemp);

				printf("\n");

				printf("Enter the low value for day %d: ", i + 1);
				scanf("%d", &lowTemp);
			}
			totalTemp += (double)highTemp + (double)lowTemp;
		}

		totalTemp /= (NUMS * 2);

		printf("\n");

		printf("The average (mean) temperature was: %.2f\n", totalTemp);
		
		return 0;
	}



