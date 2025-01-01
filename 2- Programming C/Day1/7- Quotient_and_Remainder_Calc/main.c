#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);
    printf("Quotient = %d\nRemainder = %d", x/y, x%y);
    getch();
    return 0;
}
