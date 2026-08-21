#include<stdio.h>
#define SIZE 5

int main()
{
    int stack[SIZE];
    int top=-1;
    stack[++top]=10;
    stack[++top]=20;
    stack[++top]=30;
    stack[++top]=40;


    printf("stack after push : \n");
    for (int i=top;i>=0;i--)
    {
        printf("|%d\n",stack[i]);
    }
    printf("Initial Top=%d\n",top);
    return 0;
}