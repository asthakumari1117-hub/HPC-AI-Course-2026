#include<stdio.h>
int main()
{
     int num1;
    
    printf("\nEnter number 1\n");
    scanf("\n%d",&num1);
    
    if(num1%2==0)
    {
        printf(" %d is  Even no",num1);
    }
    else 
    {
        printf("%d id odd",num1);
    }
}