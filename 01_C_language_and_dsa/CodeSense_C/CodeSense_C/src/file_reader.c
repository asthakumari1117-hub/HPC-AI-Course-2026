/*
=========================================================
File        : file_reader.c
Project     : CodeSense C - Code Analyzer
Description : File Reading Module
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>

#include "../include/utils.h"

#define MAX_FILENAME_LENGTH 260
#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    Function : load_file()
    Purpose  : Open a C source file for analysis
---------------------------------------------------------*/
FILE *load_file(char filename[])
{
    FILE *fp;

    printf("\nEnter C Source File Path : ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    /* Remove newline character */
    filename[strcspn(filename, "\n")] = '\0';

    if (!file_exists(filename))
    {
        printf("\nError : File does not exist.\n");
        return NULL;
    }

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("\nError : Unable to open the file.\n");
        return NULL;
    }

    printf("\nFile Loaded Successfully.\n");

    return fp;
}

/*---------------------------------------------------------
    Function : display_file()
    Purpose  : Display complete source code
---------------------------------------------------------*/
void display_file(FILE *fp)
{
    char line[MAX_LINE_LENGTH];

    printf("\n=============================================================\n");
    printf("                    SOURCE CODE PREVIEW\n");
    printf("=============================================================\n\n");

    rewind(fp);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    printf("\n=============================================================\n");

    rewind(fp);
}

/*---------------------------------------------------------
    Function : count_lines()
    Purpose  : Count total lines in source file
---------------------------------------------------------*/
int count_lines(FILE *fp)
{
    char line[MAX_LINE_LENGTH];
    int count = 0;

    rewind(fp);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    rewind(fp);

    return count;
}

/*---------------------------------------------------------
    Function : count_characters()
    Purpose  : Count total characters in source file
---------------------------------------------------------*/
int count_characters(FILE *fp)
{
    int count = 0;
    int ch;

    rewind(fp);

    while ((ch = fgetc(fp)) != EOF)
    {
        count++;
    }

    rewind(fp);

    return count;
}

/*---------------------------------------------------------
    Function : close_file()
    Purpose  : Close source file
---------------------------------------------------------*/
void close_file(FILE *fp)
{
    if (fp != NULL)
    {
        fclose(fp);
    }
}