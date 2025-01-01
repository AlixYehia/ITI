#include <stdio.h>

// Function to calculate power using recursion
float power(float base, int exponent)
{
    if (exponent == 0)  /// Base case: any number to the power of 0 is 1
        return 1;

    else if (exponent > 0)  /// Positive exponent
        return base * power(base, exponent - 1);

    else  /// Negative exponent
        return 1 / power(base, -exponent);
}

int main() {
    float base;
    int exponent;
    float result;

    printf("Enter base: ");
    scanf("%f", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    result = power(base, exponent);

    printf("%f raised to the power of %d is %f\n", base, exponent, result);

    return 0;
}
