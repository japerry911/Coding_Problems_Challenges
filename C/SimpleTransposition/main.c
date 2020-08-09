#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
---Simple Transposition---
Simple transposition is a basic and simple cryptography technique. We make 2 rows and put first a letter in the Row 1,
the second in the Row 2, third in Row 1 and so on until the end. Then we put the text from Row 2 next to the Row 1 text
and thats it.

Complete the function that recieves a string and encrypt it with this simple transposition.

Example
For example if the text to encrypt is: "Simple text", the 2 rows will be:

Row 1	S	m	l		e	t
Row 2	i	p	e	t	x

So the result string will be: `"Sml etipetx"`
 */

char *simple_transposition(const char *s);

int main() {
    char *input1 = "Simple text";
    char *input2 = "Sample text";
    char *input3 = "Simple transposition";
    char *input4 = "All that glitters is not gold";
    char *input5 = "The better part of valor is discretion";
    char *input6 = "Conscience does make cowards of us all";
    char *input7 = "Imagination is more important than knowledge";

    char *output1 = simple_transposition(input1);
    char *output2 = simple_transposition(input2);
    char *output3 = simple_transposition(input3);
    char *output4 = simple_transposition(input4);
    char *output5 = simple_transposition(input5);
    char *output6 = simple_transposition(input6);
    char *output7 = simple_transposition(input7);

    char *expected_output1 = "Sml etipetx";
    char *expected_output2 = "Sml etapetx";
    char *expected_output3 = "Sml rnpstoipetasoiin";
    char *expected_output4 = "Alta ltesi o odl htgitr sntgl";
    char *expected_output5 = "Tebte ato ao sdsrtoh etrpr fvlri icein";
    char *expected_output6 = "Cncec osmk oad fu losinede aecwrso sal";
    char *expected_output7 = "Iaiaini oeipratta nwegmgnto smr motn hnkolde";
    
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

    if (strcmp(output5, expected_output5) != 0) {
        printf("Test 5 Failed: Output = %s || Expected_Output = %s\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (strcmp(output6, expected_output6) != 0) {
        printf("Test 6 Failed: Output = %s || Expected_Output = %s\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    if (strcmp(output7, expected_output7) != 0) {
        printf("Test 7 Failed: Output = %s || Expected_Output = %s\n", output7, expected_output7);
    } else {
        printf("Test 7 Passed.\n");
    }

    return 0;
}

char *simple_transposition(const char *s) {
    char *return_string = (char *)malloc((strlen(s) + 1) * sizeof(char));
    int counter = 0;

    for (int i = 0; i < strlen(s); i += 2) {
        return_string[counter] = s[i];
        ++counter;
    }

    for (int i = 1; i < strlen(s); i += 2) {
        return_string[counter] = s[i];
        ++counter;
    }

    return_string[counter] = '\0';

    return return_string;
}