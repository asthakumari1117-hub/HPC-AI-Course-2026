/*
=========================================================
File        : function_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Function Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/analyzer.h"

#define MAX_FUNCTIONS 200
#define MAX_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    Function Structure
---------------------------------------------------------*/

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int count;
} Function;

Function functions[MAX_FUNCTIONS];
int functionCount = 0;

/*---------------------------------------------------------
    Check Existing Function
---------------------------------------------------------*/

int find_function(const char *name)
{
    for(int i = 0; i < functionCount; i++)
    {
        if(strcmp(functions[i].name, name) == 0)
            return i;
    }

    return -1;
}

/*---------------------------------------------------------
    Add Function
---------------------------------------------------------*/

void add_function(const char *name)
{
    int index = find_function(name);

    if(index != -1)
    {
        functions[index].count++;
        return;
    }

    strcpy(functions[functionCount].name, name);
    functions[functionCount].count = 1;
    functionCount++;
}

/*---------------------------------------------------------
    Analyze Functions
---------------------------------------------------------*/

void analyze_functions(FILE *fp)
{
    char line[MAX_LINE_LENGTH];

    functionCount = 0;

    rewind(fp);

    while(fgets(line, sizeof(line), fp))
    {
        int length = strlen(line);

        for(int i = 0; i < length; i++)
        {
            if(isalpha(line[i]) || line[i] == '_')
            {
                char word[MAX_NAME_LENGTH];
                int j = 0;
                int k = i;

                while(isalnum(line[k]) || line[k] == '_')
                {
                    word[j++] = line[k++];
                }

                word[j] = '\0';

                while(line[k] == ' ' || line[k] == '\t')
                    k++;

                if(line[k] == '(')
                {
                    add_function(word);
                }

                i = k;
            }
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                  FUNCTION ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("Total Unique Functions : %d\n\n", functionCount);

    printf("%-30s%s\n", "Function", "Occurrences");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < functionCount; i++)
    {
        printf("%-30s%d\n",
               functions[i].name,
               functions[i].count);
    }

    printf("\n=============================================================\n");

    rewind(fp);
}