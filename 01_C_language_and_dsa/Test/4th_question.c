#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        ptr[i] = (i + 1) * 100;
    }

    printf("\nAfter malloc():\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    
    ptr = (int *)calloc(n, sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
     for(int i = 0; i < n; i++)
    {
        ptr[i] = (i + 1) * 100;
    }

    printf("\n\nValues after calloc():\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    printf("\n\nMemory released successfully.\n");

    return 0;
}