/*
=========================================================
File        : string_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : String Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>

#include "../include/analyzer.h"

#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    String Functions to Analyze
---------------------------------------------------------*/

typedef struct
{
    const char *name;
    int count;
} StringFunction;

StringFunction stringFunctions[] =
{
    {"strlen",0},
    {"strcpy",0},
    {"strncpy",0},
    {"strcat",0},
    {"strncat",0},
    {"strcmp",0},
    {"strncmp",0},
    {"strchr",0},
    {"strrchr",0},
    {"strstr",0},
    {"strtok",0},
    {"sprintf",0},
    {"snprintf",0},
    {"sscanf",0},
    {"fgets",0},
    {"puts",0},
    {"gets",0}
};

#define TOTAL_FUNCTIONS (sizeof(stringFunctions)/sizeof(stringFunctions[0]))

/*---------------------------------------------------------
    Analyze Strings
---------------------------------------------------------*/

void analyze_strings(FILE *fp)
{
    char line[MAX_LINE_LENGTH];

    int stringLiteralCount = 0;
    int totalCharacters = 0;

    /* Reset counts */
    for(int i=0;i<TOTAL_FUNCTIONS;i++)
        stringFunctions[i].count = 0;

    rewind(fp);

    while(fgets(line,sizeof(line),fp))
    {
        /*-----------------------------------------
            Count String Literals
        ------------------------------------------*/

        char *start = line;

        while((start = strchr(start,'"')) != NULL)
        {
            char *end = strchr(start+1,'"');

            if(end != NULL)
            {
                stringLiteralCount++;

                totalCharacters += (int)(end-start-1);

                start = end + 1;
            }
            else
            {
                break;
            }
        }

        /*-----------------------------------------
            Count String Functions
        ------------------------------------------*/

        for(int i=0;i<TOTAL_FUNCTIONS;i++)
        {
            char *ptr = line;

            while((ptr = strstr(ptr,stringFunctions[i].name)) != NULL)
            {
                stringFunctions[i].count++;
                ptr += strlen(stringFunctions[i].name);
            }
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                  STRING ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("Total String Literals : %d\n", stringLiteralCount);
    printf("Total String Characters : %d\n\n", totalCharacters);

    printf("%-20s%s\n","Function","Count");
    printf("-------------------------------------------------------------\n");

    int totalUsage = 0;

    for(int i=0;i<TOTAL_FUNCTIONS;i++)
    {
        if(stringFunctions[i].count>0)
        {
            printf("%-20s%d\n",
                   stringFunctions[i].name,
                   stringFunctions[i].count);

            totalUsage += stringFunctions[i].count;
        }
    }

    printf("\n-------------------------------------------------------------\n");
    printf("Total String Function Calls : %d\n", totalUsage);

    printf("=============================================================\n");

    rewind(fp);
}