/*
=========================================================
File        : report_generator.c
Project     : CodeSense C - Code Analyzer
Description : Report Generator
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <time.h>

#include "../include/report.h"

/*---------------------------------------------------------
    Generate Report Header
---------------------------------------------------------*/

void generate_report_header(FILE *report, const char *filename)
{
    time_t now;
    time(&now);

    fprintf(report,
    "=============================================================\n");
    fprintf(report,
    "                CodeSense C Analysis Report\n");
    fprintf(report,
    "=============================================================\n");

    fprintf(report,"Source File : %s\n", filename);
    fprintf(report,"Generated On: %s", ctime(&now));

    fprintf(report,
    "=============================================================\n\n");
}

/*---------------------------------------------------------
    Generate Report Footer
---------------------------------------------------------*/

void generate_report_footer(FILE *report)
{
    fprintf(report,"\n");
    fprintf(report,
    "=============================================================\n");
    fprintf(report,
    "            End of Code Analysis Report\n");
    fprintf(report,
    "=============================================================\n");
}

/*---------------------------------------------------------
    Save Complete Report
---------------------------------------------------------*/

void save_report(
        const char *sourceFile,
        int totalLines,
        int totalCharacters,
        int keywords,
        int identifiers,
        int operators,
        int constants,
        int functions,
        int stringLiterals,
        int memoryFunctions,
        int syntaxErrors)
{
    FILE *report;

    report = fopen("reports/analysis_report.txt","w");

    if(report==NULL)
    {
        printf("\nUnable to create report.\n");
        return;
    }

    generate_report_header(report, sourceFile);

    fprintf(report,"GENERAL INFORMATION\n");
    fprintf(report,
    "-------------------------------------------------------------\n");

    fprintf(report,"Total Lines               : %d\n", totalLines);
    fprintf(report,"Total Characters          : %d\n\n", totalCharacters);

    fprintf(report,"LEXICAL ANALYSIS\n");
    fprintf(report,
    "-------------------------------------------------------------\n");

    fprintf(report,"Keywords                  : %d\n", keywords);
    fprintf(report,"Identifiers               : %d\n", identifiers);
    fprintf(report,"Operators                 : %d\n", operators);
    fprintf(report,"Constants                 : %d\n", constants);
    fprintf(report,"Functions                 : %d\n", functions);

    fprintf(report,"\nSTRING ANALYSIS\n");
    fprintf(report,
    "-------------------------------------------------------------\n");

    fprintf(report,"String Literals           : %d\n",
            stringLiterals);

    fprintf(report,"\nMEMORY ANALYSIS\n");
    fprintf(report,
    "-------------------------------------------------------------\n");

    fprintf(report,"Memory Functions          : %d\n",
            memoryFunctions);

    fprintf(report,"\nSYNTAX ANALYSIS\n");
    fprintf(report,
    "-------------------------------------------------------------\n");

    fprintf(report,"Bracket Errors            : %d\n",
            syntaxErrors);

    generate_report_footer(report);

    fclose(report);

    printf("\n");
    printf("=============================================================\n");
    printf("Report Successfully Generated.\n");
    printf("Location : reports/analysis_report.txt\n");
    printf("=============================================================\n");
}