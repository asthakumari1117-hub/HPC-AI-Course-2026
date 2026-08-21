#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[50] = "CodeSense";
    char copy[50];

    strcpy(copy, name);

    printf("Original String : %s\n", name);
    printf("Copied String   : %s\n", copy);

    printf("Length : %lu\n", strlen(name));

    int *arr;

    arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}