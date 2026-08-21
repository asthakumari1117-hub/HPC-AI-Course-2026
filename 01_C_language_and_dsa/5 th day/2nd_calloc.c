#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr=(int *)calloc(5,sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed.\n");
        return 0;
    }

    printf("values after calloc():\n\n");

    for(int i=0;i<5;i++)
    {
        printf("%d",ptr[i]);
    }
    printf("\n");

    free(ptr);
   

    return 0;
}