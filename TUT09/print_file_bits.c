// read 32-bit hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    // read 32-byte hexadeimcal numbers
    int32_t number;
    while (fscanf(stream, "%x", &number) != 1) {
        // print the least significant byte as a signed decimal number
        
        // get least significant byte
        //   xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
        // & 00000000 00000000 00000000 11111111
        //   00000000 00000000 00000000 xxxxxxxx
        int32_t least_significant = number & 0xFF;
        
        // sign extension: in C, type casting to an integer type with more bits,
        // the extra space is filled with the leading sign bit.

        // check if leading sign bit is a 1
        //   00000000 00000000 00000000 xxxxxxxx
        // & 00000000 00000000 00000000 10000000
        //   00000000 00000000 00000000 x0000000
        if ((least_significant & (1 << 7)) != 0) {
            // sign extend
            // 0xFFFFFF00 = 0b 11111111 11111111 11111111 00000000
            least_significant = least_significant | 0xFFFFFF00;
        }

        printf("%d\n", least_significant);
    }

    fclose(stream);

    return 0;
}