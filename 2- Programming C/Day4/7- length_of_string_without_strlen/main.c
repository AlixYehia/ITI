#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate length of the string
    while (str[length] != '\0')
    {
        if (str[length] == '\n')
        {
            break; // Stop counting if newline is encountered
        }
        length++;
    }

    printf("Length of the string: %d\n", length);

    getch();

    return 0;



/*

Buffer Overflow Risk:

gets: Does not check the buffer size, leading to potential buffer overflow.
fgets: Takes the buffer size as a parameter, preventing overflow by limiting the number of characters read.
Newline Handling:

gets: Discards the newline character, so the string does not contain it.
fgets: Includes the newline character in the string if there is room in the buffer.
Safety:

gets: Considered unsafe and has been deprecated in C11; it should not be used in modern C programming.
fgets: Safe to use and recommended for reading strings from input.

*/




}
