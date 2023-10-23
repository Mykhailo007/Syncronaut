#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to copy a file
int copy_file(const char *src, const char *dest) {
    FILE *sourceFile, *destFile;
    char ch;

    sourceFile = fopen(src, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open source file to read.\n");
        return -1;
    }

    destFile = fopen(dest, "wb");
    if (destFile == NULL) {
        fclose(sourceFile);
        printf("Unable to open destination file to write.\n");
        return -1;
    }

    // Copy file content character by character.
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

// Function to delete a file
int delete_file(const char *file_path) {
    if (remove(file_path) == 0) {
        printf("Deleted successfully.\n");
        return 0;
    } else {
        printf("Unable to delete the file.\n");
        return -1;
    }
}

// Function to move a file
int move_file(const char *src, const char *dest) {
    // Copy the source to destination
    if (copy_file(src, dest) == 0) {
        // Delete the source file
        if (delete_file(src) == 0) {
            return 0;
        } else {
            printf("Failed to delete source file after copying.\n");
            return -1;
        }
    } else {
        printf("Failed to copy file.\n");
        return -1;
    }
}

// // Testing the file operations
// int main() {
//     if (copy_file("source.txt", "destination.txt") == 0) {
//         printf("File copied successfully.\n");
//     }

//     if (delete_file("destination.txt") == 0) {
//         printf("File deleted successfully.\n");
//     }

//     if (move_file("source.txt", "moved_source.txt") == 0) {
//         printf("File moved successfully.\n");
//     }

//     return 0;
// }
