#include <stdio.h>
#include <string.h>
#include <math.h>

/*
---Write Number in Expanded Form Part 2---
Write Number in Expanded Form - Part 2
This is version 2 of my 'Write Number in Exanded Form' Kata.

You will be given a number and you will need to return it as a string in Expanded Form. For example:

expandedForm(1.24); // should return "1 + 2/10 + 4/100"
expandedForm(7.304); // should return "7 + 3/10 + 4/1000"
expandedForm(0.04); // should return "4/100"
 */

char *expanded_form(double n);

int main() {
    double input1 = 1.24;
    double input2 = 7.304;
    double input3 = 0.04;
    double input4 = 4.29;

    char *output1 = expanded_form(input1);
    char *output2 = expanded_form(input2);
    char *output3 = expanded_form(input3);
    char *output4 = expanded_form(input4);

    char *expected_output1 = "1 + 2/10 + 4/100";
    char *expected_output2 = "7 + 3/10 + 4/1000";
    char *expected_output3 = "4/100";
    char *expected_output4 = "4 + 2/10 + 8/100";
    
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

char *expanded_form(double n) {

    return "";
}