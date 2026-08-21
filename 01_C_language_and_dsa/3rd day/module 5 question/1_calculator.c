//Create a calculator using arithmetic operators.
#include<stdio.h>
int main()
{
    int num1;
    int num2;
    printf("Calculator.......");
    printf("\nEnter number 1\n");
    scanf("\n%d",&num1);
    printf("\nEnter number 2\n");
    scanf("\n%d",&num2);

    printf("ADD : %d\n",num1+num2);
    printf("SUBTRACTION : %d\n",num1-num2);
    printf("Multiplication: %d\n",num1*num2);
    printf("Divide : %d\n",num1/num2);
    return 0;
}