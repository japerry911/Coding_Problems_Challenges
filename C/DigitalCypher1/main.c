#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
---Digital Cypher 1---
Digital Cypher assigns to each letter of the alphabet unique number. For example:

 a  b  c  d  e  f  g  h  i  j  k  l  m
 1  2  3  4  5  6  7  8  9 10 11 12 13
 n  o  p  q  r  s  t  u  v  w  x  y  z
14 15 16 17 18 19 20 21 22 23 24 25 26
Instead of letters in encrypted word we write the corresponding number, eg. The word scout:

 s  c  o  u  t
19  3 15 21 20
Then we add to each obtained digit consecutive digits from the key. For example. In case of key equal to 1939 :

   s  c  o  u  t
  19  3 15 21 20
 + 1  9  3  9  1
 ---------------
  20 12 18 30 21

   m  a  s  t  e  r  p  i  e  c  e
  13  1 19 20  5 18 16  9  5  3  5
+  1  9  3  9  1  9  3  9  1  9  3
  --------------------------------
  14 10 22 29  6 27 19 18  6  12 8
Task
Write a function that accepts str string and key number and returns an array of integers representing encoded str.

Input / Output
The str input string consists of lowercase characters only.
The key input number is a positive integer.

Example
Encode("scout",1939);  ==>  [ 20, 12, 18, 30, 21]
Encode("masterpiece",1939);  ==>  [ 14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
 */

unsigned char *encode(const char *s, unsigned k);
bool compare_arrays(const unsigned char *a, const unsigned char *b, size_t size);

int main() {
    const char *input1a = "scout";
    const char *input2a = "masterpiece";

    unsigned input1b = 1939;
    unsigned input2b = 1939;

    unsigned char *output1 = encode(input1a, input2b);
    unsigned char *output2 = encode(input2a, input2b);

    unsigned char *expected_output1 = (unsigned char[]){20, 12, 18, 30, 21};
    unsigned char *expected_output2 = (unsigned char[]){14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8};

    if (compare_arrays(output1, expected_output1, 5)) {
        printf("Test 1 Passed\n");
    } else {
        printf("Test 1 Failed\n");
    }
    free(output1);

    if (compare_arrays(output2, expected_output2, 11)) {
        printf("Test 2 Passed\n");
    } else {
        printf("Test 2 Failed\n");
    }
    free(output2);

    return 0;
}

unsigned char *encode(const char *s, unsigned k) {
    unsigned char *encrypted_string = calloc(strlen(s), sizeof(unsigned char));
    int key_length = (int)log10(k);
    char key_str[key_length];
    int key_index = 0;
    sprintf(key_str, "%u", k);

    for (int i = 0; i < strlen(s); ++i) {
        encrypted_string[i] = (unsigned char)(s[i] - 96 + key_str[key_index] - 48);
        ++key_index;
        if (key_index >= strlen(key_str)) {
            key_index = 0;
        }
    }

    return encrypted_string;
}

bool compare_arrays(const unsigned char *a, const unsigned char *b, size_t size) {
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}