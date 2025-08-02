#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}

char* concatenate_strings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null-terminator

    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }

    return result;
}

char** tokenize_string(const char* str, const char* delimiter, int* token_count) {
    char* str_copy = strdup(str);
    char* token;
    char** tokens = NULL;
    *token_count = 0;

    token = strtok(str_copy, delimiter);
    while (token != NULL) {
        tokens = (char**)realloc(tokens, sizeof(char*) * (*token_count + 1));
        tokens[*token_count] = strdup(token);
        (*token_count)++;
        token = strtok(NULL, delimiter);
    }

    free(str_copy);
    return tokens;
}

void free_tokens(char** tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}