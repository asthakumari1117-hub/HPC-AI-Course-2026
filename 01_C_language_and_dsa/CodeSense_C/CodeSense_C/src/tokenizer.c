/*
=========================================================
File        : tokenizer.c
Project     : CodeSense C - Code Analyzer
Description : Lexical Tokenizer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/tokenizer.h"

#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    C Keywords
---------------------------------------------------------*/

static const char *keywords[] =
{
    "auto","break","case","char","const","continue",
    "default","do","double","else","enum","extern",
    "float","for","goto","if","int","long",
    "register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

#define KEYWORD_COUNT (sizeof(keywords)/sizeof(keywords[0]))

/*---------------------------------------------------------
    Check Keyword
---------------------------------------------------------*/

int is_keyword(const char *word)
{
    int i;

    for(i=0;i<KEYWORD_COUNT;i++)
    {
        if(strcmp(word,keywords[i])==0)
            return 1;
    }

    return 0;
}

/*---------------------------------------------------------
    Check Identifier
---------------------------------------------------------*/

int is_identifier(const char *word)
{
    int i;

    if(!(isalpha(word[0]) || word[0]=='_'))
        return 0;

    for(i=1;word[i]!='\0';i++)
    {
        if(!(isalnum(word[i]) || word[i]=='_'))
            return 0;
    }

    if(is_keyword(word))
        return 0;

    return 1;
}

/*---------------------------------------------------------
    Check Integer Constant
---------------------------------------------------------*/

int is_constant(const char *word)
{
    int i;

    if(word[0]=='\0')
        return 0;

    for(i=0;word[i]!='\0';i++)
    {
        if(!isdigit(word[i]))
            return 0;
    }

    return 1;
}

/*---------------------------------------------------------
    Check Operator
---------------------------------------------------------*/

int is_operator(const char *word)
{
    const char *operators[] =
    {
        "+","-","*","/","%",
        "=","==","!=",
        "<",">","<=",">=",
        "&&","||","!",
        "&","|","^","~",
        "<<",">>",
        "+=","-=","*=","/=","%=",
        "++","--",
        "?",
        ":"
    };

    int total =
    sizeof(operators)/sizeof(operators[0]);

    int i;

    for(i=0;i<total;i++)
    {
        if(strcmp(word,operators[i])==0)
            return 1;
    }

    return 0;
}

/*---------------------------------------------------------
    Tokenize File
---------------------------------------------------------*/

void tokenize_file(const char *filename)
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    printf("\n==================================================\n");
    printf("               TOKEN LIST\n");
    printf("==================================================\n\n");

    while(fgets(line,sizeof(line),fp))
    {
        char *token;

        token=strtok(line,
        " \t\n(){}[];,\"");

        while(token!=NULL)
        {

            if(is_keyword(token))
            {
                printf("[KEYWORD]     %s\n",token);
            }

            else if(is_identifier(token))
            {
                printf("[IDENTIFIER]  %s\n",token);
            }

            else if(is_constant(token))
            {
                printf("[CONSTANT]    %s\n",token);
            }

            else if(is_operator(token))
            {
                printf("[OPERATOR]    %s\n",token);
            }

            else
            {
                printf("[UNKNOWN]     %s\n",token);
            }

            token=strtok(NULL,
            " \t\n(){}[];,\"");
        }

    }

    fclose(fp);
}