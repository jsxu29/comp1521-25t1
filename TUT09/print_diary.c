// print contents of $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // create the filename $HOME/.diary
    // get $HOME
    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        home_dir = "."; // if $HOME does not exist, default to current working directory
    }

    int diary_filename_len = strlen(home_dir) + strlen("/.diary") + 1; // +1 for '\0'
    char *diary_filename = malloc(diary_filename_len);
    // pass it the actual size of diary_filename, not strlen(diary_filename) as diary_filename was not set to any specific string initially
    snprintf(diary_filename, diary_filename_len, "%s/.diary", home_dir);

    // open that file
    FILE *diary_file = fopen(diary_filename, "r");
    if (diary_file == NULL) {
        perror("Error opening file\n");
        return 1;
    }

    // read and print contents until we reach end of file
    int c;
    while ( (c = fgetc(diary_file)) != EOF) {
        fputc(c, stdout);
    }

    // close the file
    fclose(diary_file);

    return 0;
}
