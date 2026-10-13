#include <stdio.h>
#include "employees.h"

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(void)
{
    printf("Adding employee...\n");
}

void listEmployees(void)
{
    printf("Listing employees...\n");
}

double calculatePayrollTotal(void)
{
    return 0.0;
}

void saveEmployee(int id, const char *name, double salary)
{
    FILE *fp = fopen("employees.txt", "a");
    if (fp == NULL) {
        perror("employees.txt");
        return;
    }
    fprintf(fp, "%d %s|%.2f\n", id, name, salary);
    fclose(fp);
}

void loadEmployees(void)
{
    FILE *fp = fopen("employees.txt", "r");
    int id;
    char name[50];
    double salary;

    if (fp == NULL) {
        perror("employees.txt");
        return;
    }

    while (fscanf(fp, "%d %49[^|]|%lf\n", &id, name, &salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", id, name, salary);
    }
    fclose(fp);
}

void saveEmployeeBinary(const Employee *e)
{
    FILE *fp = fopen("employees.dat", "ab");
    if (fp == NULL) {
        perror("employees.dat");
        return;
    }
    fwrite(e, sizeof *e, 1, fp);
    fclose(fp);
}
```[cite: 10, 11, 12, 14]