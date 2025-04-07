/*
 * Given one command-line argument, the name of a file, reads
 * a line from stdin, and writes it to the specified file;
 * if the file exists, it should be overwritten
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Usage error\n");
        return 1;
    }

    // open specified file
    FILE *out_file = fopen(argv[1], "w");
    if (out_file == NULL) {
        perror("File could not be opened\n");
        return 1;
    }

    // read from standard input
    // int c = fgetc(stdin);
    // while (c != '\n') {
    //     // write to a file
    //     fputc(c, out_file);
    //     // read next character
    //     c = fgetc(stdin);
    // }

    int c;
    while ( (c = fgetc(stdin)) != EOF ) {
        fputc(c, out_file);
        if (c == '\n') {
            break;
        }
    }
 
    return 0;
}