#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);


    int array[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The elements in the array are:\n");
    for (i = 0; i < n; i++)
    {

        printf("%d\n", array[i]);

    }
    getch();

    return 0;
}
