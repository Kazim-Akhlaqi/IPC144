#include<stdio.h>
#include <stdbool.h>

/*
Name: Kazim Akhlaqi
Student Number: 103638177
Email: Kakhlaqi@myseneca.ca
Section: IPC144SRR
Workshop: Wk04 Array in_lab
*/

#define SIZE 10
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	int i;
	int validNumDay;
	int highTemp[SIZE];
	int lowTemp[SIZE];
	int highestTemp = 0;
	int lowestTemp = 0;
	int lowestTempDay = 0;
	int highestTempDay = 0;
	float totalTemp = 0;
	int validNumbDayAvg = 0;
	float aveTemp = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");

	do {
		scanf("%d", &validNumDay);
		if (validNumDay < 3 || validNumDay > 10) {
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		}
	} while (validNumDay < 3 || validNumDay > 10);

	printf("\n");

	for (i = 0; i < validNumDay; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemp[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemp[i]);

		if (highTemp[i] > highestTemp) {
			highestTemp = highTemp[i];
			highestTempDay = i + 1;
		}

		if (lowTemp[i] < lowestTemp) {
			lowestTemp = lowTemp[i];
			lowestTempDay = i + 1;
		}
	}

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < validNumDay; i++) {
		printf("%d    %d    %d\n", i + 1, highTemp[i], lowTemp[i]);
	}

	printf("\nThe highest temperature was %d, on day %d", highestTemp, highestTempDay);
	
	printf("\nThe lowest temperature was %d, on day %d", lowestTemp, lowestTempDay);

	printf("\n");

	bool exit = false;

	char avgStr[200];
	
	sprintf(avgStr, "\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", validNumDay);
	
	printf( avgStr);

	do {
		
		scanf("%d", &validNumbDayAvg);

		if (validNumbDayAvg < 0) {
			break;
		}
		else if (validNumbDayAvg < 1 || validNumbDayAvg > validNumDay) {

			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", validNumDay);

			continue;
		}
		else {
			//reset totalTemp to 0 on each loop iteration.
			totalTemp = 0;

			for (i = 0; i < validNumbDayAvg; i++) {
				totalTemp += (float)highTemp[i] + (float)lowTemp[i];
			}
			aveTemp = totalTemp / (validNumbDayAvg * 2);

			printf("\nThe average temperature up to day %d is: %.2f", validNumbDayAvg, aveTemp);

			printf("\n");
			
			printf(avgStr);
		}

	} while (!exit);

	printf("\nGoodbye!\n");

	return 0;
}                    
