#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
---Alphabet Wars - Reinforce Massacre---
There is a war and nobody knows - the alphabet war! The letters called airstrikes to help them in war -
dashes and dots are spread everywhere on the battlefield.

Task
Write a function that accepts reinforces array of strings and airstrikes array of strings.
The reinforces strings consist of only small letters. The size of each string in reinforces array is the same.
The airstrikes strings consists of * and white spaces. The size of each airstrike may vary. There may be also no
airstrikes at all.

The first row in reinforces array is the current battlefield. Whenever some letter is killed by bomb, it's replaced by
a letter from next string in reinforces array on the same position.
The airstrike always starts from the beginning of the battlefield.
The * means a bomb drop place. The each * bomb kills letter only on the battelfield. The bomb kills letter on the same
index on battlefield plus the adjacent letters.
The letters on the battlefield are replaced after airstrike is finished.
Return string of letters left on the battlefield after the last airstrike. In case there is no any letter left in
reinforces on specific position, return _.

reinforces = [ "abcdefg",
               "hijklmn"];
airstrikes = [ "   *   ",
               "*  *   "];

The battlefield  is     : "abcedfg".
The first airstrike    : "   *   "
After first airstrike  : "ab___fg"
Reinforces are comming : "abjklfg"
The second airstrike   : "*  *   "
After second airstrike : "_____fg"
Reinforces are coming  : "hi___fg"
No more airstrikes => return "hi___fg"
Other example
  reinforces =
          ["g964xxxxxxxx",
           "myjinxin2015",
           "steffenvogel",
           "smile67xxxxx",
           "giacomosorbi",
           "freywarxxxxx",
           "bkaesxxxxxxx",
           "vadimbxxxxxx",
           "zozofouchtra",
           "colbydauphxx" ];
airstrikes =
          ["* *** ** ***",
           " ** * * * **",
           " * *** * ***",
           " **  * * ** ",
           "* ** *   ***",
           "***   ",
           "**",
           "*",
           "*" ]
That should lead to:

alphabet_war(reinforces, airstrikes, 10, 9); // => codewarsxxx
 */

char *alphabet_war(const char *reinforces[], const char *airstrikes[], size_t nreinforce, size_t nairstrike);

int main() {
    const char *reinforces[][12] = {
            { "g964xxxxxxxx",
              "myjinxin2015",
              "steffenvogel",
              "smile67xxxxx",
              "giacomosorbi",
              "freywarxxxxx",
              "bkaesxxxxxxx",
              "vadimbxxxxxx",
              "zozofouchtra",
              "colbydauphxx"
            },
            { "abcdefg","hijklmn" },
            { "aaaaa","bbbbb", "ccccc", "ddddd" },
    };
    const size_t nreinforce[] = { 10ul, 2ul, 4ul };
    const size_t nairstrike[] = {  9ul, 2ul, 3ul };
    const char *airstrikes[][12] = {
            { "* *** ** ***",
              " ** * * * **",
              " * *** * ***",
              " **  * * ** ",
              "* ** *   ***",
              "***   ",
              "**",
              "*",
              "*"
            },
            { "   *   ", "*  *   " },
            { "*", " *", "   " },
            { "   *   ", "*  *   " }
    };

    char *output1 = alphabet_war(*reinforces, *airstrikes, *nreinforce, *nairstrike);
    char *output2 = alphabet_war(*(reinforces + 1), *(airstrikes + 1), *(nreinforce + 1), *(nairstrike + 1));
    char *output3 = alphabet_war(*(reinforces + 2), *(airstrikes + 2), *(nreinforce + 2), *(nairstrike + 2));

    char *expected_output1 = "codewarsxxxx";
    char *expected_output2 = "hi___fg";
    char *expected_output3 = "ccbaa";

    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed: Output1: %s || Expected_Output1: %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed: Output2: %s || Expected_Output2: %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed: Output3: %s || Expected_Output3: %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    free(output1);
    free(output2);
    free(output3);

    return 0;
}

char *alphabet_war(const char *reinforces[], const char *airstrikes[], size_t nreinforce, size_t nairstrike) {
    char *main_row = (char *)malloc(strlen(reinforces[0]) * sizeof(char));
    char **reinforces_copy = malloc(sizeof(char *) * (nreinforce - 1));
    int full_loop_break = 0;

    strcpy(main_row, reinforces[0]);
    for (size_t i = 1; i < nreinforce; ++i) {
        reinforces_copy[i - 1] = malloc(strlen(reinforces[0]) * sizeof(char*));
        strcpy(reinforces_copy[i - 1], *(reinforces + i));
    }

    for (size_t i = 0; i < nairstrike; ++i) {
        int reinforcements_needed = 0;
        int reinforcements_placed = 0;

        for (size_t a = 0; a < strlen(airstrikes[i]); ++a) {
            if (airstrikes[i][a] == '*') {
                if (a - 1 >= 0 && a + 1 < strlen(main_row)) {
                    main_row[a - 1] = '_';
                    main_row[a] = '_';
                    main_row[a + 1] = '_';

                    reinforcements_needed += 3;
                } else if (a == 0) {
                    main_row[a] = '_';
                    main_row[a + 1] = '_';

                    reinforcements_needed += 2;
                } else {
                    main_row[a - 1] = '_';
                    main_row[a] = '_';

                    reinforcements_needed += 2;
                }
            }
        }

        for (size_t s = 0; s < nreinforce; ++s) {
            for (size_t q = 0; q < strlen(main_row); ++q) {
                if (main_row[q] == '_' && reinforces_copy[s][q] != '_') {

                    main_row[q] = reinforces_copy[s][q];
                    reinforces_copy[s][q] = '_';

                    ++reinforcements_placed;

                    if (reinforcements_placed == reinforcements_needed) {
                        full_loop_break = 1;
                        break;
                    }
                }
            }

            if (full_loop_break) {
                break;
            }
        }
    }

    for (size_t i = 0; i < nreinforce - 1; ++i) {
        free(reinforces_copy[i]);
    }
    free(reinforces_copy);

    return main_row;
}