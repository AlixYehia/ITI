#include <stdio.h>

int findLargest(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}

int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    int largest = findLargest(a, b, c);
    printf("The largest number is: %d\n", largest);

    getch();

    return 0;
}
