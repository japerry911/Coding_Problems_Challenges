#include <stdio.h>

/*
---Sum of Digits / Digital Root
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a
single-digit number is produced. This is only applicable to the natural numbers.
 */

int digital_root(int n);

int main() {
    int input1 = 16;
    int input2 = 195;
    int input3 = 992;
    int input4 = 167346;
    int input5 = 0;

    int output1 = digital_root(input1);
    int output2 = digital_root(input2);
    int output3 = digital_root(input3);
    int output4 = digital_root(input4);
    int output5 = digital_root(input5);

    int expected_output1 = 7;
    int expected_output2 = 6;
    int expected_output3 = 2;
    int expected_output4 = 9;
    int expected_output5 = 0;
    
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

    if (output4 != expected_output4) {
        printf("Test 4 Failed: Output = %i || Expected_Output = %i\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed: Output = %i || Expected_Output = %i\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    return 0;
}

int digital_root(int n) {
    int return_number = 10;

    while (return_number >= 10) {
        int holding_sum = 0;

        while (n > 0) {
            holding_sum += n % 10;
            n /= 10;
        }

        if (holding_sum < 10) {
            return_number = holding_sum;
        } else {
            n = holding_sum;
        }
    }

    return return_number;
}