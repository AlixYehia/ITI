#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char firstName[50];
    char lastName[50];
    char fullName[100];


    printf("Enter your first name: ");
    gets(firstName);

    printf("Enter your last name: ");
    gets(lastName);


    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);


    printf("Your full name is: %s\n", fullName);

    getch();

    return 0;
}
