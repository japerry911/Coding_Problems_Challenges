#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
---Disemvowel Trolls---
Trolls are attacking your comment section!

A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the
threat.

Your task is to write a function that takes a string and return a new string with all vowels removed.

For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".

Note: for this kata y isn't considered a vowel.
 */

char *disemvowel(const char *str);

int main() {
    // Disemvowel Trolls Kata Tests
    printf("Disemvowel Tests Beginning...\n");

    char *input1 = "This website is for losers LOL!";
    char *input2 = "What are you, a communist?";
    char *input3 = "nzPWMcRVezzwZZDbnupeVHlBpQP";
    char *input4 = "tE";

    char *output1 = disemvowel(input1);
    char *output2 = disemvowel(input2);
    char *output3 = disemvowel(input3);
    char *output4 = disemvowel(input4);

    char *expected_output1 = "Ths wbst s fr lsrs LL!";
    char *expected_output2 = "Wht r y,  cmmnst?";
    char *expected_output3 = "nzPWMcRVzzwZZDbnpVHlBpQP";
    char *expected_output4 = "t";

    if (strcmp(output1, expected_output1) != 0) {
        printf("\tTest1: Failed, returned - %s\n", output1);
    } else {
        printf("\tTest1: Passed, return - %s\n", output1);
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("\tTest2: Failed, returned - %s\n", output2);
    } else {
        printf("\tTest2: Passed, return - %s\n", output2);
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("\tTest3: Failed, returned - %s\n", output3);
    } else {
        printf("\tTest3: Passed, return - %s\n", output3);
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("\tTest4: Failed, returned - %s\n", output4);
    } else {
        printf("\tTest4: Passed, return - %s\n", output4);
    }

    return 0;
}

char *disemvowel(const char *str) {
    char vowels[] = "aeiou";
    int vowel_counter = 0;

    for (size_t i = 0; i < strlen(str); ++i) {
        for (size_t k = 0; k < 5; ++k) {
            if (tolower(str[i]) == vowels[k]) {
                ++vowel_counter;
                break;
            }
        }
    }

    char *return_str = malloc(sizeof(char) * (strlen(str) - vowel_counter));
    int return_str_index = 0;

    printf("Word: %s\n", str);
    printf("Length: %lu\n", strlen(str));
    printf("Vowel Count: %d\n", vowel_counter);

    int letters_added = 0;

    for (size_t i = 0; i < strlen(str); ++i) {
        int is_vowel = 0;

        for (size_t k = 0; k < 5; ++k) {
            if (tolower(str[i]) == vowels[k]) {
                is_vowel = 1;
                ++letters_added;
                break;
            }
        }

        if (is_vowel == 0) {
            return_str[return_str_index] = str[i];
            ++return_str_index;
        }
    }

    printf("Number of letters remaining in solution: %d\n", strlen(str) - letters_added);
    printf("\n-----------------------------------\n\n");

    return return_str;
}