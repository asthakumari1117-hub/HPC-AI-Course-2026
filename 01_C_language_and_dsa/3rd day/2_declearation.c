#include <stdio.h>

int main()
{
    // Elements are accessed
    // using row and column
    // indices.

    int matrix[2][3] =
    {
        {10,20,30},
        {40,50,60}
    };

    printf("matrix[0][0] = %d\n", matrix[0][0]);
    printf("matrix[0][2] = %d\n", matrix[0][2]);
    printf("matrix[1][1] = %d\n", matrix[1][1]);
    printf("matrix[1][2] = %d\n", matrix[1][2]);

    return 0;
}