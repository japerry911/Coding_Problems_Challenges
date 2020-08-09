#include <stdio.h>

/*
---Maximum SubArray Sum---
The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list
of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9)
// should return 6, from sub-array: {4, -1, 2, 1}
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If
the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.
 */

int max_sequence(const int *array, size_t n);

int main() {
    int input1a[0] = {};
    int input2a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int input3a[16] = {7, 4, 11, -11, 39, 36, 10, -6, 37, -10, -32, 44, -26, -34, 43, 43};

    size_t input1b = 0;
    size_t input2b = 9;
    size_t input3b = 16;

    int output1 = max_sequence(input1a, input1b);
    int output2 = max_sequence(input2a, input2b);
    int output3 = max_sequence(input3a, input3b);

    int expected_output1 = 0;
    int expected_output2 = 6;
    int expected_output3 = 155;

    if (output1 != expected_output1) {
        printf("Test 1 Failed: Output = %i || Expected_Output = %i\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed: Output = %i || Expected_Output = %i\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }
    
    if (output3 != expected_output3) {
        printf("Test 3 Failed: Output = %i || Expected_Output = %i\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    return 0;
}

int max_sequence(const int *array, size_t n) {
    int max_sum = 0;

    for (size_t i = 0; i < n; ++i) {
        int hold_sum = array[i];

        if (hold_sum > max_sum) {
            max_sum = hold_sum;
        }

        for (size_t j = i + 1; j < n; ++j) {
            hold_sum += array[j];

            if (hold_sum > max_sum) {
                max_sum = hold_sum;
            }
        }
    }

    return max_sum;
}