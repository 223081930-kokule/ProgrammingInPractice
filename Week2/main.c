#include <stdio.h>

int main() 
{
    double revenue;
    double expenses;
    double balance;

    // Display title header
    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    // Request user inputs
    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    // Calculate remaining financial balance
    balance = revenue - expenses;

    // Display output report
    printf("\nRevenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Budget balance: %.2f\n", balance);

    return 0;
}