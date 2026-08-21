#include <stdio.h>

int main()
{
    // Mini Practical
    //
    // This program demonstrates:
    // 1. float
    // 2. double
    // 3. Arithmetic Operations
    // 4. Precision
    // 5. Formatted Output

    double number1 = 15.75;
    double number2 = 4.25;

    printf("Number 1 : %.2lf\n", number1);
    printf("Number 2 : %.2lf\n\n", number2);

    printf("Addition       : %.2lf\n", number1 + number2);
    printf("Subtraction    : %.2lf\n", number1 - number2);
    printf("Multiplication : %.2lf\n", number1 * number2);
    printf("Division       : %.4lf\n", number1 / number2);

    return 0;
}
