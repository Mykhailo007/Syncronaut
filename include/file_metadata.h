#ifndef FILE_METADATA_H
#define FILE_METADATA_H

#include <sys/types.h>
#include <time.h>

// Structure to hold file metadata
typedef struct {
    off_t size;
    time_t last_modified;
} FileMetadata;

// Function declarations
FileMetadata collect_file_metadata(const char *file_path);
void print_file_metadata(const FileMetadata *metadata);

#endif // FILE_METADATA_H
