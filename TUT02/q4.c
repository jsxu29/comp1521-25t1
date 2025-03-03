// Prints the square of a number

#include <stdio.h>

int main(void) {
    int x, y; // declaring these variables

    printf("Enter a number: "); 
    scanf("%d", &x);

    y = x * x;

    printf("%d", y);
    printf("\n");

    return 0;
}
