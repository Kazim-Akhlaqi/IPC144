#include <stdio.h>

// Name: Kazim Akhlaqi
// Student Number: 103638177
// Email: kakhlaqi@myseneca.ca
// Section: IPC144SRR
// Workshop: 3 in_lab Temp.c

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3

int main(void) {

		int i;
		int highTemp;
		int lowTemp;
		float totalTemp = 0;
		float aveTemp;
	
		printf("---=== IPC Temperature Analyzer ===---");

		for (i = 0; i < NUMS; i++)
		{

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);

			while (highTemp < lowTemp || highTemp>40 || highTemp < -40 || lowTemp < -40 || lowTemp > 40) {

				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

				printf("\nEnter the high value for day %d: ", i + 1);
				scanf("%d", &highTemp);

				printf("\nEnter the low value for day %d: ", i + 1);
				scanf("%d", &lowTemp);
			}
			totalTemp = totalTemp + (float)highTemp + (float)lowTemp;
		}

		aveTemp = totalTemp /(NUMS * 2);

		printf("\nThe average (mean) temperature was: %.2f\n", aveTemp);
		
		return 0;
	}



