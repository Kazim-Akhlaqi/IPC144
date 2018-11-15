/*
Kazim Akhlaqi #103638177
IPC144SRR, at_home Wk02
cashRegister.c
*/

#include <stdio.h>
#include <math.h>

int main(void)
{

    int loonies, quarters, dimes, nickels, pennies;
    float balanceOwingL, balanceOwingQ, balanceOwingD, balanceOwingN, balanceOwingP;
    float amount, gst, amountAfterGst;

    printf("Please enter the amount to be paid: $"); // Ask user to print an amount
    scanf("%f", &amount); // Get input from user
    gst = amount * 0.13 + 0.005; // Calculate GST
    amountAfterGst = amount + gst;

    printf("GST: %.2f\n", gst); // Print GST
    
    printf("Balance owing: $%.2f\n", amountAfterGst);

    loonies = (int) amountAfterGst;
    printf("Loonies required: %d, ", loonies);
    balanceOwingL = amountAfterGst - loonies;
    printf("balance owing $%.2f\n", balanceOwingL);

    balanceOwingL = balanceOwingL * 100;
    quarters = (int) balanceOwingL / 25;
    printf("Quarters required: %d, ", quarters);
    balanceOwingQ = (int) balanceOwingL % 25;
    printf("balance owing $%.2f\n", balanceOwingQ / 100);

    dimes = (int) balanceOwingQ / 10;
    printf("Dimes required: %d, ", dimes);
    balanceOwingD = (int) balanceOwingQ % 10;
    printf("balance owing $%.2f\n", balanceOwingD / 100);

    nickels = (int) balanceOwingD / 5;
    printf("Nickels required: %d, ", nickels);
    balanceOwingN = (int) balanceOwingD % 5;
    printf("balance owing $%.2f\n", balanceOwingN /100);

    pennies = balanceOwingN / 1;
    printf("Pennies required: %d, ", pennies);
    balanceOwingP = (int) balanceOwingN % 1;
    printf("balance owing $%.2f\n", balanceOwingP / 100);

    return 0;
}
