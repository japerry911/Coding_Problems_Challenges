#include <stdio.h>

/*
---Count the Divisors of a Number---
Count the number of divisors of a positive integer n.

Random tests go up to n = 500000.

Examples
divisors(4)  == 3  //  1, 2, 4
divisors(5)  == 2  //  1, 5
divisors(12) == 6  //  1, 2, 3, 4, 6, 12
divisors(30) == 8  //  1, 2, 3, 5, 6, 10, 15, 30
 */

int divisors(int n);

int main() {
    int input1 = 4;
    int input2 = 5;
    int input3 = 12;
    int input4 = 30;
    int input5 = 500000;

    int output1 = divisors(input1);
    int output2 = divisors(input2);
    int output3 = divisors(input3);
    int output4 = divisors(input4);
    int output5 = divisors(input5);

    int expected_output1 = 3;
    int expected_output2 = 2;
    int expected_output3 = 6;
    int expected_output4 = 8;
    int expected_output5 = 42;

    if (output1 != expected_output1) {
        printf("Test 1 Failed: Expected: %d || Output: %d\n", expected_output1, output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed: Expected: %d || Output: %d\n", expected_output2, output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed: Expected: %d || Output: %d\n", expected_output3, output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed: Expected: %d || Output: %d\n", expected_output4, output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed: Expected: %d || Output: %d\n", expected_output5, output5);
    } else {
        printf("Test 5 Passed.\n");
    }

        return 0;
}

int divisors(int n) {
    int number_of_divisors = 1;

    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            ++number_of_divisors;
        }
    }

    return number_of_divisors;
}