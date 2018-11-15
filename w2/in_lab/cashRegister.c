/*
Kazim Akhlaqi #103638177
IPC144SRR, In_Lab Wk02 
cashRegister.c
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int loonies, quarters;
    float amount, balanceL, balanceQ;
 
    printf("Please enter the amount to be paid: $"); // Ask user to print an amount
    scanf("%f", &amount); // Get input from user

    loonies = amount;
    printf("Loonies required: %d, ", loonies);
    balanceL = amount - loonies;
    printf("balance owing $%.2f\n", balanceL);

    quarters = balanceL / 0.25;
    printf("Quarters required: %d, ", quarters);
    balanceQ = balanceL - quarters * 0.25;
    printf("balance owing $%.2f\n", balanceQ);
    return 0;
}
