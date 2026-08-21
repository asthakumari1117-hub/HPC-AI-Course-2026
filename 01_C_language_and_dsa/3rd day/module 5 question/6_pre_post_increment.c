#include <stdio.h>

int main()
{
    int a = 10, b = 10;

    printf("Initial value of a = %d\n", a);
    printf("Initial value of b = %d\n", b);

    printf("\nUsing Pre-increment (++a)\n");
    printf("Value = %d\n", ++a);
    printf("Current value of a = %d\n", a);

    printf("\nUsing Post-increment (b++)\n");
    printf("Value = %d\n", b++);
    printf("Current value of b = %d\n", b);

    return 0;
}