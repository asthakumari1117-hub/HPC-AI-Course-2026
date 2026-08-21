#include <stdio.h>

int main()
{
    // Floating point numbers cannot
    // represent every decimal value exactly.
    //
    // This happens because decimal values
    // are stored in binary format.

    float a = 0.1f;
    float b = 0.2f;
    float sum = a + b;

    printf("a   = %.20f\n", a);
    printf("b   = %.20f\n", b);
    printf("Sum = %.20f\n", sum);

    // Notice that the result may not be
    // exactly 0.30000000000000000000.

    return 0;
}