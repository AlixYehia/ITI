#include <stdio.h>
#include <stdlib.h>


void swap_integers(int* x, int* y)
{
    int temp;

    temp = *x;

    *x = *y;

    *y = temp;
}

int main()
{
    int x , y;

    int* a, b;

    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    printf("Before swap x = %d , y = %d", x, y);

    a = &x;
    b = &y;

    swap_integers(a, b);

    printf("\nAfter swap x = %d , y = %d", x, y);

    getch();

    return 0;

}
