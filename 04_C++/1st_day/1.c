#include<stdio.h>

void add()
    {
         static int sum;
       static int a=10;
       static int b=20;
        sum=a+b;
        printf("SUM = %d",sum);
        a++;
    }

    int main()
    {
        add();
        add();
        add();
    }