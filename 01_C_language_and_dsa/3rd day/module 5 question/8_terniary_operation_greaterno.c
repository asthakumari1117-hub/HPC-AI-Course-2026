#include<stdio.h>
int main()
{
     int num1;
    int num2;
    int max;
     
    printf("\nEnter number 1\n");
    scanf("\n%d",&num1);
    printf("\nEnter number 2\n");
    scanf("\n%d",&num2);
   max = (num1 > num2) ? num1: num2;

    printf("Maximum number = %d", max);
    
}