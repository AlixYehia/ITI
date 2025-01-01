#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;

    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    printf("Enter third number: ");
    scanf("%d", &z);

    if(x>y && x>z)
    {
        printf("largest number is %d", x);
        getch();
    }
    else if(y>x && y>z)
    {
        printf("largest number is %d", y);
        getch();
    }
    else
    {
        printf("largest number is %d", z);
        getch();
    }

    return 0;
}
