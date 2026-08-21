#include<stdio.h>
int main()
{
    int number =50;
    int *ptr;
    ptr =&number;
    printf("value of number : %d\n", number);
    printf("Address stored in pointer : %p\n", ptr);
    printf("value using pointer : %d\n", *ptr);
}