#include <stdio.h>

int main()
{
    float basicSalary, housing, transport, tax;
    float grossSalary, netSalary;

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("Net Salary  : %.2f\n", netSalary);

    if (netSalary >= 20000.0)
    {
        printf("Income Status: High Income\n");
    }
    else
    {
        printf("Income Status: Standard Income\n");
    }

    return 0;
}