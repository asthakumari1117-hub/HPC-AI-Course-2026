#include<stdio.h>
int main(){
    int number = 10;
    int *ptr = &number;

    printf("Legal Access = %d\n",*ptr);
    printf("\nExampleof illegal Access (Do not Execute):\n");
    // ptr = (int *)5000;
    printf("%d\n",*ptr);
    printf("illegal memmory access may crash the program.\n");
    return 0;

}