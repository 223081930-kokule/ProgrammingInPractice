#include <stdio.h>
#include <string.h>

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        while (getchar() != '\n');

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4: {
                float amt, vat;
                printf("Enter amount: ");
                scanf("%f", &amt);
                vat = calculateVAT(amt);
                printf("VAT: %.2f\n", vat);
                break;
            }
            case 5: {
                float basic, housing, transport, total;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                total = calculateSalary(basic, housing, transport);
                printf("Gross Salary: %.2f\n", total);
                break;
            }
            case 6: {
                float rev, exp, res;
                printf("Enter revenue: ");
                scanf("%f", &rev);
                printf("Enter expenses: ");
                scanf("%f", &exp);
                res = calculateBudget(rev, exp);
                printf("Budget balance: %.2f\n", res);
                if (res > 0) {
                    printf("SURPLUS\n");
                } else if (res < 0) {
                    printf("DEFICIT\n");
                } else {
                    printf("BALANCED\n");
                }
                break;
            }
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 7);

    return 0;
}

void displayMenu() {
    printf("\n=====================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=====================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

void addSupplier() {
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
    char desc[200];

    FILE *f = fopen("suppliers.txt", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    getchar();

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = 0;

    strcpy(desc, name);
    strcat(desc, " operates in ");
    strcat(desc, town);
    strcat(desc, ".");
    printf("Description: %s\n", desc);

    fprintf(f, "%s,%s,%s,%s\n", name, email, phone, town);
    fclose(f);
    printf("Supplier saved successfully!\n");
}

void displaySupplier() {
    char line[300];
    FILE *f = fopen("suppliers.txt", "r");
    if (f == NULL) {
        printf("No suppliers found.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");
    while (fgets(line, sizeof(line), f) != NULL) {
        char name[100], email[100], phone[30], town[50];
        sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, email, phone, town);
        printf("Name: %s | Email: %s | Phone: %s | Town: %s\n", name, email, phone, town);
        printf("Name length: %zu\n", strlen(name));
    }
    fclose(f);
}

void searchSupplier() {
    char searchName[100];
    char line[300];
    int found = 0;

    FILE *f = fopen("suppliers.txt", "r");
    if (f == NULL) {
        printf("No suppliers found to search.\n");
        return;
    }

    getchar();
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        char name[100], email[100], phone[30], town[50];
        sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, email, phone, town);
        
        if (strcmp(name, searchName) == 0) {
            printf("Supplier found!\n");
            printf("Name: %s, Email: %s, Phone: %s, Town: %s\n", name, email, phone, town);
            found = 1;
            break;
        }
    }
    fclose(f);

    if (!found) {
        printf("Supplier not found.\n");
    }
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}