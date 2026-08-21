/*
=========================================================
File        : bracket_checker.c
Project     : CodeSense C - Code Analyzer
Description : Bracket Matching Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>

#include "../include/analyzer.h"

#define STACK_SIZE 1000

/*---------------------------------------------------------
    Stack Implementation
---------------------------------------------------------*/

typedef struct
{
    char bracket;
    int line;
} StackNode;

StackNode stack[STACK_SIZE];
int top = -1;

/*---------------------------------------------------------
    Stack Operations
---------------------------------------------------------*/

void push(char ch, int line)
{
    if(top < STACK_SIZE - 1)
    {
        top++;
        stack[top].bracket = ch;
        stack[top].line = line;
    }
}

StackNode pop()
{
    StackNode node = {'\0', -1};

    if(top >= 0)
    {
        node = stack[top];
        top--;
    }

    return node;
}

int is_empty()
{
    return (top == -1);
}

/*---------------------------------------------------------
    Matching Brackets
---------------------------------------------------------*/

int is_matching(char open, char close)
{
    return
        (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

/*---------------------------------------------------------
    Analyze Brackets
---------------------------------------------------------*/

void analyze_brackets(FILE *fp)
{
    int ch;
    int line = 1;

    int openRound = 0;
    int closeRound = 0;

    int openCurly = 0;
    int closeCurly = 0;

    int openSquare = 0;
    int closeSquare = 0;

    int errors = 0;

    top = -1;

    rewind(fp);

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            line++;

        switch(ch)
        {
            case '(':
                openRound++;
                push('(', line);
                break;

            case '{':
                openCurly++;
                push('{', line);
                break;

            case '[':
                openSquare++;
                push('[', line);
                break;

            case ')':
                closeRound++;

                if(is_empty())
                {
                    printf("Error : Unmatched ')' at line %d\n", line);
                    errors++;
                }
                else
                {
                    StackNode node = pop();

                    if(!is_matching(node.bracket, ')'))
                    {
                        printf("Error : Mismatched ')' at line %d\n", line);
                        errors++;
                    }
                }
                break;

            case '}':
                closeCurly++;

                if(is_empty())
                {
                    printf("Error : Unmatched '}' at line %d\n", line);
                    errors++;
                }
                else
                {
                    StackNode node = pop();

                    if(!is_matching(node.bracket, '}'))
                    {
                        printf("Error : Mismatched '}' at line %d\n", line);
                        errors++;
                    }
                }
                break;

            case ']':
                closeSquare++;

                if(is_empty())
                {
                    printf("Error : Unmatched ']' at line %d\n", line);
                    errors++;
                }
                else
                {
                    StackNode node = pop();

                    if(!is_matching(node.bracket, ']'))
                    {
                        printf("Error : Mismatched ']' at line %d\n", line);
                        errors++;
                    }
                }
                break;
        }
    }

    while(!is_empty())
    {
        StackNode node = pop();

        printf("Error : Missing closing bracket for '%c' opened at line %d\n",
               node.bracket,
               node.line);

        errors++;
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                 BRACKET ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("Round Brackets ()    : %d Opening, %d Closing\n",
           openRound,
           closeRound);

    printf("Curly Braces {}      : %d Opening, %d Closing\n",
           openCurly,
           closeCurly);

    printf("Square Brackets []   : %d Opening, %d Closing\n",
           openSquare,
           closeSquare);

    printf("\n");

    if(errors == 0)
    {
        printf("Bracket Status : All brackets are balanced.\n");
    }
    else
    {
        printf("Bracket Status : %d syntax error(s) found.\n", errors);
    }

    printf("\n=============================================================\n");

    rewind(fp);
}