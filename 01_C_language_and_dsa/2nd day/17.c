#include <stdio.h>
#include <float.h>
int main()
{
    // <float.h> provides information
    // about floating point limits.

    printf("Range of Floating Point Data Types\n\n");

    printf("float\n");
    printf("Minimum Positive : %e\n", FLT_MIN);
    printf("Maximum          : %e\n\n", FLT_MAX);

    printf("double\n");
    printf("Minimum Positive : %e\n", DBL_MIN);
    printf("Maximum          : %e\n\n", DBL_MAX);

    printf("long double\n");
    printf("Minimum Positive : %Le\n", LDBL_MIN);
    printf("Maximum          : %Le\n", LDBL_MAX);

    return 0;
}