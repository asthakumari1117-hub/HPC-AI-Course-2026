#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr=(int *)malloc(sizeof(int));

    *ptr=500;
    printf("value before free()=%d\n",*ptr);
     

    free(ptr);
    ptr=NULL;
    printf("Memory Released Successfully.\n");
    printf("pointer After free()=%p\n",ptr);
    return 0;
}