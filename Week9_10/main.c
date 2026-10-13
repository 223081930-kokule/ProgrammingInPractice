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
```[cite: 11, 13, 42]

---

### Final Push to GitHub

Once you save `main.c`, run these final commands in your terminal to stage, commit, and push your completed Week 9 and 10 lab work to GitHub[cite: 4]:

```bash
git add Week9_10
git commit -m "Complete Week 9 and 10 labs for MFMS"
git push origin main
```[cite: 4]