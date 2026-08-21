#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr=(int *)malloc(sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed.\n");
        return 0;
    }
    *ptr =500;
    printf("Allocated Value =%d\n", *ptr);
    printf("Memory adress =%p\n",ptr);

    free(ptr);
    printf("memory released suceessfully.\n");

    return 0;
}