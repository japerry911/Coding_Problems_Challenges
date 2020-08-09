#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
---Reverse Letter---
Task
Given a string str, reverse it omitting all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".

Input/Output
[input] string str

A string consists of lowercase latin letters, digits and symbols.

[output] a string
 */

char *reverse_letter(const char *str);

int main() {
    char *input1 = "krishan";
    char *input2 = "ultr53o?n";
    char *input3 = "ab23c";
    char *input4 = "krish21an";
    char *input5 = "l=asfpzdnaocm%ybsjoonwgw_cq";
    char *input6 = "x-n!fa-aht*nr{u/d@ro[c)jwgiq.bzy3psg[v,z";

    char *output1 = reverse_letter(input1);
    char *output2 = reverse_letter(input2);
    char *output3 = reverse_letter(input3);
    char *output4 = reverse_letter(input4);
    char *output5 = reverse_letter(input5);
    char *output6 = reverse_letter(input6);

    char *expected_output1 = "nahsirk";
    char *expected_output2 = "nortlu";
    char *expected_output3 = "cba";
    char *expected_output4 = "nahsirk";
    char *expected_output5 = "qcwgwnoojsbymcoandzpfsal";
    char *expected_output6 = "zvgspyzbqigwjcordurnthaafnx";

    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed, Output -> %s || Expected_Output -> %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed, Output -> %s || Expected_Output -> %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed, Output -> %s || Expected_Output -> %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed, Output -> %s || Expected_Output -> %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (strcmp(output5, expected_output5) != 0) {
        printf("Test 5 Failed, Output -> %s || Expected_Output -> %s\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (strcmp(output6, expected_output6) != 0) {
        printf("Test 6 Failed, Output -> %s || Expected_Output -> %s\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    return 0;
}

char *reverse_letter(const char *str) {
    char *return_str;
    char *str_copy = strdup(str);
    char *loop = str_copy;
    int length = 0;
    int letter_counter = 0;

    while (*loop != '\0') {
        if (*loop >= 97 && *loop <= 122) {
            ++letter_counter;
        }

        ++length;
        ++loop;
    }

    return_str = malloc(sizeof(char) * (letter_counter + 1);
    int count_up = 0;

    for (int i = length - 1; i >= 0; --i) {
        if (str_copy[i] >= 97 && str_copy[i] <= 122) {
            return_str[count_up] = str_copy[i];
            ++count_up;
        }
    }

    return_str[count_up] = '\0';

    return return_str;
}