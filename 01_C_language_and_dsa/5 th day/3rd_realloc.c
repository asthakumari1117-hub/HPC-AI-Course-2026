#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr=(int *)malloc(3*sizeof(int));
    for(int i=0;i<3;i++)
    {
        ptr[i] = (i+1)*10;
    }
    ptr=(int *)realloc(ptr,5*sizeof(int));
    ptr[3]=40;
    ptr[4]=50;

    printf("Array after realloc():\n\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",ptr[i]);
    }

    printf("\n");

    free(ptr);
   

    return 0;
}