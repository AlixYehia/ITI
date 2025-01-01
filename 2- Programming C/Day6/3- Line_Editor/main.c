#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>

int main()
{
    int current_selection = 0;
    char name[10];
    int i;
    char ch;

    textattr(0x47);
    gotoxy(10, 10);

    for(i=0; i<10; i++)
    {
        printf(" ");
    }

    gotoxy(10,10);

    ch = 0; // Initialize ch to enter the loop

    while (ch != 13 && ch != 27) // Continue until Enter (13) or Esc (27) is pressed
    {
        ch = getch();

        switch (ch)
        {
            case 77: // Right arrow key
                if (current_selection < 10)
                {
                    current_selection += 1;

                }
                else
                {
                    textattr(0x47);
                    printf("");
                }
                break;

            case 75: // Left arrow key
                if (current_selection > 0)
                {
                    current_selection -= 1;

                }
                else
                {
                    textattr(0x47);
                    printf("");
                }
                break;

            case 71: // Home key
                current_selection = 0;
                break;

            case 79: // End key
                current_selection = 10;
                break;
            default:
                if (ch >= 32 && ch <= 126) // Printable ASCII characters
                {
                    name[current_selection] = ch; // Store character in the array
                    gotoxy(10 + current_selection, 10);
                    textattr(0x47); // Red background
                    if (current_selection < 10)
                    printf("%c", ch);

                    // Move to the next position if available
                    if (current_selection < 9)
                    {
                        current_selection += 1;
                    }
                }
        }

        // Update position or output based on current_selection
        gotoxy(10 + current_selection, 10);
    }

    gotoxy(10, 15);
    // After breaking from the loop, print a message or execute further code
    if (ch == 13) // Enter
    {
        textattr(0x07);
        for(i=0; i<current_selection; i++)
        printf("%c", name[i]);
    }


    getch();

    return 0;
}
