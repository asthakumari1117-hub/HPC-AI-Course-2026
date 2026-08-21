#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int addNumbers(int x, int y)
{
    return x + y;
}

int main()
{
    int numbers[MAX] = {10, 20, 30, 40, 50};
    int sum = 0;
    int i;

    char message[100] = "Welcome to CodeSense C";

    printf("%s\n", message);

    char copy[100];
    strcpy(copy, message);

    printf("Copied String : %s\n", copy);
    printf("Length : %lu\n", strlen(copy));

    int *dynamicArray;

    dynamicArray = (int *)malloc(MAX * sizeof(int));

    if (dynamicArray == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (i = 0; i < MAX; i++)
    {
        dynamicArray[i] = numbers[i];
        sum = addNumbers(sum, dynamicArray[i]);
    }

    printf("Sum = %d\n", sum);

    if (sum > 100)
    {
        printf("Large Sum\n");
    }
    else
    {
        printf("Small Sum\n");
    }

    free(dynamicArray);

    return 0;
}