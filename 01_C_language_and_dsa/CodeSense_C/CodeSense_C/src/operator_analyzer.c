/*
=========================================================
File        : operator_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Operator Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>

#include "../include/analyzer.h"

#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    Operator Structure
---------------------------------------------------------*/

typedef struct
{
    const char *symbol;
    const char *category;
    int count;
} Operator;

/*---------------------------------------------------------
    List of Supported Operators
---------------------------------------------------------*/

Operator operators[] =
{
    {"+",   "Arithmetic", 0},
    {"-",   "Arithmetic", 0},
    {"*",   "Arithmetic", 0},
    {"/",   "Arithmetic", 0},
    {"%",   "Arithmetic", 0},

    {"++",  "Increment/Decrement", 0},
    {"--",  "Increment/Decrement", 0},

    {"=",   "Assignment", 0},
    {"+=",  "Assignment", 0},
    {"-=",  "Assignment", 0},
    {"*=",  "Assignment", 0},
    {"/=",  "Assignment", 0},
    {"%=",  "Assignment", 0},

    {"==",  "Relational", 0},
    {"!=",  "Relational", 0},
    {"<",   "Relational", 0},
    {">",   "Relational", 0},
    {"<=",  "Relational", 0},
    {">=",  "Relational", 0},

    {"&&",  "Logical", 0},
    {"||",  "Logical", 0},
    {"!",   "Logical", 0},

    {"&",   "Bitwise", 0},
    {"|",   "Bitwise", 0},
    {"^",   "Bitwise", 0},
    {"~",   "Bitwise", 0},
    {"<<",  "Bitwise", 0},
    {">>",  "Bitwise", 0},

    {"?",   "Conditional", 0},
    {":",   "Conditional", 0}
};

#define TOTAL_OPERATORS (sizeof(operators)/sizeof(operators[0]))

/*---------------------------------------------------------
    Analyze Operators
---------------------------------------------------------*/

void analyze_operators(FILE *fp)
{
    char line[MAX_LINE_LENGTH];

    rewind(fp);

    /* Reset previous counts */
    for(int i = 0; i < TOTAL_OPERATORS; i++)
    {
        operators[i].count = 0;
    }

    while(fgets(line, sizeof(line), fp))
    {
        for(int i = 0; i < TOTAL_OPERATORS; i++)
        {
            char *ptr = line;

            while((ptr = strstr(ptr, operators[i].symbol)) != NULL)
            {
                operators[i].count++;
                ptr += strlen(operators[i].symbol);
            }
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                 OPERATOR ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("%-8s %-25s %s\n",
           "Operator",
           "Category",
           "Count");

    printf("-------------------------------------------------------------\n");

    int total = 0;

    for(int i = 0; i < TOTAL_OPERATORS; i++)
    {
        if(operators[i].count > 0)
        {
            printf("%-8s %-25s %d\n",
                   operators[i].symbol,
                   operators[i].category,
                   operators[i].count);

            total += operators[i].count;
        }
    }

    printf("\n-------------------------------------------------------------\n");
    printf("Total Operators : %d\n", total);

    printf("=============================================================\n");

    rewind(fp);
}