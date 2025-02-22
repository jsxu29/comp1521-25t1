#include <stdio.h>

int main(void) {
    char str[10]; // - - - - - - - - - -
    str[0] = 'H'; // H - - - - - - - - -
    str[1] = 'i'; // H i - - - - - - - -
    str[2] = '\0';
    printf("%s", str); // H i \0 - - - - - - - 
    return 0;
}

