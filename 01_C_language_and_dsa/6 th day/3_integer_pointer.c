#include<stdio.h>
int main()
{
    int age =25;
    int *ptr= &age;
    
    printf(" age =  %d\n", age);
    
    printf(" pointer Value  = %p\n", ptr);
    printf(" value through pointer  : %d\n", *ptr);
    *ptr=30;
    printf("\n updated age =%d\n",age);
    return 0;
}