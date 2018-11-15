#include<stdio.h>

/*
Name: Kazim Akhlaqi
Student Number: 103638177
Email: Kakhlaqi@myseneca.ca
Section: IPC144SRR
Workshop: Wk04 Array in_lab
*/

#define SIZE 10

int main(void)
{
	int i;
	int validNumDay;
	int highTemp[SIZE];
	int lowTemp[SIZE];
	int tolatlHighestTemp;
	int totalLowestTemp = 0;
	int lowestTempDay = 0;
	int highestTempDay = 0;
	float TotalTemp;
	float aveTemp;


	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
			
	do{
		scanf("%d", &validNumDay);
		if(validNumDay < 3 || validNumDay > 10){
		      printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: "); 
		}       
	} while (validNumDay < 3 || validNumDay > 10);

	printf("\n");

	for (i = 0; i < validNumDay; i++) 
	{
		printf("Day %d - High: ", i+1);
		scanf("%d", &highTemp[i]);
		printf("Day %d - Low: ", i+1);
		scanf("%d", &lowTemp[i]);

		totalTemp = totalTemp + (float)highTemp + (float)lowTemp;
		
		if (highTemp > highestTemp){
		    highestTemp = highTemp;
		    highestTempday = i + 1;
		}

		if (lowTemp > lowestTemp){
		    lowestTemp = lowTemp;
		    LowestTempDay = i + 1;
		}
	}                                   
		aveTemp = totalTemp / (vadlidNumDay * 2);

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < validNumDay; i++) {
		printf("%d    %d    %d\n", day[i], highDay[i], lowDay[i]);
	}

	printf("The highest temperature was %d, on day %d" highestTemp, highestTempDay);
	
	printf("The lowest temperature was %d, on day %D" lowestTemp, lowestTempday);                           

	printf("\n");

	printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");

	printf("\n");

	printf("Inavalid entry, please enter a number between 1 and 4, inclusive: ");

	printf("\n");

	printf(The average temperature up to day %d is: %f");
	
	printf("\n");
	
	printf("Goodbye!");

	return 0;
}
