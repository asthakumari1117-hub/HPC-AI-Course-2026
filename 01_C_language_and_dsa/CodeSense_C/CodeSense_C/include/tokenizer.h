#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_TOKEN_LENGTH 100
#define MAX_LINE_LENGTH 1024

int is_keyword(const char *word);

int is_identifier(const char *word);

int is_constant(const char *word);

int is_operator(const char *word);

void tokenize_file(const char *filename);

#endif