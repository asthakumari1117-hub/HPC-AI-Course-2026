#include<stdio.h>
int main()
{
    int x =25;
    int *ptr= &x;
    
    printf(" X =  %d\n", x);
    printf(" Address of x  = %p\n",&x);
    printf(" pointer Value  = %p\n", ptr);
    printf("Dereferenced value   : %d\n", *ptr);
    return 0;
}