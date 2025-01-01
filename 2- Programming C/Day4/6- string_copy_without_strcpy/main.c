#include <stdio.h>

int main() {
    char source[100];
    char destination[100];
    int i = 0;


    printf("Enter a string: ");
    gets(source);


    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Null-terminate the destination string


    printf("Copied string: %s\n", destination);

    getch();

    return 0;
}
