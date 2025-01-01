#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int max, min;

    int i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(array[i] < array[i+1])
        {
            min = array[i];
        }

        if(array[i] > array[i+1])
        {
            max = array[i];
        }
    }

    printf("Maximum Element is %d", max);
    printf("\nMinimum Element is %d", min);

    getch();

    return 0;
}
