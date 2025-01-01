#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int x,y;
    int sum;

    printf("Enter number of students: ");
    scanf("%d", &x);

    printf("Enter number of subjects: ");
    scanf("%d", &y);

    int array[x][y];

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("Enter student %d subject %d grade: ", i+1, j+1);
            scanf("%d", &array[i][j]);

        }

    }

    for(i=0; i<x; i++)
    {
        sum = 0;
        for(j=0; j<y; j++)
        {
            sum = sum + array[i][j];

        }

        printf("Student %d total Grade is %d\n", i+1, sum);
    }

    getch();

    return 0;
}
