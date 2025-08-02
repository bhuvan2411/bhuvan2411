#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

// Function to trim whitespace from the beginning and end of a string
char* trim_whitespace(char* str);

// Function to concatenate two strings
char* concat_strings(const char* str1, const char* str2);

// Function to split a string into tokens based on a delimiter
char** tokenize_string(const char* str, const char* delimiter, size_t* token_count);

// Function to free the memory allocated for tokens
void free_tokens(char** tokens, size_t token_count);

#endif // STRING_UTILS_H