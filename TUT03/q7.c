// A simple program that adds 42 to each element of an array

#define N_SIZE 10

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};

    i = 0; // INIT
    while (i < N_SIZE) { // COND
        // BODY
        if (numbers[i] < 0) {
            int temp = numbers[i] + 42;
            numbers[i] = temp;
        }
        i++; // STEP
    }
    // POST

add42_init:
    i = 0;
add42_cond:
    if (i >= N_SIZE) goto add42_post;

add42_body:
    if (numbers[i] < 0) {
        int temp = numbers[i] + 42;
        numbers[i] = temp;
    } else {
        
    }

add42_step:
    i++;
    goto add42_cond;

add42_post:

    return 0;
}

