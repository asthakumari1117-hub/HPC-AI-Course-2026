#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>

/*---------------------------------------------------------
    Main Analysis
---------------------------------------------------------*/
void analyze_file(const char *filename);

/*---------------------------------------------------------
    File Reader Functions
---------------------------------------------------------*/
FILE *load_file(char filename[]);
void display_file(FILE *fp);
int count_lines(FILE *fp);
int count_characters(FILE *fp);
void close_file(FILE *fp);

/*---------------------------------------------------------
    Analysis Modules
---------------------------------------------------------*/
void analyze_keywords(FILE *fp);
void analyze_identifiers(FILE *fp);
void analyze_operators(FILE *fp);
void analyze_constants(FILE *fp);
void analyze_functions(FILE *fp);
void analyze_strings(FILE *fp);
void analyze_memory(FILE *fp);
void analyze_brackets(FILE *fp);
void analyze_naming(FILE *fp);

#endif /* ANALYZER_H */