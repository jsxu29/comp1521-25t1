/*
 * Given 1+ command-line arguments which are the pathnames of files or directories
 * If the file or directory is publically-writeable, it should change it to be not
 * publically-writeable, leaving other permissions unchanged.
 */

#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // for every file
    for (int i = 1; i < argc; i++) {
        struct stat s;
        // get permissions mode
        if (stat(argv[i], &s) != 0) {
            perror("Unable to get stat metadata\n");
            continue;
        }
        mode_t mode = s.st_mode;

        // check if it is publically writeable
        if ((mode & S_IWOTH) != 0) { // we have a 1 at the other group write permissions bit 
            // if so, change it to be not publically writeable
            // int chmod(const char *path, mode_t mode);

            // S_IWOTH = 0b 000 000 010
            // ~S_IWOTH = 0b 111 111 101
            // mode = 0b --- --- -1-
            // mode & ~S_IWOTH = 0b --- --- -0-
            mode_t new_mode = mode & ~S_IWOTH; 
            if (chmod(argv[i], new_mode) != 0) {
                perror("Error changing permissions\n");
            }
        }
    }

    return 0;
}
