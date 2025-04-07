// Write a C program, fgrep.c, which is given 1+ command-line arguments which is
// a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and
// print them to stdout if they contain the string specified as the first 
// command line argument.
//
// If there are 2 or more command line arguments, it should treat arguments 
// after the first as filenames and print any lines they contain which contain
// the string specified as the first command line argument.
//
// When printing lines, preface them with their line number (indexed from 1).
//
// Print a suitable error message if there are not enough arguments, or there is
// an error opening a file.
//
// Example:
// ./fgrep hello nonexistentfile.txt
//  hello: nonexistentfile.txt: No such file or directory
//
// ./fgrep test testfile.txt
// line 1 from testfile.txt: This is a test
//
// Assume lines are 65536 bytes at most.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    } else if (argc == 2) {
        search_stream(stdin, "<stdin>", argv[1]);
    } else {
        for (int i = 2; i < argc; i++) {
            // filename = argv[i]
            // open the file
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "%s: %s: No such file or directory\n", argv[1], argv[i]);
                continue;
            }

            // call search_stream  
            search_stream(file, argv[i], argv[1]);
        }
    }

    return 0;
}

/*
 * Search through every line of the opened file / stream and look for the search string,
 * if it is apart of the line, we should print to standard output
 */
void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    // TODO: complete this function
    // hint: look at `strstr(3)'
    char buffer[MAX_LINE];
    int line_num = 1;
    
    // read every line of stream
    while ( fgets(buffer, MAX_LINE, stream) != NULL ) {
        // and if the line contains the search_for string
        if ( strstr(buffer, search_for) != NULL ) {
            // print the line to standard output, indexed by line number and what stream it is from
            printf("line %d from %s: %s", line_num, stream_name, buffer);
        }
        line_num++;
    }
}
