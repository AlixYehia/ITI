#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
//  char z;
    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);
    printf("Sum = %d\nSub = %d\nMultiplication = %d\nDivision = %d", x+y, x-y, x*y, x/y);
    getch();

/*

    printf("Enter the operation add, sub, multiply or divid: ");
    getchar("%s", &z);


    if(z == add)
        printf("%d", x+y);
    else if(z == sub)
        printf("%d", x-y);
    else if(z == multiply)
        printf("%d", x*y);
    else if(z == divid)
        printf("%d", x/y);
    else
        printf("invalid operation");
    getch();

*/
    return 0;
}
