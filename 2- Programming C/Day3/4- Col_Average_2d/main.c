#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,j;
    int x,y;
    int sum;


    printf("Enter number of rows: ");
    scanf("%d", &x);

    printf("Enter number of columns: ");
    scanf("%d", &y);

    float col_sum[y];
    float col_average[y];

    for (j = 0; j < y; j++)
    {
        col_sum[j] = 0;
        col_average[j] = 0;
    }


    int array[x][y];

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("Enter row %d column %d : ", i+1, j+1);
            scanf("%d", &array[i][j]);

        }

    }



    for(j=0; j<y; j++)
    {
        for(i=0; i<x; i++)
        {
            col_sum[j] = col_sum[j] + array[i][j];

        }

    }



    for(j=0; j<y; j++)
    {
            col_average[j] = (col_sum[j]/x);


    }


    for(i=0; i<x; i++)
    {
        printf("column %d average is %f\n", i+1, col_average[i]);
    }

    getch();


    return 0;
}
