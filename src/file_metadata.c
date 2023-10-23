#include "file_metadata.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

// Structure to hold file metadata
typedef struct {
    off_t size;
    time_t last_modified;
} FileMetadata;

// Function to collect file metadata
FileMetadata collect_file_metadata(const char *file_path) {
    struct stat file_stat;
    FileMetadata metadata;

    // Initialize to zero
    metadata.size = 0;
    metadata.last_modified = 0;

    if (stat(file_path, &file_stat) < 0) {
        perror("stat");
        return metadata;
    }

    metadata.size = file_stat.st_size; // File size in bytes
    metadata.last_modified = file_stat.st_mtime; // Last modification time

    return metadata;
}

// Function to print file metadata
void print_file_metadata(const FileMetadata *metadata) {
    printf("File Size: %lld bytes\n", (long long)metadata->size);

    // Convert time_t to human-readable format
    char buffer[30];
    struct tm *time_info = localtime(&metadata->last_modified);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);

    printf("Last Modified: %s\n", buffer);
}

// For testing
int main() {
    FileMetadata metadata = collect_file_metadata("test.txt");
    print_file_metadata(&metadata);
    return
