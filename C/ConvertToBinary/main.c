#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
---Convert to Binary---
Given a non-negative integer n, write a function toBinary/ToBinary which returns
that number in a binary format.

Example:

to_binary(1)  should return 1
to_binary(5)  should return 101
to_binary(11) should return 1011
 */

unsigned long long to_binary(unsigned short num);

int main() {
    unsigned short input1 = 1;
    unsigned short input2 = 2;
    unsigned short input3 = 3;
    unsigned short input4 = 5;
    unsigned short input5 = 15;

    unsigned long long output1 = to_binary(input1);
    unsigned long long output2 = to_binary(input2);
    unsigned long long output3 = to_binary(input3);
    unsigned long long output4 = to_binary(input4);
    unsigned long long output5 = to_binary(input5);

    unsigned long long expected_output1 = 1ull;
    unsigned long long expected_output2 = 10ull;
    unsigned long long expected_output3 = 11ull;
    unsigned long long expected_output4 = 101ull;
    unsigned long long expected_output5 = 1111ull;

    if (output1 != expected_output1) {
        printf("Test 1 Failed: Output: %llu || Expected_Output: %llu\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed: Output: %llu || Expected_Output: %llu\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed: Output: %llu || Expected_Output: %llu\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed: Output: %llu || Expected_Output: %llu\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed: Output: %llu || Expected_Output: %llu\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    return 0;
}

unsigned long long to_binary(unsigned short num) {
    int *array = calloc(25, sizeof(int));
    int counter = 0;

    while (num > 0) {
        array[counter] = num % 2;
        ++counter;
        num /= 2;
    }

    unsigned long long return_binary = 0;

    for (int i = 0; i < counter; ++i) {
        if (array[i] == 1) {
            return_binary += (unsigned long long) pow(10.0, i);
        }
    }

    free(array);

    return return_binary;
}