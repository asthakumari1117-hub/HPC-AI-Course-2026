#include<stdio.h>
int main()
{
    int arr[ ]= {5,10,15,20,25};
    int *ptr = arr;
    printf("array element : \n\n");
    for(int i=0;i<5;i++)
    {
        printf("%p\n",ptr);
        ptr++;
    }
    printf("\n");
}