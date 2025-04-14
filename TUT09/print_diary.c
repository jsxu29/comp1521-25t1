// print contents of $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // get env variable - $HOME
    char *home_env = getenv("HOME");
    // $HOME not set
    if (home_env == NULL) {
        home_env = ".";
    }

    // build a filename $HOME/.diary '\0'
    // create a placeholder string 
    char *diary_name = ".diary";
    // add 2 for '/' and '\0'
    int diary_filename_len = strlen(home_env) + strlen(diary_name) + 2;
    char *diary_filename = malloc(diary_filename_len);
    // pass it the actual size of diary_filename, not strlen(diary_filename) as diary_filename was not set to any specific string initially
    snprintf(diary_filename, diary_filename_len, "%s/.diary", home_env);
    // open this file $HOME/.diary
    FILE *diary_file = fopen(diary_filename, "r");
    if (diary_file == NULL) {
        perror("Error opening file\n");
        return 1;
    }

    // read contents of file and print to stdout
    int c;
    while ( (c = fgetc(diary_file)) != EOF ) {
        fputc(c, stdout);
    }

    // close this file
    fclose(diary_file);

    return 0;
}
