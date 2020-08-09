#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

/*
---int32 to IPv4---
Take the following IPv4 address: 128.32.10.1

This address has 4 octets where each octet is a single byte (or 8 bits).

1st octet 128 has the binary representation: 10000000
2nd octet 32 has the binary representation: 00100000
3rd octet 10 has the binary representation: 00001010
4th octet 1 has the binary representation: 00000001
So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 2149583361

Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.

Examples
2149583361 ==> "128.32.10.1"
32         ==> "0.0.0.32"
0          ==> "0.0.0.0"
 */

void uint32_to_ip(uint32_t ip, char *output);

int main() {
    uint32_t input1 = 2154959208;
    uint32_t input2 = 0;
    uint32_t input3 = 2149583361;
    uint32_t input4 = 1804289383;
    uint32_t input5 = 4294967295;
    uint32_t input6 = 1783636305;
    uint32_t input7 = 746311195;

    char output1[16];
    char output2[16];
    char output3[16];
    char output4[16];
    char output5[16];
    char output6[16];
    char output7[16];

    char *expected_output1 = "128.114.17.104";
    char *expected_output2 = "0.0.0.0";
    char *expected_output3 = "128.32.10.1";
    char *expected_output4 = "107.139.69.103";
    char *expected_output5 = "255.255.255.255";
    char *expected_output6 = "106.80.33.81";
    char *expected_output7 = "44.123.206.27";

    uint32_to_ip(input1, output1);
    uint32_to_ip(input2, output2);
    uint32_to_ip(input3, output3);
    uint32_to_ip(input4, output4);
    uint32_to_ip(input5, output5);
    uint32_to_ip(input6, output6);
    uint32_to_ip(input7, output7);

    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed: output = %s || expected_output = %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed: output = %s || expected_output = %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed: output = %s || expected_output = %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed: output = %s || expected_output = %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    if (strcmp(output5, expected_output5) != 0) {
        printf("Test 5 Failed: output = %s || expected_output = %s\n", output5, expected_output5);
    } else {
        printf("Test 5 Passed.\n");
    }

    if (strcmp(output6, expected_output6) != 0) {
        printf("Test 6 Failed: output = %s || expected_output = %s\n", output6, expected_output6);
    } else {
        printf("Test 6 Passed.\n");
    }

    if (strcmp(output7, expected_output7) != 0) {
        printf("Test 7 Failed: output = %s || expected_output = %s\n", output7, expected_output7);
    } else {
        printf("Test 7 Passed.\n");
    }

    return 0;
}

void uint32_to_ip(uint32_t ip, char *output) {
    if (ip == 0) {
        sprintf(output, "%s", "0.0.0.0\0");
        return;
    }

    int binary[32];
    int counter = 31;

    while (ip > 0) {
        binary[counter] = ip % 2;

        --counter;
        ip /= 2;
    }

    if (counter >= 0) {
        do {
            binary[counter] = 0;
            --counter;
        } while (counter >= 0);
        counter = 0;
    } else {
        ++counter;
    }

    int octet_counter = 7;
    int octet_sum = 0;

    while (counter < 32) {
        if (octet_counter == -1) {
            sprintf(output, "%s%d.", output, octet_sum);
            octet_counter = 7;
            octet_sum = 0;
        }

        if (binary[counter] == 1) {
            octet_sum += floor(pow(2.0, octet_counter));
        }

        --octet_counter;
        ++counter;
    }

    sprintf(output, "%s%d%c", output, octet_sum, '\0');
}