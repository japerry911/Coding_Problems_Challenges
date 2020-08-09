#include <stdio.h>

/*
---A Rule of Divisibility by 13---
When you divide the successive powers of 10 by 13 you get the following remainders of the integer divisions:

1, 10, 9, 12, 3, 4.

Then the whole pattern repeats.

Hence the following method: Multiply the right most digit of the number with the left most number in the sequence shown
above, the second right most digit to the second left most digit of the number in the sequence. The cycle goes on and
you sum all these products. Repeat this process until the sequence of sums is stationary.

...........................................................................

Example: What is the remainder when 1234567 is divided by 13?

7×1 + 6×10 + 5×9 + 4×12 + 3×3 + 2×4 + 1×1 = 178

We repeat the process with 178:

8x1 + 7x10 + 1x9 = 87

and again with 87:

7x1 + 8x10 = 87

...........................................................................

From now on the sequence is stationary and the remainder of 1234567 by 13 is the same as the remainder of 87 by 13: 9

Call thirt the function which processes this sequence of operations on an integer n (>=0). thirt will return the stationary number.

thirt(1234567) calculates 178, then 87, then 87 and returns 87.

thirt(321) calculates 48, 48 and returns 48
 */

// sz1: size of array1, sz2: size of array2, lg: size of the returned array
long long thirt(long long n);

int main() {
    long long input1 = 1234567;
    long long input2 = 85299258;
    long long input3 = 5634;
    long long input4 = 1111111111;
    long long input5 = 987654321;
    long long input6 = 8529;

    long long output1 = thirt(input1);
    long long output2 = thirt(input2);
    long long output3 = thirt(input3);
    long long output4 = thirt(input4);
    long long output5 = thirt(input5);
    long long output6 = thirt(input6);

    long long expected_output1 = 87;
    long long expected_output2 = 31;
    long long expected_output3 = 57;
    long long expected_output4 = 71;
    long long expected_output5 = 30;
    long long expected_output6 = 79;

    if (output1 != expected_output1) {
        printf("Test 1 Failed: %llu = %llu\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (output2 != expected_output2) {
        printf("Test 2 Failed: %llu = %llu\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3 != expected_output3) {
        printf("Test 3 Failed: %llu = %llu\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (output4 != expected_output4) {
        printf("Test 4 Failed: %llu = %llu\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (output5 != expected_output5) {
        printf("Test 5 Failed: %llu = %llu\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (output6 != expected_output6) {
        printf("Test 6 Failed: %llu = %llu\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    return 0;
}

long long thirt(long long n) {
    long long pattern_array[6] = {1, 10, 9, 12, 3, 4};
    long long return_long = 0;
    long long current_value = n;
    long long previous_value = n;
    int counter = 0;

    for (;;) {
        if (counter == 6) {
            counter = 0;
        }

        return_long += (pattern_array[counter] * (current_value % 10));
        ++counter;
        current_value /= 10;

        if (current_value == 0) {
            if (return_long == previous_value) {
                break;
            }

            current_value = return_long;
            previous_value = return_long;
            return_long = 0;
            counter = 0;
        }
    }

    return return_long;
}