#include "../include/file_metadata.h" 
#include "../include/file_operations.h" 
#include "../include/sync_logic.h"
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Two-way synchronization between two directories
void two_way_sync(const char *dir1, const char *dir2) {
    // Open the directories
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);
    struct dirent *entry1, *entry2;

    if (d1 == NULL || d2 == NULL) {
        printf("Failed to open one or both directories.\n");
        return;
    }

    // TODO: Implement actual sync logic here.
    // For demonstration, let's say we're just copying new files from dir1 to dir2 and vice versa
    // and deleting files that don't exist in the other directory.
    while ((entry1 = readdir(d1)) != NULL) {
        char src_path[512], dest_path[512];

        // Construct full path for source and destination
        snprintf(src_path, sizeof(src_path), "%s/%s", dir1, entry1->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dir2, entry1->d_name);

        // Compare file metadata (like last modified time) and decide what to do
        FileMetadata meta1 = collect_file_metadata(src_path);
        FileMetadata meta2 = collect_file_metadata(dest_path);

        // If file exists only in dir1, copy it to dir2
        if (meta1.last_modified != 0 && meta2.last_modified == 0) {
            copy_file(src_path, dest_path);
        }
        // TODO: Add more conditions based on metadata for full two-way sync
    }

    // Similar loop for dir2 to dir1 sync
    while ((entry2 = readdir(d2)) != NULL) {
        char src_path[512], dest_path[512];

        snprintf(src_path, sizeof(src_path), "%s/%s", dir2, entry2->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dir1, entry2->d_name);

        FileMetadata meta1 = collect_file_metadata(src_path);
        FileMetadata meta2 = collect_file_metadata(dest_path);

        if (meta1.last_modified != 0 && meta2.last_modified == 0) {
            copy_file(src_path, dest_path);
        }
    }

    closedir(d1);
    closedir(d2);
}

// For testing purposes
int main() {
    two_way_sync("./test_dir1", "./test_dir2");
    return 0;
}
