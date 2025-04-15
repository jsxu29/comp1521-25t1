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

    // we can loop through our utf-8 string
    // and for every codepoint/unicode character, we can find the length of it by looking at the first byte of the char
    // and then we can move by that length to the next unicode char and repeat 
    char *utf8_str = argv[1];
    int unicode_char_num = 0;
    for (int i = 0; utf8_str[i] != '\0'; ) {
        unicode_char_num++;

        // increment by length of unicode char

        // if format is 0xxxxxxx, length is 1
        //   xxxxxxxx
        // & 10000000
        //   x0000000 -> 00000000 or 10000000
        if ((utf8_str[i] & 0x80) == 0) {
            i += 1;
        }
        // else if format is 110xxxxx, length is 2
        //   xxxxxxxx
        // & 11100000
        //   xxx00000, check if 110 00000
        else if ((utf8_str[i] & 0xE0) == 0xC0) {
            i += 2;
        }
        // else if format is 1110xxxx, length is 3
        //   xxxxxxxx
        // & 11110000
        //   xxxx0000, check if 1110 0000
        else if ((utf8_str[i] & 0xF0) == 0xE0) {
            i += 3;
        }
        // else if format is 11110xxx, length is 4
        //   xxxxxxxx
        // & 11111000
        //   xxxxx000, check if 1111 0000
        else if ((utf8_str[i] & 0xF8) == 0xF0) {
            i += 4;
        }
        // else, there is an error, invalid unicode char
        else {
            perror("Invalid UTF-8 string\n");
            return 1;
        }
    }

    printf("there are %d codepoints in this string\n", unicode_char_num);

    return 0;
}