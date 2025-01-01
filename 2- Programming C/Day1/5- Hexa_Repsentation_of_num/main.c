#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter the number you want to convert to Hexa: ");
    scanf("%d", &x);
    printf("The Hexa representation of %d is %x", x, x);
    getch();

    return 0;
}
