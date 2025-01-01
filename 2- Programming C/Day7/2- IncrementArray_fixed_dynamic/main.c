#include <stdio.h>
#include <stdlib.h>

int* IncrementArray()
{
    int i;
    ///int* Arr[5];
    int* Arr = malloc(5 * sizeof(int));


    for(i=0; i<5; i++)
    {
        printf("\n Enter Array Element Number %d: ", i+1);
        scanf("%d", &Arr[i]);
    }

    return Arr;
}

int main()
{
    int* Arr;
    int i;

    Arr = IncrementArray();

    printf("\nElements of Array: ");
    for(i=0; i<5; i++)
    {
        printf("\nArray[%d] = %d", i+1, Arr[i]);
    }

}
