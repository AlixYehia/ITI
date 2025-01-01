#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>
int main()
{
    /////// Magic Box 3x3 ///////

    int num = 1, row = 1, col = 2, col_factor = 5, row_factor = 3;
    int i;
    int magic_box = 3(3^2+1)/2;

    printf("Magic box value = %d\n", magic_box);
    getch();

    for (i=0; i<9; i++, num++)
    {
        gotoxy(col * col_factor, row * row_factor); // so numbers wont stick to each other
        printf("%d", num);
        getch();
        if(num%3 == 0)
        {
            row++;
            if(row > 3)
            {
                row = 1;
            }
        }
        else
        {
            row--;
            col--;
            if(row < 1)
            {
                row = 3;
            }
            if(col < 1)
            {
                col = 3;
            }
        }


    }


    return 0;
}
