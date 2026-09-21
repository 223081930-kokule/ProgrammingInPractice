#include <stdio.h>

#define DEPT_COUNT 5

int main() {
    float budgets[DEPT_COUNT];
    float total = 0, average, temp;

    printf("--- Enter Department Budgets ---\n");
    for (int i = 0; i < DEPT_COUNT; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        total += budgets[i];
    }

    average = total / DEPT_COUNT;

    for (int i = 0; i < DEPT_COUNT - 1; i++) {
        for (int j = 0; j < DEPT_COUNT - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Department Budget Summary ---\n");
    printf("Total Municipal Budget: %.2f\n", total);
    printf("Average Department Budget: %.2f\n", average);

    printf("\n--- Sorted Budgets (Lowest to Highest) ---\n");
    for (int i = 0; i < DEPT_COUNT; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}