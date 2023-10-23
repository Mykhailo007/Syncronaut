#include "../include/sync_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Concatenate two strings, allocating a new buffer for the result.
char* string_concat(const char *str1, const char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    if (result == NULL) {
        perror("Memory allocation failed for string_concat");
        exit(EXIT_FAILURE);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to check for file extension
int check_file_extension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) return 0;
    return (strcmp(dot, ext) == 0);
}

// Simple error logging function
void log_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

// Simple info logging function
void log_info(const char *message) {
    fprintf(stdout, "Info: %s\n", message);
}

// Function to check if a string ends with a specific character
int string_ends_with(const char *str, char c) {
    size_t length = strlen(str);
    return length > 0 && str[length - 1] == c;
}
