#include <stdio.h>
#include <string.h>

#define VEHICLE_COUNT 5

int main() {
    char registrations[VEHICLE_COUNT][20];
    char searchReg[20];
    int found = 0;

    printf("--- Vehicle Registration Entry ---\n");
    for (int i = 0; i < VEHICLE_COUNT; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\n--- Registered Vehicles ---\n");
    for (int i = 0; i < VEHICLE_COUNT; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter registration number to search: ");
    scanf("%19s", searchReg);

    for (int i = 0; i < VEHICLE_COUNT; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration %s found at position %d.\n", searchReg, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Registration %s not found.\n", searchReg);
    }

    return 0;
}