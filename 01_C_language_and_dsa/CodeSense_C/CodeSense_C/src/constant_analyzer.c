/*
=========================================================
File        : constant_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Constant Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/analyzer.h"

#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    Check Integer Constant
---------------------------------------------------------*/
int isInteger(const char *token)
{
    if(token == NULL || *token == '\0')
        return 0;

    int i = 0;

    if(token[0]=='-' || token[0]=='+')
        i++;

    for(; token[i]; i++)
    {
        if(!isdigit(token[i]))
            return 0;
    }

    return 1;
}

/*---------------------------------------------------------
    Check Floating Constant
---------------------------------------------------------*/
int isFloat(const char *token)
{
    int dot = 0;
    int digit = 0;
    int i = 0;

    if(token[0]=='-' || token[0]=='+')
        i++;

    for(; token[i]; i++)
    {
        if(isdigit(token[i]))
        {
            digit = 1;
        }
        else if(token[i]=='.')
        {
            dot++;
        }
        else
        {
            return 0;
        }
    }

    return (digit && dot==1);
}

/*---------------------------------------------------------
    Check Character Constant
---------------------------------------------------------*/
int isCharacter(const char *token)
{
    int len = strlen(token);

    if(len==3 &&
       token[0]=='\'' &&
       token[2]=='\'')
        return 1;

    return 0;
}

/*---------------------------------------------------------
    Check String Constant
---------------------------------------------------------*/
int isString(const char *token)
{
    int len = strlen(token);

    if(len>=2 &&
       token[0]=='\"' &&
       token[len-1]=='\"')
        return 1;

    return 0;
}

/*---------------------------------------------------------
    Check Hexadecimal Constant
---------------------------------------------------------*/
int isHexadecimal(const char *token)
{
    if(strlen(token)<3)
        return 0;

    if(token[0]=='0' &&
      (token[1]=='x' || token[1]=='X'))
    {
        for(int i=2; token[i]; i++)
        {
            if(!isxdigit(token[i]))
                return 0;
        }
        return 1;
    }

    return 0;
}

/*---------------------------------------------------------
    Check Octal Constant
---------------------------------------------------------*/
int isOctal(const char *token)
{
    if(token[0]!='0')
        return 0;

    for(int i=1; token[i]; i++)
    {
        if(token[i]<'0' || token[i]>'7')
            return 0;
    }

    return 1;
}

/*---------------------------------------------------------
    Analyze Constants
---------------------------------------------------------*/
void analyze_constants(FILE *fp)
{
    char token[256];

    int integers = 0;
    int floating = 0;
    int characters = 0;
    int strings = 0;
    int hexadecimal = 0;
    int octal = 0;

    rewind(fp);

    while(fscanf(fp,"%255s",token)==1)
    {
        if(isHexadecimal(token))
            hexadecimal++;

        else if(isOctal(token))
            octal++;

        else if(isInteger(token))
            integers++;

        else if(isFloat(token))
            floating++;

        else if(isCharacter(token))
            characters++;

        else if(isString(token))
            strings++;
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                 CONSTANT ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("Integer Constants      : %d\n", integers);
    printf("Floating Constants     : %d\n", floating);
    printf("Character Constants    : %d\n", characters);
    printf("String Constants       : %d\n", strings);
    printf("Hexadecimal Constants  : %d\n", hexadecimal);
    printf("Octal Constants        : %d\n", octal);

    printf("\n=============================================================\n");

    rewind(fp);
}