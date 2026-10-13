#include <stdio.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

double readDouble(const char *prompt)
{
    double value;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

void pauseScreen(void)
{
    printf("Press Enter to continue...");
    while(getchar() != '\n');
    getchar();
}