#include <stdio.h>

int main()
{

    int x, arrY[5];
    int a[5][10];
    int i, j;



    printf("Enter number of jagged array rows: ");
    scanf("%d", &x);


    for (i = 0; i < x; i++)
    {
        printf("Enter number of columns for row %d: ", i + 1);
        scanf("%d", &arrY[i]);
    }



    for (i = 0; i < x; i++)
    {
        for (j = 0; j < arrY[i]; j++)
        {
            printf("Enter jagged array element of row %d column %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }


    printf("\nThe jagged array is:\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < arrY[i]; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    getch();

    return 0;
}
