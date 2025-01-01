#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int x, y;
    int sum;
    float *average;

    printf("Enter number of students: ");
    scanf("%d", &x);

    printf("Enter number of subjects: ");
    scanf("%d", &y);

    /// Dynamically allocate memory for 2D array (pointer to pointer)
    int **array = (int **)malloc(x * sizeof(int *));
    for (i = 0; i < x; i++) {
        array[i] = (int *)malloc(y * sizeof(int));
    }

    /// Input grades for each student
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("Enter student %d subject %d grade: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }

    /// Calculate and display total grades for each student
    for (i = 0; i < x; i++) {
        sum = 0; // reset sum for each student
        for (j = 0; j < y; j++) {
            sum += array[i][j];
        }
        printf("Student %d total Grade is %d\n", i + 1, sum);
    }

    /// Allocate memory for averages
    average = (float *)malloc(y * sizeof(float));


    for (j = 0; j < y; j++) {
        sum = 0;
        for (i = 0; i < x; i++) {
            sum += array[i][j];
        }
        average[j] = (float)sum / x; // Calculate average
    }

    /// Display average grades for each subject
    printf("\nAverage grades for each subject:\n");
    for (j = 0; j < y; j++) {
        printf("Average grade for subject %d is %.2f\n", j + 1, average[j]);
    }

    /// Free allocated memory
    for (i = 0; i < x; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the array of pointers
    free(average); // Free the averages array

    return 0;
}
