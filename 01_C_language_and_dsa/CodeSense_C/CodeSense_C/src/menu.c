/*
=========================================================
File        : menu.c
Project     : CodeSense C - Code Analyzer
Description : Menu Handling Module
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include "../include/utils.h"

void print_menu()
{
    printf("\n");
    printf("=============================================================\n");
    printf("               CodeSense C - Code Analyzer\n");
    printf("=============================================================\n");

    printf(" 1. Load C File\n");
    printf(" 2. Analyze Keywords\n");
    printf(" 3. Analyze Identifiers\n");
    printf(" 4. Analyze Operators\n");
    printf(" 5. Analyze Constants\n");
    printf(" 6. Analyze Functions\n");
    printf(" 7. Analyze Strings\n");
    printf(" 8. Analyze Memory Usage\n");
    printf(" 9. Check Brackets\n");
    printf("10. Naming Convention Check\n");
    printf("11. Complete Code Analysis\n");
    printf("12. Generate Report\n");

    printf("\n");

    printf(" 0. Exit\n");

    printf("=============================================================\n");
}