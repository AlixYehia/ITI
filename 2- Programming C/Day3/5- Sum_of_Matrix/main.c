#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>

int main()
{

    int i,j;
    int a,b;
    int sum;


    printf("Enter number of rows of matrices: ");
    scanf("%d", &a);

    printf("Enter number of columns of matrices: ");
    scanf("%d", &b);


    int array1[a][b];
    int array2[a][b];
    int array3[a][b];


    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            array1[a][b] = 0 ;
            array2[a][b] = 0 ;
            array3[a][b] = 0 ;
        }
    }


    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            printf("Enter array1 row %d column %d: ", i+1, j+1);
            scanf("%d", &array1[i][j]);

        }

    }


    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            printf("Enter array2 row %d column %d: ", i+1, j+1);
            scanf("%d", &array2[i][j]);

        }

    }



    for(i=0; i<a; i++)
    {
           for (j = 0; j<b; j++)
        {
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("Resultant array of summation of array 1 and 2 is\n\n");
    for(i=0; i<a; i++)
    {
           for (j = 0; j<b; j++)
        {
            printf("    ");
            printf("%d", array3[i][j]);
            printf("    ");

        }
        printf("\n\n");
    }

    getch();






    return 0;
}
