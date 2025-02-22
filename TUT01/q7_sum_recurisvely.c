/*
This program scans in a number n and prints the sum of all integers up to and including n.

Rewrite the sum function so it uses recursion instead of a loop.

What happens in memory when this program runs? What is the difference between the loop and recursive versions?
*/

#include <stdio.h>

int sum(int n);

int main(int argc, char *argv[]) {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);

        int result = sum(n);
        printf("Sum of all numbers up to %d = %d\n", n, result);

        return 0;
}

// int sum(int n) {
//     int result = 0;
//     for (int i = 0; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }

int sum(int n) {
    if (n == 0) return 0;

    return n + sum(n - 1);
}
