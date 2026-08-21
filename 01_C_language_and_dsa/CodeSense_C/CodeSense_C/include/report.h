#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>

void generate_report_header(FILE *report,
                            const char *filename);

void generate_report_footer(FILE *report);

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
        int syntaxErrors);

#endif