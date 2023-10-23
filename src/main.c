#include <stdio.h>
#include <stdlib.h>
#include "../include/file_metadata.h"
#include "../include/file_operations.h"
#include "../include/sync_logic.h"
#include "../include/utils.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        exit(1);
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    // Validate the directories
    if (!is_directory_valid(dir1) || !is_directory_valid(dir2)) {
        printf("One or both directories are invalid.\n");
        exit(1);
    }

    // Collect metadata from both directories
    FileMetadataList *list1 = collect_file_metadata(dir1);
    FileMetadataList *list2 = collect_file_metadata(dir2);

    // Handle error if metadata collection fails
    if (list1 == NULL || list2 == NULL) {
        printf("Error in collecting file metadata.\n");
        exit(1);
    }

    // Perform two-way synchronization
    if (!two_way_sync(list1, list2, dir1, dir2)) {
        printf("Two-way synchronization failed.\n");
        exit(1);
    }

    // Clean up
    free_file_metadata_list(list1);
    free_file_metadata_list(list2);

    printf("Two-way synchronization completed successfully.\n");
    return 0;
}
