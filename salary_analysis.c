#include <stdio.h>

#define SIZE 5

int main() {
    float salaries[SIZE];
    float total = 0, average, searchSalary;
    float highest, lowest, temp;
    int found = 0;

    printf("--- Enter Employee Salaries ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        total += salaries[i];
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < SIZE; i++) {
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    average = total / SIZE;

    printf("\n--- Salary Report ---\n");
    printf("Total Salary Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < SIZE; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f found at position %d\n", searchSalary, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Salary %.2f not found in records.\n", searchSalary);
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n--- Sorted Salaries (Ascending) ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}