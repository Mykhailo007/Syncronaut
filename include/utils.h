#ifndef UTILS_H
#define UTILS_H

#include <stddef.h> // for size_t

// Function to concatenate two strings, allocating a new buffer for the result.
char* string_concat(const char *str1, const char *str2);

// Function to check if a filename has a specific extension.
int check_file_extension(const char *filename, const char *ext);

// Function to log errors.
void log_error(const char *message);

// Function to log informational messages.
void log_info(const char *message);

// Function to check if a string ends with a specific character.
int string_ends_with(const char *str, char c);

#endif // UTILS_H
