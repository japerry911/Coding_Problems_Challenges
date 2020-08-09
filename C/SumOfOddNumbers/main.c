#include <stdio.h>
#include <inttypes.h>

/*
---Sum of Odd Numbers---
Given the triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
Calculate the row sums of this triangle from the row index (starting at index 1) e.g.:

rowSumOddNumbers(1); // 1
rowSumOddNumbers(2); // 3 + 5 = 8
 */

uint64_t row_sum_odd_numbers(uint32_t n);

int main() {
    uint32_t input1 = 1;
    uint32_t input2 = 2;
    uint32_t input3 = 42;
    uint32_t input4 = 4;
    uint32_t input5 = 5;

    uint64_t output1 = row_sum_odd_numbers(input1);
    uint64_t output2 = row_sum_odd_numbers(input2);
    uint64_t output3 = row_sum_odd_numbers(input3);
    uint64_t output4 = row_sum_odd_numbers(input4);
    uint64_t output5 = row_sum_odd_numbers(input5);

    uint64_t expected_output1 = 1;
    uint64_t expected_output2 = 8;
    uint64_t expected_output3 = 74088;
    uint64_t expected_output4 = 64;
    uint64_t expected_output5 = 125;

    if (output1 != expected_output1) {
        printf("Test 1 Failed: %llu != %llu\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed: %llu != %llu\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed: %llu != %llu\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed: %llu != %llu\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed: %llu != %llu\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    return 0;
}

uint64_t row_sum_odd_numbers(uint32_t n) {
    uint64_t return_sum = 0;
    uint64_t start_number = 0;

    for (int i = 1; i < n + 1; ++i) {
        if (i == 1) {
            start_number += 1;
        } else {
            start_number += ((i - 1) * 2);
        }
    }

    for (int i = 0; i < n; ++i) {
        return_sum += start_number;
        start_number += 2;
    }

    return return_sum;
}