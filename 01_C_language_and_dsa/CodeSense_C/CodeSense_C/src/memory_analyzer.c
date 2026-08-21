/*
=========================================================
File        : memory_analyzer.c
Project     : CodeSense C - Code Analyzer
Description : Memory Analyzer
Author      : Himanshu Rajak
=========================================================
*/

#include <stdio.h>
#include <string.h>

#include "../include/analyzer.h"

#define MAX_LINE_LENGTH 1024

/*---------------------------------------------------------
    Memory Function Structure
---------------------------------------------------------*/

typedef struct
{
    const char *name;
    int count;
} MemoryFunction;

/*---------------------------------------------------------
    Memory Functions
---------------------------------------------------------*/

MemoryFunction memoryFunctions[] =
{
    {"malloc",0},
    {"calloc",0},
    {"realloc",0},
    {"free",0},
    {"memcpy",0},
    {"memmove",0},
    {"memset",0},
    {"memcmp",0}
};

#define TOTAL_MEMORY_FUNCTIONS \
(sizeof(memoryFunctions)/sizeof(memoryFunctions[0]))

/*---------------------------------------------------------
    Analyze Memory Functions
---------------------------------------------------------*/

void analyze_memory(FILE *fp)
{
    char line[MAX_LINE_LENGTH];

    int allocationCalls = 0;
    int freeCalls = 0;

    /* Reset counts */

    for(int i=0;i<TOTAL_MEMORY_FUNCTIONS;i++)
        memoryFunctions[i].count = 0;

    rewind(fp);

    while(fgets(line,sizeof(line),fp))
    {
        for(int i=0;i<TOTAL_MEMORY_FUNCTIONS;i++)
        {
            char *ptr = line;

            while((ptr = strstr(ptr,memoryFunctions[i].name)) != NULL)
            {
                memoryFunctions[i].count++;

                if(strcmp(memoryFunctions[i].name,"malloc")==0)
                    allocationCalls++;

                else if(strcmp(memoryFunctions[i].name,"calloc")==0)
                    allocationCalls++;

                else if(strcmp(memoryFunctions[i].name,"realloc")==0)
                    allocationCalls++;

                else if(strcmp(memoryFunctions[i].name,"free")==0)
                    freeCalls++;

                ptr += strlen(memoryFunctions[i].name);
            }
        }
    }

    printf("\n");
    printf("=============================================================\n");
    printf("                  MEMORY ANALYSIS REPORT\n");
    printf("=============================================================\n\n");

    printf("%-20s%s\n","Memory Function","Count");
    printf("-------------------------------------------------------------\n");

    for(int i=0;i<TOTAL_MEMORY_FUNCTIONS;i++)
    {
        if(memoryFunctions[i].count>0)
        {
            printf("%-20s%d\n",
                    memoryFunctions[i].name,
                    memoryFunctions[i].count);
        }
    }

    printf("\n-------------------------------------------------------------\n");

    printf("Allocation Calls : %d\n",allocationCalls);
    printf("Free Calls       : %d\n",freeCalls);

    if(allocationCalls==freeCalls)
    {
        printf("\nMemory Leak Status : No obvious leak detected.\n");
    }
    else if(allocationCalls>freeCalls)
    {
        printf("\nMemory Leak Status : Possible Memory Leak Detected!\n");
        printf("Reason             : Allocation > Free\n");
    }
    else
    {
        printf("\nMemory Leak Status : Extra free() detected.\n");
    }

    printf("\n=============================================================\n");

    rewind(fp);
}