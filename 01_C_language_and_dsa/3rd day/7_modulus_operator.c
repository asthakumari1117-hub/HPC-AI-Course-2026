#include<stdio.h>
int main()
{
   
    int a=29;
    int b=5;
    printf("value of a =%d\n",a);
    printf("value of b =%d\n",b);
    // printf("value of a =%.2f\n",a);
    // printf("value of b =%.2f\n",b);
    int remainder =a%b;
    // float result =a/b;

    printf("division : %d\n",remainder);
    return 0;
}