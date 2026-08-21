#include <stdio.h>

int main()
{
    // Comparison of all floating
    // point data types.

    float f = 123.456789f;
    double d = 123.456789123456789;
    long double ld = 123.45678912345678912345L;

    printf("Data Type\tStorage\tValue\n");
    printf("----------------------------------------------\n");

    printf("float\t\t%zu\t%.7f\n",
           sizeof(float), f);

    printf("double\t\t%zu\t%.15lf\n",
           sizeof(double), d);

    printf("long double\t%zu\t%.20Lf\n",
           sizeof(long double), ld);

    return 0;
}