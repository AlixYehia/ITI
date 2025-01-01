#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100], result[100];
    int i, j = 0;

    // Input source string using gets (unsafe)
    printf("Enter a string: ");
    gets(str); // Read input (note: gets() is unsafe)

    // Filter and copy only alphabet characters
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            result[j] = str[i];
            j++;
        }
    }

    result[j] = '\0';

    // Output the result
    printf("String after removing non-alphabet characters: %s\n", result);

    getch();

    return 0;
}
