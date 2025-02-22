### Intro

- What is your preferred name (what should we call you?) - feel free to share pronouns if you wish!
- What is your degree and year of study?
- Share a fun fact about yourself!

## Process Address Space

This is a diagram of the address space of a process in memory:

![Process address space](https://th.bing.com/th/id/OIP.sLKvCgtHxloDHz_bfnMzzQAAAA?pid=ImgDet&rs=1)

Note the 'text' segment is always called the 'code' segment.

- The code segment contains the program instructions (e.g. functions).
- The data segment contains global and static variables, and string literals.
- The heap contains dynamically allocated memory (think `malloc()`).
- The stack contains local variables.

function pointers 

Consider this simple C program:

```c
#include <stdlib.h>

int globalCounter = 0;

int main(void)
{
        int i = 0;
        char *message = "Hello world!\n";
        float floatArray[10];
        int *pointer = malloc(400);
}
```

- `globalCounter` is a global variable, hence, it's in the data segment.
- `main()` is a function, and its instructions are stored in the code segment.
- `i` is a local variable, so it's in the stack.
- `char *message = "Hello world!\n"` has 2 allocations:
  - `"Hello world"` is a string literal, so it's in the data segment.
  - `message` is a pointer. It points to `"Hello world"` in the data segment, but the pointer itself is a local variable, and hence it's in the stack.
- `floatArray[10]` is a local variable, so it's in the stack.
- Like before, `int *pointer = malloc(400)` has 2 allocations:
  - The 400 bytes allocated by `malloc()` is in the heap.
  - `pointer` is a local variable that points to the 400 byte memory region returned by `malloc()`, but the pointer itself is in the stack.