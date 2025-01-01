#include <stdio.h>
#include <stdlib.h>

void SumArr (int* arr)
{
    int i;
    int sum =0;

    for(i=0; i<sizeof(arr); i++)
    {
	/// Pointer notation while printing data
        printf("Array Element %i is: %d\n", i, *(arr+i) );
    }

    for(i=0; i<sizeof(arr); i++)
    {
        sum += arr[i];
    }

    printf("Sum of array elements is %d", sum);
}

int main()
{
    int arr[5];
    int i;

    for(i=0; i<5; i++)
    {
        printf("Enter Array's Element %d: ", i+1);

	/// Array notation while reading data
        scanf("%d", &arr[i]);
    }

    SumArr(arr);

    getch();

    return 0;
}
