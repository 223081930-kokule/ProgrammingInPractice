#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"

int main(void)
{
    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n\n");
    
    addEmployee();
    listEmployees();
    addBudget();
    
    saveEmployee(1001, "Maria", 18500.50);
    loadEmployees();

    employeeReport();
    budgetReport();

    return 0;
}