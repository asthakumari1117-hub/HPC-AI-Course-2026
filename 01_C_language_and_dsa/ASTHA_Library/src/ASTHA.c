#include <stdio.h>
#include "../include/ASTHA.h"

void ASTHA_banner()
{
    printf("=====================================================\n");
    printf("           ASTHA STANDARD LIBRARY v1.0\n");
    printf("         Developed by ASTHA KUMARI\n");
    printf("=====================================================\n");
}

void ASTHA_line()
{
    printf("-----------------------------------------------------\n");
}

void ASTHA_version()
{
    printf("Library Version : 1.0\n");
}

void ASTHA_success(const char *message)
{
    printf("[SUCCESS] %s\n", message);
}

int ASTHA_add(int a, int b)
{
    return a + b;
}
