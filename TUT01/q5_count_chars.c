/*
Write a c program count_chars.c that uses getchar to read in characters until the user enters Ctrl-D and then prints the total number of characters entered.
Use man 3 getchar to look at the manual entry.
*/

#include <stdio.h>

int main() {

    // getchar()
    // getchar()
    // ...
    // user hits ctrl-D -> stop reading input
    // getchar() -> EOF

    int num_char = 0;
    int c;
    while ( (c = getchar()) != EOF ) {
        // ++num_char; // pre-increment, num_char + 1 -> return num_char
        num_char++; // post-increment, return num_char -> num_char + 1
    }

    printf("Number of characters entered: %d\n", num_char);

    return 0;
}
