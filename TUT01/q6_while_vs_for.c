/*
How could we rewrite the above program using a for loop? What subtle difference would there be between the two programs?
*/

#include <stdio.h>

int main(void) {

  int i = 0; // 1. INITIALISE
  while (i < 10) { // 2. CHECKING CONDITION
    printf("%d\n", i); // 3. BODY
    i++; // 4. INCREMENT or STEP 
  }

  // for (INIT; COND; INCREMENT)
  for (int i = 0; i < 10; i++) {
    // body
    printf("%d\n", i);
  }
  
  return 0;
}
