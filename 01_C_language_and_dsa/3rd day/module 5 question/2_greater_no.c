#include<stdio.h>
int main()
{
     int num1;
    int num2;
    int num3;
     
    printf("\nEnter number 1\n");
    scanf("\n%d",&num1);
    printf("\nEnter number 2\n");
    scanf("\n%d",&num2);
    printf("\nEnter number 3\n");
    scanf("\n%d",&num3);

    if(num1>num2 && num1>num3)
    {
        printf("num1 is greater : %d",num1);
    }
    else if(num2>num1 && num2>num3)
    {
        printf("num2 is greater :%d",num2);
    }
    else 
    {
        printf("num3 is greateer : %d",num3);
    }
}