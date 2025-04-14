/*
 * Write a C program that reads a null-terminated UTF-8 string as a command line
 * argument and counts how many Unicode characters (code points) it contains.
 * Assume that all codepoints in the string are valid.
 * 
 * Examples:
 * ./count_utf8 "チョコミント、よりもあなた！"
    there are 14 codepoints in the string
 * ./count_utf8 "早上好中国现在我有冰淇淋"
    there are 12 codepoints in the string
 * ./count_utf8 "🤓🤓🤓🤓🤓🤓🤓🤓"
    there are 8 codepoints in the string
 */

#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // given a string, loop through it, and depending on the head/first byte of the utf-8 character, we know its length of the character
    // utf 8 string of 9 bytes: 012 345 67 8
    // at index 0: look at length of that unicode character, and move forward by that length to get to the next character
    int unicode_char_num = 0;
    for (int i = 0; argv[1][i] != '\0'; ) {
        // keep track of number of unicode characters
        unicode_char_num++;
        // increment the position to the head/first byte of the next unicode character
        // find length of this unicode character
        char head_byte = argv[1][i];
        // 1 - 0xxxxxxx
        // 2 - 110xxxxx
        // 3 - 1110xxxx
        // 4 - 11110xxx

        //   --------
        // & 10000000
        //   -0000000 check if this is equal to 0 0000000
        if ((head_byte & 1 << 7) == 0) {
            i += 1;
        } 
        //   --------
        // & 11100000
        //   ---00000 check if this is equal to 110 00000
        else if ((head_byte & 0xE0) == 0xC0) {
            i += 2;
        }

        //   --------
        // & 11110000
        //   ----0000 check if this is equal to 1110 0000
        else if ((head_byte & 0xF0) == 0xE0) {
            i += 3;
        }

        //   --------
        // & 11111000
        //   -----000 check if this is equal to 11110 000
        else if ((head_byte & 0xF8) == 0xF0) {
            i += 4;
        }

        else {
            fprintf(stderr, "Invalid utf-8 character\n");
        }
    }

    printf("there are %d codepoints in the string\n", unicode_char_num);
    return 0;
}