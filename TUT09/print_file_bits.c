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

    // read 32-bit hexadecimal numbers until end of file
    int32_t number;
    while (fscanf(stream, "%x", &number) == 1) {
        // print lowest byte
        //   xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
        // & 00000000 00000000 00000000 11111111
        //   00000000 00000000 00000000 xxxxxxxx

        int32_t least_signifcant_byte = number & 0xFF;

        // sign extension 
        // In C, type casting to an integer type with more bits
        // the extra space is filled with the leading sign bit.
        //   00000000 00000000 00000000 xxxxxxxx
        // & 00000000 00000000 00000000 10000000
        //   00000000 00000000 00000000 x0000000
        // check if the leading sign bit of the last byte is a 1
        if ((least_signifcant_byte & 0x80) != 0) {
            least_signifcant_byte = least_signifcant_byte | 0xFFFFFF00;
        }

        printf("%d\n", least_signifcant_byte);
    }

    // close the file
    fclose(stream);

    return 0;
}