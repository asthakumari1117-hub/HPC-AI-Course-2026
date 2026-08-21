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

    ptr= (int *)realloc(ptr,40*sizeof(int));
    printf("After realloc():\n");
    printf("\n\n");
     printf("160 bytes of memory allocated successfully.\n");
    return 0;
}