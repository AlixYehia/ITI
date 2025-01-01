#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getche() and getch()

int main()
{
    char x;
    int Alpha_count = 0, Word_count = 0;
    int flag = 0; // To track if we are in a word

    printf("Enter the sentence you want to count the number of Alphabets and words in it: ");


    while ((x = getche()) != 13)
    {

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            Alpha_count++;
            flag = 1; // We are in a word
        }
        else if (x == 32)
        {
            if (flag) // We only want to increment the word count if we were in a word
            {
                Word_count++;
                flag = 0; // Reset flag as we are now out of a word
            }
        }
    }

    // If the last character was not a space, increment the word count
    if (flag) {
        Word_count++;
    }

    printf("\nAlpha_count = %d, Word_count = %d\n", Alpha_count, Word_count);
    getch(); // Wait for a key press
    return 0;
}
