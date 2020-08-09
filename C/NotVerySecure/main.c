#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
---Not Very Secure---
In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None,
so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces / underscore */

bool alphanumeric(const char *strin);

int main() {
    char *input1 = "hello_world";
    char *input2 = "PassW0rd";
    char *input3 = "     ";
    char *input4 = "a";
    char *input5 = "43534h56jmTHHF3k";
    char *input6 = "sw7CB87L7ZFGT45HL0MpTM4GMHTTMBdQwv3a3KxXLMkIDiiPrfG6378Uk09nl8y3PpPS6A6Bzxsv42tLIVwfluIYALNd3P9EEfWzFF8a4jsyw7hkq=6yD8HtJrr20egupc1";

    bool output1 = alphanumeric(input1);
    bool output2 = alphanumeric(input2);
    bool output3 = alphanumeric(input3);
    bool output4 = alphanumeric(input4);
    bool output5 = alphanumeric(input5);
    bool output6 = alphanumeric(input6);

    if (output1) {
        printf("Test 1 Failed, Supposed to be FALSE\n");
    } else {
        printf("Test 1 Passed.\n");
    }

    if (!output2) {
        printf("Test 2 Failed, Supposed to be TRUE\n");
    } else {
        printf("Test 2 Passed.\n");
    }

    if (output3) {
        printf("Test 3 Failed, Supposed to be FALSE\n");
    } else {
        printf("Test 3 Passed.\n");
    }

    if (!output4) {
        printf("Test 4 Failed, Supposed to be TRUE\n");
    } else {
        printf("Test 4 Passed.\n");
    }

    if (!output5) {
        printf("Test 5 Failed, Supposed to be TRUE\n");
    } else {
        printf("Test 5 Passed.\n");
    }

    if (output6) {
        printf("Test 6 Failed, Supposed to be FALSE\n");
    } else {
        printf("Test 6 Passed.\n");
    }

    return 0;
}

bool alphanumeric(const char *strin) {
    int alphanumeric_count = 0;

    while (*strin != '\0') {
        if (isalpha(*strin) || isdigit(*strin)) {
            ++alphanumeric_count;
        } else if (!isalpha(*strin) && !isdigit(*strin)) {
            return false;
        }

        ++strin;
    }

    return alphanumeric_count > 0;
}