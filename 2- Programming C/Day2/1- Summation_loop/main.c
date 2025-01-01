#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Receive numbers from the user, and exit when the sum exceeds 100
    int x, sum = 0;

    while(sum < 101)
    {
        printf("Enter the number to add: ");
        scanf("%d", &x);
        sum = sum + x
        printf("Sum = %d\n", sum);
    }

    return 0;
}
