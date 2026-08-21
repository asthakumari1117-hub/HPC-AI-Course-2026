#include<stdio.h>
int main()
{
    int arr[]={10,20,30,40,50};
    int*ptr=arr;
    printf("initial address :%p\n",ptr);
    printf("initial value : %d\n\n",*ptr);
    ptr++;
    printf("After ptr++ \n");
    printf("address : %p\n",ptr);
    printf("value : %d\n",*ptr);
    return 0;
}