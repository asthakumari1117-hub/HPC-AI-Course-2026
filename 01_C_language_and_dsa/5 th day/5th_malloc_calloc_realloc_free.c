#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    ptr = (int*)malloc(3*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed.\n");
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        ptr[i]=(i+1)*100;
    }
    printf("After malloc():\n");
    for(int i=0;i<3;i++)
    {
        printf("%d\n",ptr);
    }
    printf("\n\n");

    ptr= (int *)realloc(ptr,5*sizeof(int));
    ptr[3]=400;
    ptr[4]=500;
    printf("After realloc():\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",ptr[i]);
    }
     printf("\n\n");
     free(ptr);
     ptr =NULL;
     printf("memory realeased Successfully.\n");
     return 0;
}