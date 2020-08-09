#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
---Grouped by Commas---
Finish the solution so that it takes an input n (integer) and returns a string that is the decimal representation of
the number grouped by commas after every 3 digits.

Assume: 0 <= n < 2147483647

Examples
       1  ->           "1"
      10  ->          "10"
     100  ->         "100"
    1000  ->       "1,000"
   10000  ->      "10,000"
  100000  ->     "100,000"
 1000000  ->   "1,000,000"
35235235  ->  "35,235,235"
 */

char *group_by_commas(int n);

int main() {
    int input1 = 1;
    int input2 = 10;
    int input3 = 100;
    int input4 = 1000;
    int input5 = 10000;
    int input6 = 100000;
    int input7 = 1000000;
    int input8 = 35235235;
    int input9 = 1234567890;
    int input10 = 12;

    char *output1 = group_by_commas(input1);
    char *output2 = group_by_commas(input2);
    char *output3 = group_by_commas(input3);
    char *output4 = group_by_commas(input4);
    char *output5 = group_by_commas(input5);
    char *output6 = group_by_commas(input6);
    char *output7 = group_by_commas(input7);
    char *output8 = group_by_commas(input8);
    char *output9 = group_by_commas(input9);
    char *output10 = group_by_commas(input10);

    char *expected_output1 = "1";
    char *expected_output2 = "10";
    char *expected_output3 = "100";
    char *expected_output4 = "1,000";
    char *expected_output5 = "10,000";
    char *expected_output6 = "100,000";
    char *expected_output7 = "1,000,000";
    char *expected_output8 = "35,235,235";
    char *expected_output9 = "1,234,567,890";
    char *expected_output10 = "12";

    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed, Output = %s || Expected_Output = %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed, Output = %s || Expected_Output = %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed, Output = %s || Expected_Output = %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed, Output = %s || Expected_Output = %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (strcmp(output5, expected_output5) != 0) {
        printf("Test 5 Failed, Output = %s || Expected_Output = %s\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (strcmp(output6, expected_output6) != 0) {
        printf("Test 6 Failed, Output = %s || Expected_Output = %s\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    if (strcmp(output7, expected_output7) != 0) {
        printf("Test 7 Failed, Output = %s || Expected_Output = %s\n", output7, expected_output7);
    } else {
        printf("Test 7 Passed.\n");
    }

    if (strcmp(output8, expected_output8) != 0) {
        printf("Test 8 Failed, Output = %s || Expected_Output = %s\n", output8, expected_output8);
    } else {
        printf("Test 8 Passed.\n");
    }

    if (strcmp(output9, expected_output9) != 0) {
        printf("Test 9 Failed, Output = %s || Expected_Output = %s\n", output9, expected_output9);
    } else {
        printf("Test 9 Passed.\n");
    }

    if (strcmp(output10, expected_output10) != 0) {
        printf("Test 10 Failed, Output = %s || Expected_Output = %s\n", output10, expected_output10);
    } else {
        printf("Test 10 Passed.\n");
    }

    return 0;
}

char *group_by_commas(int n) {
    int n_length = 0;
    int n_copy = n;
    char *staging_str;
    char *return_str;

    while (n_copy != 0) {
        n_copy /= 10;
        ++n_length;
    }

    int commas = floor(n_length / 3.0);
    staging_str = malloc(sizeof(char) * (n_length + commas + 1));
    return_str = malloc(sizeof(char) * (n_length + commas + 1));
    int comma_counter = 0;
    int position_counter = 0;

    while (n != 0) {
        if (comma_counter % 3 == 0 && comma_counter != 0) {
            staging_str[position_counter] = ',';
            ++position_counter;
        }

        sprintf(staging_str, "%s%d", staging_str, n % 10);

        ++comma_counter;
        ++position_counter;

        n /= 10;
    }

    staging_str[position_counter] = '\0';

    int count_up = 0;
    for (int i = position_counter - 1; i >= 0; --i) {
        return_str[count_up] = staging_str[i];
        ++count_up;
    }

    return_str[position_counter] = '\0';

    return return_str;
}