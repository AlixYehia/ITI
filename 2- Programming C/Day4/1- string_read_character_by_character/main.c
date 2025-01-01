#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int i = 0;
    char ch;

    printf("Enter characters (Press Enter to terminate input):\n");

    while (1) {
        ch = getchar();


        if (ch == '\n')
        {
            str[i] = '\0';
            break;
        }

        str[i++] = ch;

    }

    printf("You entered: %s\n", str);
    getch();

}
