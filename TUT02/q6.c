// A simple program demonstrating how to represent a implementing an && in an
// if-statement in MIPS.
// This version: C, but a slightly less nice approach.

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    
    // 100 < x < 100
    /*
    !(x > 100 && x < 1000)
    = !(x> 100) || !(x<1000)
    = x <= 100 || x >= 1000
    */

    // char *message = "small/big\n";
    // if (x > 100 && x < 1000) { // Change AND statements to OR 
    //     message = "medium";
    // }

    if (x <= 100) goto small_big;
    if (x >= 1000) goto small_big;

    // 100 < x < 1000
    char *message = "medium\n";
    goto print;


small_big:
    message = "small/big\n";


print:
    printf("%s", message);
}
