#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int i;
    printf("Enter the number you want it's multiple table: ");
    scanf("%d", &x);

    for(i=0; i<10; i++)
    {
        printf("%d*%d=%d\n", x, i, x*i);

    }
    getch();
    return 0;
}
