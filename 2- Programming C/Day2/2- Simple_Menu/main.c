#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>

int main()
{
    char x;

    do {
            clrscr();
        //gotoxy(5,5);
        printf("Simple Menu:\n");
        //gotoxy(5,5);
        printf("-----------\n");
        //gotoxy(5,5);
        printf("A - Good Morning\n");
        //gotoxy(5,5);
        printf("B - Good Evening\n");
        //gotoxy(5,5);
        printf("C - Exit");
        //gotoxy(5,5);
        printf("\n\nEnter your choice: ");
        x = getch();

        switch(x)
        {

            case 'a' :  clrscr();
                        printf("Good Morning\n");
                        getch();
                        break;

            case 'b' :  clrscr();
                        printf("Good Evening\n");
                        getch();
                        break;


        }


    } while(x != 'c');


    return 0;
}
