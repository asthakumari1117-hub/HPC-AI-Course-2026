/*
=========================================================
File        : keyword_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Keyword Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/analyzer.h"

#define MAX_WORD_LENGTH 100

/*---------------------------------------------------------
    C Keywords
---------------------------------------------------------*/

const char *keywords[] =
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
    Analyze Keywords
---------------------------------------------------------*/

void analyze_keywords(FILE *fp)
{
    char word[MAX_WORD_LENGTH];
    int totalKeywords = 0;
    int keywordFrequency[KEYWORD_COUNT] = {0};

    rewind(fp);

    while(fscanf(fp,"%99s",word)==1)
    {
        int i;

        /* Remove punctuation */

        int length = strlen(word);

        while(length>0 &&
             !isalnum(word[length-1]) &&
             word[length-1]!='_')
        {
            word[length-1]='\0';
            length--;
        }

        for(i=0;i<KEYWORD_COUNT;i++)
        {
            if(strcmp(word,keywords[i])==0)
            {
                keywordFrequency[i]++;
                totalKeywords++;
                break;
            }
        }
    }

    printf("\n");
    printf("=====================================================\n");
    printf("               KEYWORD ANALYSIS REPORT\n");
    printf("=====================================================\n\n");

    printf("Total Keywords : %d\n\n",totalKeywords);

    printf("%-20s%s\n","Keyword","Count");
    printf("--------------------------------------\n");

    int i;

    for(i=0;i<KEYWORD_COUNT;i++)
    {
        if(keywordFrequency[i]>0)
        {
            printf("%-20s%d\n",
                   keywords[i],
                   keywordFrequency[i]);
        }
    }

    printf("\n=====================================================\n");

    rewind(fp);
}