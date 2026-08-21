/*
=========================================================
File        : utils.c
Project     : CodeSense C - Code Analyzer
Description : Utility Functions
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "../include/utils.h"

/*-------------------------------------------------------
  Clear Console Screen
-------------------------------------------------------*/
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*-------------------------------------------------------
  Pause Screen
-------------------------------------------------------*/
void pause_screen()
{
    printf("\nPress ENTER to continue...");
    getchar();
}

/*-------------------------------------------------------
  Display Project Banner
-------------------------------------------------------*/
void print_banner()
{
    printf("=============================================================\n");
    printf("               CodeSense C - Code Analyzer\n");
    printf("=============================================================\n");
    printf("      Analyze C Programs Like a Professional Tool\n");
    printf("=============================================================\n\n");
}

/*-------------------------------------------------------
  Check Whether File Exists
-------------------------------------------------------*/
int file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        return 0;

    fclose(fp);
    return 1;
}