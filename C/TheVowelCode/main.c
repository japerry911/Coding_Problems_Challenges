#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
---The Vowel Code---
Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according
to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown
above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.
 */

char *encode(const char *string);
char *decode(const char *string);

int main() {
    char *input1 = "hello";
    char *input2 = "How are you today?";
    char *input3 = "This is an encoding test.";
    char *input4 = "h2ll4";
    char *input5 = "H4w 1r2 y45 t4d1y?";
    char *input6 = "Th3s 3s 1n 2nc4d3ng t2st.";

    char *output1 = encode(input1);
    char *output2 = encode(input2);
    char *output3 = encode(input3);
    char *output4 = decode(input4);
    char *output5 = decode(input5);
    char *output6 = decode(input6);

    char *expected_output1 = "h2ll4";
    char *expected_output2 = "H4w 1r2 y45 t4d1y?";
    char *expected_output3 = "Th3s 3s 1n 2nc4d3ng t2st.";
    char *expected_output4 = "hello";
    char *expected_output5 = "How are you today?";
    char *expected_output6 = "This is an encoding test.";
    
    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed -> Output: %s || Expected_Output: %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed -> Output: %s || Expected_Output: %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed -> Output: %s || Expected_Output: %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed -> Output: %s || Expected_Output: %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (strcmp(output5, expected_output5) != 0) {
        printf("Test 5 Failed -> Output: %s || Expected_Output: %s\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (strcmp(output6, expected_output6) != 0) {
        printf("Test 6 Failed -> Output: %s || Expected_Output: %s\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    return 0;
}

char *encode(const char *string) {
    char *vowels_key[][2] = {
            {"a", "1"},
            {"e", "2"},
            {"i", "3"},
            {"o", "4"},
            {"u", "5"}
    };
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    char *return_string = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    bool is_vowel = false;
    int vowel_number = -1;

    for (int i = 0; i < strlen(string); ++i) {
        is_vowel = false;

        for (int v = 0; v < 5; ++v) {
            if (string[i] == vowels[v]) {
                is_vowel = true;
                vowel_number = v;
                break;
            }
        }

        if (is_vowel) {
            return_string[i] = *vowels_key[vowel_number][1];
        } else {
            return_string[i] = string[i];
        }
    }

    return_string[strlen(string)] = '\0';

    return return_string;
}

char *decode(const char *string) {
    char *vowels_key[][2] = {
            {"1", "a"},
            {"2", "e"},
            {"3", "i"},
            {"4", "o"},
            {"5", "u"}
    };

    char vowels[5] = {'1', '2', '3', '4', '5'};
    char *return_string = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    bool is_vowel = false;
    int vowel_number = -1;

    for (int i = 0; i < strlen(string); ++i) {
        is_vowel = false;

        for (int v = 0; v < 5; ++v) {
            if (string[i] == vowels[v]) {
                is_vowel = true;
                vowel_number = v;
                break;
            }
        }

        if (is_vowel) {
            return_string[i] = *vowels_key[vowel_number][1];
        } else {
            return_string[i] = string[i];
        }
    }

    return_string[strlen(string)] = '\0';

    return return_string;
}