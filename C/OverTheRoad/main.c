#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
---Over the Road---
You've just moved into a perfectly straight street with exactly n identical houses on either side of the road.
Naturally, you would like to find out the house number of the people on the other side of the street. The street looks
something like this:

Street
1|   |6
3|   |4
5|   |2
Evens increase on the right; odds decrease on the left. House numbers start at 1 and increase without gaps. When n =
3, 1 is opposite 6, 3 opposite 4, and 5 opposite 2.

Example
Given your house number address and length of street n, give the house number on the opposite side of the street.

size_t over_the_road(size_t address, size_t n);
over_the_road(1, 3) == 6
over_the_road(3, 3) == 4
over_the_road(2, 3) == 5
over_the_road(3, 5) == 8
Both n and address could get upto 500 billion with over 200 random tests.
 */

size_t over_the_road(size_t address, size_t street);

int main() {
    size_t input1a = 1;
    size_t input2a = 3;
    size_t input3a = 2;
    size_t input4a = 3;
    size_t input5a = 7;

    size_t input1b = 3;
    size_t input2b = 3;
    size_t input3b = 3;
    size_t input4b = 5;
    size_t input5b = 11;

    size_t output1 = over_the_road(input1a, input1b);
    size_t output2 = over_the_road(input2a, input2b);
    size_t output3 = over_the_road(input3a, input3b);
    size_t output4 = over_the_road(input4a, input4b);
    size_t output5 = over_the_road(input5a, input5b);

    size_t expected_output1 = 6;
    size_t expected_output2 = 4;
    size_t expected_output3 = 5;
    size_t expected_output4 = 8;
    size_t expected_output5 = 16;
    
    if (output1 != expected_output1) {
        printf("Test 1 Failed. Output: %lu || ExpectedOutput: %lu\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed. Output: %lu || ExpectedOutput: %lu\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed. Output: %lu || ExpectedOutput: %lu\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed. Output: %lu || ExpectedOutput: %lu\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed. Output: %lu || ExpectedOutput: %lu\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed\n");
    }

    return 0;
}

size_t over_the_road(size_t address, size_t street) {
    if (address % 2 == 0) {
        size_t position = address / 2 - 1;
        return street * 2 - 1 - position * 2;
    } else {
        size_t position = street - (address + 1) / 2;
        return (position + 1) * 2;
    }
}