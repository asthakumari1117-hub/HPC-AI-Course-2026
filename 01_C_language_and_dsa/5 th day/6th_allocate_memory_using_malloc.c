#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    ptr = (int*)malloc(30*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed.\n");
    }
    else
    {
        printf("120 bytes of memory allocated successfully.\n");
        free(ptr);   // Free the allocated memory
    }
    return 0;
}