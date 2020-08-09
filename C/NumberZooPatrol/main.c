#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
---Number Zoo Patrol
Background:
You're working in a number zoo, and it seems that one of the numbers has gone missing!

Zoo workers have no idea what number is missing, and are too incompetent to figure it out, so they're hiring you to do
it for them.

In case the zoo loses another number, they want your program to work regardless of how many numbers there are in total.

Task:
Write a function that takes a shuffled list of unique numbers from 1 to n with one element missing (which can be any
number including n). Return this missing number.

Note: huge lists will be tested.

Examples:
[1, 3, 4]  =>  2
[1, 2, 3]  =>  4
[4, 2, 3]  =>  1
 */

unsigned find_number(const unsigned *arr, size_t len);

int main() {
    unsigned input1[] = {2, 3, 4};
    unsigned input2[] = {1, 3, 4};
    unsigned input3[] = {1, 2, 4};
    unsigned input4[] = {1, 2, 3};

    unsigned output1 = find_number(input1, 3);
    unsigned output2 = find_number(input2, 3);
    unsigned output3 = find_number(input3, 3);
    unsigned output4 = find_number(input4, 3);

    unsigned expected_output1 = 1;
    unsigned expected_output2 = 2;
    unsigned expected_output3 = 3;
    unsigned expected_output4 = 4;
    
    if (output1 != expected_output1) {
        printf("Test 1 Failed - Output = %u || Expected_Output = %u\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed - Output = %u || Expected_Output = %u\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed - Output = %u || Expected_Output = %u\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed - Output = %u || Expected_Output = %u\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    return 0;
}

unsigned find_number(const unsigned *arr, size_t len) {
    unsigned current = 1;

    for (int i = 0; i < len; ++i) {
        if (arr[i] == current) {
            ++current;
            i = 0;
        }
    }

    return current;
}