/*
=========================================================
File        : naming_checker.c
Project     : CodeSense C - Code Analyzer
Description : Identifier Naming Convention Checker
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/analyzer.h"
#include "../include/tokenizer.h"

#define MAX_IDENTIFIERS 500
#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
} Identifier;

Identifier identifiers[MAX_IDENTIFIERS];
int identifierCount = 0;

/*---------------------------------------------------------
    Check Duplicate Identifier
---------------------------------------------------------*/

int identifier_exists(const char *name)
{
    for(int i = 0; i < identifierCount; i++)
    {
        if(strcmp(name, identifiers[i].name) == 0)
            return 1;
    }

    return 0;
}

/*---------------------------------------------------------
    Add Identifier
---------------------------------------------------------*/

void add_identifier(const char *name)
{
    if(identifier_exists(name))
        return;

    strcpy(identifiers[identifierCount].name, name);
    identifierCount++;
}

/*---------------------------------------------------------
    Check Naming Convention
---------------------------------------------------------*/

void check_identifier(const char *name)
{
    int length = strlen(name);

    printf("%-25s", name);

    /* Single character variable */

    if(length == 1)
    {
        printf("Warning : Too short\n");
        return;
    }

    /* Starts with uppercase */

    if(isupper(name[0]))
    {
        printf("Suggestion : PascalCase (Usually for structures/types)\n");
        return;
    }

    /* Contains underscore */

    if(strchr(name, '_') != NULL)
    {
        printf("Style : snake_case\n");
        return;
    }

    /* Starts lowercase */

    if(islower(name[0]))
    {
        printf("Style : camelCase\n");
        return;
    }

    printf("Unknown Style\n");
}

/*---------------------------------------------------------
    Analyze Naming Conventions
---------------------------------------------------------*/

void analyze_naming(FILE *fp)
{
    char word[100];

    identifierCount = 0;

    rewind(fp);

    while(fscanf(fp, "%99s", word) == 1)
    {
        int length = strlen(word);

        while(length > 0 &&
             !isalnum(word[0]) &&
             word[0] != '_')
        {
            memmove(word, word + 1, strlen(word));
            length--;
        }

        while(length > 0 &&
             !isalnum(word[length - 1]) &&
             word[length - 1] != '_')
        {
            word[length - 1] = '\0';
            length--;
        }

        if(length == 0)
            continue;

        if(is_identifier(word))
        {
            add_identifier(word);
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("             IDENTIFIER NAMING CONVENTION REPORT\n");
    printf("=============================================================\n\n");

    printf("%-25s%s\n",
           "Identifier",
           "Convention");

    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < identifierCount; i++)
    {
        check_identifier(identifiers[i].name);
    }

    printf("\n=============================================================\n");

    rewind(fp);
}