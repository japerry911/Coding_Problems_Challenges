#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
---More Zeroes than Ones---
Create a moreZeros function which will receive a string for input, and return an array (or null terminated string in C)
containing only the characters from that string whose binary representation of its ASCII value consists of more zeros
than ones.

You should remove any duplicate characters, keeping the first occurence of any such duplicates, so they are in the same
order in the final array as they first appeared in the input string.

Examples

"abcde" ==  {0b1100001, 0b1100010, 0b1100011, 0b1100100, 0b1100101}
               True       True       False      True       False

         --> "abd"

"DIGEST" --> "DIET"
All input will be valid strings of length > 0. Leading zeros in binary should not be counted.
 */

char *more_zeroes(const char *str);

int main() {
    char *input1 = "abcde";
    char *input2 = "thequickbrownfoxjumpsoverthelazydog";
    char *input3 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";
    char *input4 = "DIGEST";

    char *output1 = more_zeroes(input1);
    char *output2 = more_zeroes(input2);
    char *output3 = more_zeroes(input3);
    char *output4 = more_zeroes(input4);

    char *expected_output1 = "abd";
    char *expected_output2 = "hbpad";
    char *expected_output3 = "THEQICBRFXJPLAD";
    char *expected_output4 = "DIET";
    
    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed: Output = %s || Expected_Output = %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed: Output = %s || Expected_Output = %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed: Output = %s || Expected_Output = %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed: Output = %s || Expected_Output = %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    return 0;
}

char *more_zeroes(const char *str) {
    int return_size = 5;
    int counter = 0;
    char *return_string = (char *)malloc(return_size * sizeof(char));

    for (int i = 0; i < strlen(str); ++i) {
        int a = str[i];
        int ones = 0;
        int zeroes = 0;

        while (a) {
            if (a & 1) {
                ++ones;
            } else {
                ++zeroes;
            }

            a >>= 1;
        }

        if (zeroes > ones) {
            bool appeared_earlier = false;

            for (int q = 0; q < counter; ++q) {
                if (return_string[q] == str[i]) {
                    appeared_earlier = true;
                    break;
                }
            }

            if (appeared_earlier) {
                continue;
            }

            return_string[counter] = str[i];
            ++counter;

            if (counter >= return_size) {
                return_size += 5;
                return_string = realloc(return_string, return_size * sizeof(char));
            }
        }
    }

    if (counter >= return_size) {
        ++return_size;
        return_string = realloc(return_string, return_size * sizeof(char));
    }

    return_string[counter] = '\0';

    return return_string;
}