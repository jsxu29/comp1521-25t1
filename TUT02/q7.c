// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    
    /* GENERAL FOR LOOP STRUCTURE
    for (INITIALISATION; CONDITION; INCREMENT) {
        BODY
    }*/

    /* V1: original for loop version
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n", x);
    }
    */

    /* V2: conversion to while loop
    int x = 24; 
    while (x < 42) {
        printf("%d\n", x);
        x += 3;
    }
    ...
    */

    // V3: converting to labels and jump instructions
while_init:
    int x = 24;

while_cond:
    // if (x < 42) go into while loop body
    if (x >= 42) goto while_post; // exit while loop

while_body:
    printf("%d", x);
    printf("\n");

while_step:
    x = x + 3;

    goto while_cond;

while_post:



    return 0;
}
