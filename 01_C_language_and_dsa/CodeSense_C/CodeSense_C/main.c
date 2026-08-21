/*
=========================================================
File        : main.c
Project     : CodeSense C - Code Analyzer
Description : Main Driver Program
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "include/analyzer.h"
#include "include/report.h"
#include "include/utils.h"

int main()
{
    FILE *fp = NULL;
    char filename[260];

    int choice;

    while (1)
    {
        clear_screen();

        print_banner();

        print_menu();

        printf("\nEnter your choice : ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Input.\n");
            break;
        }

        getchar();     /* Remove newline */

        switch(choice)
        {

        case 1:

            if(fp != NULL)
            {
                close_file(fp);
                fp = NULL;
            }

            fp = load_file(filename);

            if(fp != NULL)
            {
                display_file(fp);
            }

            pause_screen();

            break;

        case 2:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_keywords(fp);

            pause_screen();

            break;

        case 3:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_identifiers(fp);

            pause_screen();

            break;

        case 4:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_operators(fp);

            pause_screen();

            break;

        case 5:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_constants(fp);

            pause_screen();

            break;

        case 6:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_functions(fp);

            pause_screen();

            break;

        case 7:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_strings(fp);

            pause_screen();

            break;

        case 8:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_memory(fp);

            pause_screen();

            break;

        case 9:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_brackets(fp);

            pause_screen();

            break;

        case 10:

            if(fp == NULL)
                printf("Load a file first.\n");
            else
                analyze_naming(fp);

            pause_screen();

            break;

        case 11:

            if(fp == NULL)
            {
                printf("Load a file first.\n");
            }
            else
            {
                printf("\nRunning Complete Analysis...\n\n");

                analyze_keywords(fp);
                analyze_identifiers(fp);
                analyze_operators(fp);
                analyze_constants(fp);
                analyze_functions(fp);
                analyze_strings(fp);
                analyze_memory(fp);
                analyze_brackets(fp);
                analyze_naming(fp);
            }

            pause_screen();

            break;

        case 12:

            if(fp == NULL)
            {
                printf("Load a file first.\n");
            }
            else
            {
                save_report(
                    filename,
                    count_lines(fp),
                    count_characters(fp),

                    0,      /* keywords */
                    0,      /* identifiers */
                    0,      /* operators */
                    0,      /* constants */
                    0,      /* functions */
                    0,      /* strings */
                    0,      /* memory */
                    0       /* syntax errors */
                );
            }

            pause_screen();

            break;

        case 0:

            if(fp != NULL)
                close_file(fp);

            printf("\nThank you for using CodeSense C.\n");

            return 0;

        default:

            printf("Invalid Choice.\n");

            pause_screen();

        }

    }

    return 0;
}