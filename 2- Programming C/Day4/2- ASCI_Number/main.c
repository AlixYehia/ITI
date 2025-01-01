#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    do{
        printf("Enter the key: ");
        ch = getch();

        if (ch == -32)
        {
            ch = getch();
            printf("\nYou pressed Extended key, ASCI = %d", ch);
        }
        else
        {
            printf("\nYou pressed Normal key %c, ASCI = %d", ch, ch);
        }
        printf("\n");

    }while(ch != 27);  //ESC = 27






    /*
    char x, y;

    printf("Write the character you want to convert to its equivalent ASCI number: ");
    x = getch();

    y = getch();

    printf("\nThe equivalent ASCI number to character %c is %d", y, y);

    getch();
    */

    return 0;
}
