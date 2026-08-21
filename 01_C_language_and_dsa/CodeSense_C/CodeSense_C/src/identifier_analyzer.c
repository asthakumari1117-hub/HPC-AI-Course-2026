/*
=========================================================
File        : identifier_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Identifier Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/analyzer.h"
#include "../include/tokenizer.h"

#define MAX_IDENTIFIERS 500
#define MAX_IDENTIFIER_LENGTH 100

/*---------------------------------------------------------
    Identifier Structure
---------------------------------------------------------*/

typedef struct
{
    char name[MAX_IDENTIFIER_LENGTH];
    int count;
} Identifier;

/*---------------------------------------------------------
    Analyze Identifiers
---------------------------------------------------------*/

void analyze_identifiers(FILE *fp)
{
    char word[MAX_IDENTIFIER_LENGTH];

    Identifier identifiers[MAX_IDENTIFIERS];

    int totalIdentifiers = 0;
    int uniqueIdentifiers = 0;

    rewind(fp);

    while (fscanf(fp, "%99s", word) == 1)
    {
        int length = strlen(word);

        /* Remove punctuation from beginning */
        while (length > 0 &&
              !isalnum(word[0]) &&
               word[0] != '_')
        {
            memmove(word, word + 1, strlen(word));
            length--;
        }

        /* Remove punctuation from end */
        while (length > 0 &&
              !isalnum(word[length - 1]) &&
               word[length - 1] != '_')
        {
            word[length - 1] = '\0';
            length--;
        }

        if (length == 0)
            continue;

        if (is_identifier(word))
        {
            totalIdentifiers++;

            int found = 0;

            for (int i = 0; i < uniqueIdentifiers; i++)
            {
                if (strcmp(identifiers[i].name, word) == 0)
                {
                    identifiers[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found && uniqueIdentifiers < MAX_IDENTIFIERS)
            {
                strcpy(identifiers[uniqueIdentifiers].name, word);
                identifiers[uniqueIdentifiers].count = 1;
                uniqueIdentifiers++;
            }
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                 IDENTIFIER ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("Total Identifiers  : %d\n", totalIdentifiers);
    printf("Unique Identifiers : %d\n\n", uniqueIdentifiers);

    printf("%-25s%s\n", "Identifier", "Occurrences");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < uniqueIdentifiers; i++)
    {
        printf("%-25s%d\n",
               identifiers[i].name,
               identifiers[i].count);
    }

    printf("\nDuplicate Identifiers\n");
    printf("-------------------------------------------------------------\n");

    int duplicates = 0;

    for (int i = 0; i < uniqueIdentifiers; i++)
    {
        if (identifiers[i].count > 1)
        {
            printf("%-25s%d\n",
                   identifiers[i].name,
                   identifiers[i].count);
            duplicates++;
        }
    }

    if (duplicates == 0)
    {
        printf("No duplicate identifiers found.\n");
    }

    printf("\n=============================================================\n");

    rewind(fp);
}