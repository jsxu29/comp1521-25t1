char *string = "....";
char *s = &string[0]; // INIT
int   length = 0;
while (*s != '\0') { // COND
   length++;  // BODY increment length 
   s++;       // STEP move to next char
}
// POST