//
// Created by John Perry on 2020-06-24.
//

#include <gtest/gtest.h>
#include "CodeWars.h"
#include <string>
#include <vector>
#include <tuple>

// Mumbling Kata Tests

/*TEST(Mumbling_Tests, mumbling) {
    std::string input1 = "abcd";
    std::string input2 = "RqaEzty";
    std::string input3 = "cwAt";
    std::string input4 = "ZpglnRxqenU";
    std::string input5 = "NyffsGeyylB";

    std::string expected_output1 = "A-Bb-Ccc-Dddd";
    std::string expected_output2 = "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy";
    std::string expected_output3 = "C-Ww-Aaa-Tttt";
    std::string expected_output4 = "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu";
    std::string expected_output5 = "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb";

    std::string output1 = CodeWars().mumbling(input1);
    std::string output2 = CodeWars().mumbling(input2);
    std::string output3 = CodeWars().mumbling(input3);
    std::string output4 = CodeWars().mumbling(input4);
    std::string output5 = CodeWars().mumbling(input5);

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Alternating Split Kata Tests

/*TEST(Alternating_Split_Tests, encrypt_alternating_split) {
    std::string input_string1 = "This is a test!";
    std::string input_string2 = "This is a test!";
    std::string input_string3 = "This is a test!";
    std::string input_string4 = "This is a test!";
    std::string input_string5 = "This is a test!";
    std::string input_string6 = "This is a test!";
    std::string input_string7 = "This kata is very interesting!";

    int input_int1 = 0;
    int input_int2 = 1;
    int input_int3 = 2;
    int input_int4 = 3;
    int input_int5 = 4;
    int input_int6 = -1;
    int input_int7 = 1;

    std::string expected_output1 = "This is a test!";
    std::string expected_output2 = "hsi  etTi sats!";
    std::string expected_output3 = "s eT ashi tist!";
    std::string expected_output4 = " Tah itse sits!";
    std::string expected_output5 = "This is a test!";
    std::string expected_output6 = "This is a test!";
    std::string expected_output7 = "hskt svr neetn!Ti aai eyitrsig";

    std::string output1 = CodeWars().encrypt_alternating_split(input_string1, input_int1);
    std::string output2 = CodeWars().encrypt_alternating_split(input_string2, input_int2);
    std::string output3 = CodeWars().encrypt_alternating_split(input_string3, input_int3);
    std::string output4 = CodeWars().encrypt_alternating_split(input_string4, input_int4);
    std::string output5 = CodeWars().encrypt_alternating_split(input_string5, input_int5);
    std::string output6 = CodeWars().encrypt_alternating_split(input_string6, input_int6);
    std::string output7 = CodeWars().encrypt_alternating_split(input_string7, input_int7);

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}

TEST(Alternating_Split_Tests, decrypt_alternating_split) {
    std::string input_string1 = "This is a test!";
    std::string input_string2 = "hsi  etTi sats!";
    std::string input_string3 = "s eT ashi tist!";
    std::string input_string4 = " Tah itse sits!";
    std::string input_string5 = "This is a test!";
    std::string input_string6 = "This is a test!";
    std::string input_string7 = "hskt svr neetn!Ti aai eyitrsig";

    int input_int1 = 0;
    int input_int2 = 1;
    int input_int3 = 2;
    int input_int4 = 3;
    int input_int5 = 4;
    int input_int6 = -1;
    int input_int7 = 1;

    std::string expected_output1 = "This is a test!";
    std::string expected_output2 = "This is a test!";
    std::string expected_output3 = "This is a test!";
    std::string expected_output4 = "This is a test!";
    std::string expected_output5 = "This is a test!";
    std::string expected_output6 = "This is a test!";
    std::string expected_output7 = "This kata is very interesting!";

    std::string output1 = CodeWars().decrypt_alternating_split(input_string1, input_int1);
    std::string output2 = CodeWars().decrypt_alternating_split(input_string2, input_int2);
    std::string output3 = CodeWars().decrypt_alternating_split(input_string3, input_int3);
    std::string output4 = CodeWars().decrypt_alternating_split(input_string4, input_int4);
    std::string output5 = CodeWars().decrypt_alternating_split(input_string5, input_int5);
    std::string output6 = CodeWars().decrypt_alternating_split(input_string6, input_int6);
    std::string output7 = CodeWars().decrypt_alternating_split(input_string7, input_int7);

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Take a Ten Minute Walk Kata Tests

/*TEST(Take_a_Ten_Minute_Walk, is_valid_walk) {
    std::vector<char> input1 = {'n'};
    std::vector<char> input2 = {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'};
    std::vector<char> input3 = { 'n', 's'};
    std::vector<char> input4 = {'n','s','n','s','n','s','n','s','n','s','n','s'};
    std::vector<char> input5 = {'e','w','e','w','n','s','n','s','e','w'};
    std::vector<char> input6 = {'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'};
    std::vector<char> input7 = {'n','s','e','w','n','s','e','w','n','s'};
    std::vector<char> input8 = {'s','e','w','n','n','s','e','w','n','s'};
    std::vector<char> input9 = {'n','s','n','s','n','s','n','s','n','n'};
    std::vector<char> input10 = {'e','e','e','w','n','s','n','s','e','w'};

    EXPECT_FALSE(CodeWars().is_valid_walk(input1));
    EXPECT_TRUE(CodeWars().is_valid_walk(input2));
    EXPECT_FALSE(CodeWars().is_valid_walk(input3));
    EXPECT_FALSE(CodeWars().is_valid_walk(input4));
    EXPECT_TRUE(CodeWars().is_valid_walk(input5));
    EXPECT_FALSE(CodeWars().is_valid_walk(input6));
    EXPECT_TRUE(CodeWars().is_valid_walk(input7));
    EXPECT_TRUE(CodeWars().is_valid_walk(input8));
    EXPECT_FALSE(CodeWars().is_valid_walk(input9));
    EXPECT_FALSE(CodeWars().is_valid_walk(input10));
}*/

// ----------------------------------------------------------------------------------------------------------

// Bit Counting Kata Tests

/*TEST(Bit_Counting, count_bits) {
    unsigned long long input1 = 0;
    unsigned long long input2 = 4;
    unsigned long long input3 = 7;
    unsigned long long input4 = 9;
    unsigned long long input5 = 10;
    unsigned long long input6 = 26;
    unsigned long long input7 = 77231418;
    unsigned long long input8 = 12525589;
    unsigned long long input9 = 3811;
    unsigned long long input10 = 392902058;

    unsigned int output1 = CodeWars().count_bits(input1);
    unsigned int output2 = CodeWars().count_bits(input2);
    unsigned int output3 = CodeWars().count_bits(input3);
    unsigned int output4 = CodeWars().count_bits(input4);
    unsigned int output5 = CodeWars().count_bits(input5);
    unsigned int output6 = CodeWars().count_bits(input6);
    unsigned int output7 = CodeWars().count_bits(input7);
    unsigned int output8 = CodeWars().count_bits(input8);
    unsigned int output9 = CodeWars().count_bits(input9);
    unsigned int output10 = CodeWars().count_bits(input10);

    unsigned int expected_output1 = 0;
    unsigned int expected_output2 = 1;
    unsigned int expected_output3 = 3;
    unsigned int expected_output4 = 2;
    unsigned int expected_output5 = 2;
    unsigned int expected_output6 = 3;
    unsigned int expected_output7 = 14;
    unsigned int expected_output8 = 11;
    unsigned int expected_output9 = 8;
    unsigned int expected_output10 = 17;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4,expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
}*/

// ----------------------------------------------------------------------------------------------------------

// Consecutive Strings Kata Tests

/*TEST(Consecutive_Strings, longest_consec) {
    std::vector<std::string> input1 = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    std::vector<std::string> input2 = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb",
                                       "oocccffuucccjjjkkkjyyyeehh"};
    int k1 = 2;
    int k2 = 1;

    std::string output1 = CodeWars().longest_consec(input1, k1);
    std::string output2 = CodeWars().longest_consec(input2, k2);

    std::string expected_output1 = "abigailtheta";
    std::string expected_output2 = "oocccffuucccjjjkkkjyyyeehh";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
}*/

// ----------------------------------------------------------------------------------------------------------

// Alternate Capitalization Kata Tests

/*TEST(Alternate_Capitalization, capitalize) {
    std::string input1 = "abcdef";
    std::string input2 = "codewars";
    std::string input3 = "abracadabra";
    std::string input4 = "codewarriors";

    std::pair<std::string, std::string> output1 = CodeWars().capitalize(input1);
    std::pair<std::string, std::string> output2 = CodeWars().capitalize(input2);
    std::pair<std::string, std::string> output3 = CodeWars().capitalize(input3);
    std::pair<std::string, std::string> output4 = CodeWars().capitalize(input4);

    std::pair<std::string, std::string> expected_output1 = {"AbCdEf", "aBcDeF"};
    std::pair<std::string, std::string> expected_output2 = {"CoDeWaRs", "cOdEwArS"};
    std::pair<std::string, std::string> expected_output3 = {"AbRaCaDaBrA", "aBrAcAdAbRa"};
    std::pair<std::string, std::string> expected_output4 = {"CoDeWaRrIoRs", "cOdEwArRiOrS"};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
}*/

// ----------------------------------------------------------------------------------------------------------

// Sums of Parts Kata Tests

/*TEST(SumsOfParts, parts_sum) {
    std::vector<unsigned long long> input1 = {0, 1, 3, 6, 10};
    std::vector<unsigned long long> input2 = {1, 2, 3, 4, 5, 6};
    std::vector<unsigned long long> input3 = {744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358};
    std::vector<unsigned long long> input4 = {30350, 76431, 156228, 78043, 98977, 80169, 32457, 182875, 162323, 17508,
                                              57971, 171907};
    std::vector<unsigned long long> input5 = {158077, 143494, 196531, 26272, 35656, 68756, 109861, 36958, 83895, 134127,
                                              81618, 193758, 143422};

    std::vector<unsigned long long> output1 = CodeWars().parts_sum(input1);
    std::vector<unsigned long long> output2 = CodeWars().parts_sum(input2);
    std::vector<unsigned long long> output3 = CodeWars().parts_sum(input3);
    std::vector<unsigned long long> output4 = CodeWars().parts_sum(input4);
    std::vector<unsigned long long> output5 = CodeWars().parts_sum(input5);

    std::vector<unsigned long long> expected_output1 = {20, 20, 19, 16, 10, 0};
    std::vector<unsigned long long> expected_output2 = {21, 20, 18, 15, 11, 6, 0};
    std::vector<unsigned long long> expected_output3 = {10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414,
                                                        9291270, 2581057, 2580168, 2579358, 0};
    std::vector<unsigned long long> expected_output4 = {1145239, 1114889, 1038458, 882230, 804187, 705210, 625041,
                                                        592584, 409709, 247386, 229878, 171907, 0};
    std::vector<unsigned long long> expected_output5 = {1412425, 1254348, 1110854, 914323, 888051, 852395, 783639,
                                                        673778, 636820, 552925, 418798, 337180, 143422, 0};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Validate Credit Card Number Kata Tests

/*TEST(Validate_Credit_Card_Number, validate) {
    unsigned long long input1 = 891;
    unsigned long long input2 = 2121;
    unsigned long long input3 = 2030;
    unsigned long long input4 = 1714636915;

    bool output1 = CodeWars().validate(input1);
    bool output2 = CodeWars().validate(input2);
    bool output3 = CodeWars().validate(input3);
    bool output4 = CodeWars().validate(input4);

    EXPECT_FALSE(output1);
    EXPECT_TRUE(output2);
    EXPECT_TRUE(output3);
    EXPECT_TRUE(output4);
}*/

// ----------------------------------------------------------------------------------------------------------

// Help the Bookseller! Kata Tests

/*TEST(Help_the_Bookseller, stock_summary) {
    std::vector<std::string> input_lst1 = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> input_lst2 = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"};
    std::vector<std::string> input_lst3 = {"ABAR 200"};
    std::vector<std::string> input_lst4 = {};
    std::vector<std::string> input_lst5 = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};

    std::vector<std::string> input_cat1 = {"A", "B"};
    std::vector<std::string> input_cat2 ={"A", "B", "C", "W"};
    std::vector<std::string> input_cat3 = {};
    std::vector<std::string> input_cat4 = {"A"};
    std::vector<std::string> input_cat5 = {"A", "B", "C", "D"};

    std::string output1 = CodeWars().stock_summary(input_lst1, input_cat1);
    std::string output2 = CodeWars().stock_summary(input_lst2, input_cat2);
    std::string output3 = CodeWars().stock_summary(input_lst3, input_cat3);
    std::string output4 = CodeWars().stock_summary(input_lst4, input_cat4);
    std::string output5 = CodeWars().stock_summary(input_lst5, input_cat5);

    std::string expected_output1 = "(A : 200) - (B : 1140)";
    std::string expected_output2 = "(A : 20) - (B : 114) - (C : 50) - (W : 0)";
    std::string expected_output3 = "";
    std::string expected_output4 = "";
    std::string expected_output5 = "(A : 0) - (B : 1290) - (C : 515) - (D : 600)";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3,expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// The Deaf Rats of Hamelin Kata Tests

/*TEST(The_Deaf_Rats_of_Hamelin, count_deaf_rats) {
    std::string input1 = "~O~O~O~O P";
    std::string input2 = "P O~ O~ ~O O~";
    std::string input3 = "~O~O~O~OP~O~OO~";

    int output1 = CodeWars().count_deaf_rats(input1);
    int output2 = CodeWars().count_deaf_rats(input2);
    int output3 = CodeWars().count_deaf_rats(input3);

    int expected_output1 = 0;
    int expected_output2 = 1;
    int expected_output3 = 2;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Roman Numerals Encoder Kata Tests

/*TEST(Roman_Numerals_Encoder, solution) {
    int input1 = 182;
    int input2 = 1990;
    int input3 = 1875;
    int input4 = 2000;
    int input5 = 1500;
    int input6 = 1290;
    int input7 = 1298;
    int input8 = 4;
    int input9 = 3744;
    int input10 = 3412;

    std::string output1 = CodeWars().solution(input1);
    std::string output2 = CodeWars().solution(input2);
    std::string output3 = CodeWars().solution(input3);
    std::string output4 = CodeWars().solution(input4);
    std::string output5 = CodeWars().solution(input5);
    std::string output6 = CodeWars().solution(input6);
    std::string output7 = CodeWars().solution(input7);
    std::string output8 = CodeWars().solution(input8);
    std::string output9 = CodeWars().solution(input9);
    std::string output10 = CodeWars().solution(input10);

    std::string expected_output1 = "CLXXXII";
    std::string expected_output2 = "MCMXC";
    std::string expected_output3 = "MDCCCLXXV";
    std::string expected_output4 = "MM";
    std::string expected_output5 = "MD";
    std::string expected_output6 = "MCCXC";
    std::string expected_output7 = "MCCXCVIII";
    std::string expected_output8 = "IV";
    std::string expected_output9 = "MMMDCCXLIV";
    std::string expected_output10 = "MMMCDXII";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
}*/

// ----------------------------------------------------------------------------------------------------------

// Primorial of a Number Kata Tests

/*TEST(Primorial_of_a_Number, num_primorial) {
    unsigned short int input1 = 3;
    unsigned short int input2 = 4;
    unsigned short int input3 = 5;
    unsigned short int input4 = 8;
    unsigned short int input5 = 9;

    unsigned long long output1 = CodeWars().num_primorial(input1);
    unsigned long long output2 = CodeWars().num_primorial(input2);
    unsigned long long output3 = CodeWars().num_primorial(input3);
    unsigned long long output4 = CodeWars().num_primorial(input4);
    unsigned long long output5 = CodeWars().num_primorial(input5);

    unsigned long long expected_output1 = 30;
    unsigned long long expected_output2 = 210;
    unsigned long long expected_output3 = 2310;
    unsigned long long expected_output4 = 9699690;
    unsigned long long expected_output5 = 223092870;

    EXPECT_EQ(output1 ,expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Convert all the Cases! Kata Tests

/*TEST(Convert_all_the_Cases, change_case) {
    std::string input1 = "snakeCase";
    std::string input2 = "some-lisp-name";
    std::string input3 = "map_to_all";
    std::string input4 = "doHTMLRequest";
    std::string input5 = "invalid-inPut_bad";
    std::string input6 = "valid-input";
    std::string input7 = "";
    std::string input8 = "snake-kebab_case";
    std::string input9 = "snakeCamel_case";
    std::string input10 = "kebabCamel-case";
    std::string input11 = "case-Camel";

    std::string target_case1 = "snake";
    std::string target_case2 = "camel";
    std::string target_case3 = "kebab";
    std::string target_case4 = "kebab";
    std::string target_case5 = "kebab";
    std::string target_case6 = "huh???";
    std::string target_case7 = "camel";
    std::string target_case8 = "kebab";
    std::string target_case9 = "snake";
    std::string target_case10 = "snake";
    std::string target_case11 = "kebab";

    std::string output1 = CodeWars().change_case(input1, target_case1);
    std::string output2 = CodeWars().change_case(input2, target_case2);
    std::string output3 = CodeWars().change_case(input3, target_case3);
    std::string output4 = CodeWars().change_case(input4, target_case4);
    std::string output5 = CodeWars().change_case(input5, target_case5);
    std::string output6 = CodeWars().change_case(input6, target_case6);
    std::string output7 = CodeWars().change_case(input7, target_case7);
    std::string output8 = CodeWars().change_case(input8, target_case8);
    std::string output9 = CodeWars().change_case(input9, target_case9);
    std::string output10 = CodeWars().change_case(input10, target_case10);
    std::string output11 = CodeWars().change_case(input11, target_case11);

    std::string expected_output1 = "snake_case";
    std::string expected_output2 = "someLispName";
    std::string expected_output3 = "map-to-all";
    std::string expected_output4 = "do-h-t-m-l-request";
    std::string expected_output5 = "";
    std::string expected_output6 = "";
    std::string expected_output7 = "";
    std::string expected_output8 = "";
    std::string expected_output9 = "";
    std::string expected_output10 = "";
    std::string expected_output11 = "";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
    EXPECT_EQ(output11, expected_output11);
}*/

// ----------------------------------------------------------------------------------------------------------

// Sudoku Solution Validator Kata Tests

/*TEST(Sudoku_Solution_Validator, valid_solution) {
    unsigned int input1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                 {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                 {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                 {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                 {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                 {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                 {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                 {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                 {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    unsigned int input2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                 {6, 7, 2, 1, 9, 0, 3, 4, 8},
                                 {1, 0, 0, 3, 4, 2, 5, 6, 0},
                                 {8, 5, 9, 7, 6, 1, 0, 2, 0},
                                 {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                 {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                 {9, 0, 1, 5, 3, 7, 2, 1, 4},
                                 {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                 {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    bool output1 = CodeWars().valid_solution(input1);
    bool output2 = CodeWars().valid_solution(input2);

    EXPECT_TRUE(output1);
    EXPECT_FALSE(output2);
}*/

// ----------------------------------------------------------------------------------------------------------

// Explosive Sum Kata Tests - Not Solved

/*TEST(Explosive_Sum, exp_sum) {
    unsigned int input1 = 1;
    unsigned int input2 = 2;
    unsigned int input3 = 3;
    unsigned int input4 = 4;
    unsigned int input5 = 5;
    unsigned int input6 = 10;
    unsigned int input7 = 50;
    unsigned int input8 = 80;
    unsigned int input9 = 100;
    unsigned int input10 = 137;

    unsigned long long output1 = CodeWars().exp_sum(input1);
    unsigned long long output2 = CodeWars().exp_sum(input2);
    unsigned long long output3 = CodeWars().exp_sum(input3);
    unsigned long long output4 = CodeWars().exp_sum(input4);
    unsigned long long output5 = CodeWars().exp_sum(input5);
    unsigned long long output6 = CodeWars().exp_sum(input6);
    unsigned long long output7 = CodeWars().exp_sum(input7);
    unsigned long long output8 = CodeWars().exp_sum(input8);
    unsigned long long output9 = CodeWars().exp_sum(input9);
    unsigned long long output10 = CodeWars().exp_sum(input10);

    unsigned long long expected_output1 = 1;
    unsigned long long expected_output2 = 2;
    unsigned long long expected_output3 = 3;
    unsigned long long expected_output4 = 5;
    unsigned long long expected_output5 = 7;
    unsigned long long expected_output6 = 42;
    unsigned long long expected_output7 = 204226;
    unsigned long long expected_output8 = 15796476;
    unsigned long long expected_output9 = 190569292;
    unsigned long long expected_output10 = 11097645016;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
}*/

// ----------------------------------------------------------------------------------------------------------

// Unwanted Dollars Kata Tests

/*TEST(Unwanted_Dollars, money_value) {
    std::string input1 = "12.34";
    std::string input2 = "$5.67";
    std::string input3 = "-0.89";
    std::string input4 = "-$ 0.1";
    std::string input5 = "$-2.3456";
    std::string input6 = "007";
    std::string input7 = " $ 89";
    std::string input8 = "   .11";
    std::string input9 = "$.2";
    std::string input10 = "-.34";
    std::string input11 = "$$$";
    std::string input12 = "$$23.56";

    double output1 = CodeWars().money_value(input1);
    double output2 = CodeWars().money_value(input2);
    double output3 = CodeWars().money_value(input3);
    double output4 = CodeWars().money_value(input4);
    double output5 = CodeWars().money_value(input5);
    double output6 = CodeWars().money_value(input6);
    double output7 = CodeWars().money_value(input7);
    double output8 = CodeWars().money_value(input8);
    double output9 = CodeWars().money_value(input9);
    double output10 = CodeWars().money_value(input10);
    double output11 = CodeWars().money_value(input11);
    double output12 = CodeWars().money_value(input12);

    double expected_output1 = 12.34;
    double expected_output2 = 5.67;
    double expected_output3 = -0.89;
    double expected_output4 = -0.10;
    double expected_output5 = -2.3456;
    double expected_output6 = 7.00;
    double expected_output7 = 89.0;
    double expected_output8 = 0.11;
    double expected_output9 = 0.20;
    double expected_output10 = -0.34;
    double expected_output11 = 0.0;
    double expected_output12 = 23.56;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
    EXPECT_EQ(output11, expected_output11);
    EXPECT_EQ(output12, expected_output12);
}*/

// ----------------------------------------------------------------------------------------------------------

// Help Mrs Jefferson Kata Tests

/*TEST(Help_Mrs_Jefferson, shortest_arrang) {
    int input1 = 16;
    int input2 = 10;
    int input3 = 22;
    int input4 = 65;

    std::vector<int> output1 = CodeWars().shortest_arrang(input1);
    std::vector<int> output2 = CodeWars().shortest_arrang(input2);
    std::vector<int> output3 = CodeWars().shortest_arrang(input3);
    std::vector<int> output4 = CodeWars().shortest_arrang(input4);

    std::vector<int> expected_output1 = {-1};
    std::vector<int> expected_output2 = {4, 3, 2, 1};
    std::vector<int> expected_output3 = {7, 6, 5, 4};
    std::vector<int> expected_output4 = {33, 32};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
}*/

// ----------------------------------------------------------------------------------------------------------

// Alphabet War - Airstrike - Letters Massacre Kata Tests

/*TEST(Alphabet_War_Airstrike_Letters_Massacre, alphabet_war) {
    std::string input1 = "z";
    std::string input2 = "****";
    std::string input3 = "z*dq*mw*pb*s";
    std::string input4 = "zdqmwpbs";
    std::string input5 = "zz*zzs";
    std::string input6 = "wwwwww*z*";
    std::string input7 = "*ww*ww*w*wz";
    std::string input8 = "s*zz";
    std::string input9 = "*zd*qm*wp*bs*";
    std::string input10 = "zzzz*s*";
    std::string input11 = "www*www****z";
    std::string input12 = "mgx";
    std::string input13 = "sl*p*k*d*";
    std::string input14 = "u*vtn*ab";

    std::string output1 = CodeWars().alphabet_war(input1);
    std::string output2 = CodeWars().alphabet_war(input2);
    std::string output3 = CodeWars().alphabet_war(input3);
    std::string output4 = CodeWars().alphabet_war(input4);
    std::string output5 = CodeWars().alphabet_war(input5);
    std::string output6 = CodeWars().alphabet_war(input6);
    std::string output7 = CodeWars().alphabet_war(input7);
    std::string output8 = CodeWars().alphabet_war(input8);
    std::string output9 = CodeWars().alphabet_war(input9);
    std::string output10 = CodeWars().alphabet_war(input10);
    std::string output11 = CodeWars().alphabet_war(input11);
    std::string output12 = CodeWars().alphabet_war(input12);
    std::string output13 = CodeWars().alphabet_war(input13);
    std::string output14 = CodeWars().alphabet_war(input14);

    std::string expected_output1 = "Right side wins!";
    std::string expected_output2 = "Let's fight again!";
    std::string expected_output3 = "Let's fight again!";
    std::string expected_output4 = "Let's fight again!";
    std::string expected_output5 = "Right side wins!";
    std::string expected_output6 = "Left side wins!";
    std::string expected_output7 = "Right side wins!";
    std::string expected_output8 = "Right side wins!";
    std::string expected_output9 = "Let's fight again!";
    std::string expected_output10 = "Right side wins!";
    std::string expected_output11 = "Left side wins!";
    std::string expected_output12 = "Right side wins!";
    std::string expected_output13 = "Left side wins!";
    std::string expected_output14 = "Left side wins!";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
    EXPECT_EQ(output11, expected_output11);
    EXPECT_EQ(output12, expected_output12);
    EXPECT_EQ(output13, expected_output13);
    EXPECT_EQ(output14, expected_output14);
}*/

// ----------------------------------------------------------------------------------------------------------

// Complete the Pattern #8 - Number Pyramid Kata Tests

/*TEST(Complete_the_Pattern_8_Number_Pyramid, pattern) {
    int input1 = 0;
    int input2 = -25;
    int input3 = 1;
    int input4 = 4;
    int input5 = 7;
    int input6 = 20;

    std::string output1 = CodeWars().pattern(input1);
    std::string output2 = CodeWars().pattern(input2);
    std::string output3 = CodeWars().pattern(input3);
    std::string output4 = CodeWars().pattern(input4);
    std::string output5 = CodeWars().pattern(input5);
    std::string output6 = CodeWars().pattern(input6);

    std::string expected_output1 = "";
    std::string expected_output2 = "";
    std::string expected_output3 = "1";
    std::string expected_output4 = "   1   \n  121  \n 12321 \n1234321";
    std::string expected_output5 = (std::string)"      1      \n     121     \n    12321    \n   1234321   \n  " +
            "123454321  \n 12345654321 \n1234567654321";
    std::string expected_output6 = (std::string)"                   1                   \n" +
            "                  121                  \n" +
            "                 12321                 \n" +
            "                1234321                \n" +
            "               123454321               \n" +
            "              12345654321              \n" +
            "             1234567654321             \n" +
            "            123456787654321            \n" +
            "           12345678987654321           \n" +
            "          1234567890987654321          \n" +
            "         123456789010987654321         \n" +
            "        12345678901210987654321        \n" +
            "       1234567890123210987654321       \n" +
            "      123456789012343210987654321      \n" +
            "     12345678901234543210987654321     \n" +
            "    1234567890123456543210987654321    \n" +
            "   123456789012345676543210987654321   \n" +
            "  12345678901234567876543210987654321  \n" +
            " 1234567890123456789876543210987654321 \n" +
            "123456789012345678909876543210987654321";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
}*/

// ----------------------------------------------------------------------------------------------------------

// Strings Mix Kata Tests

/*TEST(Strings_Mix, mix) {
    std::string input1a = "A aaaa bb c";
    std::string input2a = "my&friend&Paul has heavy hats! &";
    std::string input3a = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
    std::string input4a = "Are the kids at home? aaaaa fffff";
    std::string input5a = "Are they here";
    std::string input6a = "looping is fun but dangerous";
    std::string input7a = "codewars";

    std::string input1b = "& aaa bbb c d";
    std::string input2b = "my friend John has many many friends &";
    std::string input3b = "my frie n d Joh n has ma n y ma n y frie n ds n&";
    std::string input4b = "Yes they are here! aaaaa fffff";
    std::string input5b = "yes, they are here";
    std::string input6b = "less dangerous than coding";
    std::string input7b = "codewars";

    std::string output1 = CodeWars().mix(input1a, input1b);
    std::string output2 = CodeWars().mix(input2a, input2b);
    std::string output3 = CodeWars().mix(input3a, input3b);
    std::string output4 = CodeWars().mix(input4a, input4b);
    std::string output5 = CodeWars().mix(input5a, input5b);
    std::string output6 = CodeWars().mix(input6a, input6b);
    std::string output7 = CodeWars().mix(input7a, input7b);

    std::string expected_output1 = "1:aaaa/2:bbb";
    std::string expected_output2 = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    std::string expected_output3 = "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    std::string expected_output4 = "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh";
    std::string expected_output5 = "2:eeeee/2:yy/=:hh/=:rr";
    std::string expected_output6 = "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg";
    std::string expected_output7 = "";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Errors: Histogram Kata Tests

/*TEST(Errors_Histogram, hist) {
    std::string input1 = "uuaaaxbbbbyyhwawiwjjjwwxym";
    std::string input2 = "uuaaaxbbbbyyhwawiwjjjwwxymzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    std::string input3 = "tpwaemuqxdmwqbqrjbeosjnejqorxdozsxnrgpgqkeihqwybzyymqeazfkyiucesxwutgszbenzvgxibxrlvmzihcb";
    std::string input4 = "aaifzlnderpeurcuqjqeywdq";
    std::string input5 = "sjeneccyhrcpfvpujfaoaykqllteovskclebmzjeqepilxygdmzvdfmxbqdzubkzturnuqxsewrwgmdfwgdx";
    std::string input6 = "bnxyytdtqrkeaswymiwbxnuydwthweyzny";
    std::string input7 = (std::string)"ttopvdaxgwfpzjmomkwssytktaizqtsekfmfhrabidwaugioqyyzrxbugsusxkfdevm" +
            "ijqyprcoxfyjqwsutoutjgozyhsoytg";

    std::string output1 = CodeWars().hist(input1);
    std::string output2 = CodeWars().hist(input2);
    std::string output3 = CodeWars().hist(input3);
    std::string output4 = CodeWars().hist(input4);
    std::string output5 = CodeWars().hist(input5);
    std::string output6 = CodeWars().hist(input6);
    std::string output7 = CodeWars().hist(input7);

    std::string expected_output1 = "u  2     **\\rw  5     *****\\rx  2     **";
    std::string expected_output2 = (std::string)"u  2     **\\rw  5     *****\\rx  2     **\\rz  31    " +
            "*******************************";
    std::string expected_output3 = "u  3     ***\\rw  4     ****\\rx  6     ******\\rz  6     ******";
    std::string expected_output4 = "u  2     **\\rw  1     *\\rz  1     *";
    std::string expected_output5 = "u  4     ****\\rw  3     ***\\rx  4     ****\\rz  4     ****";
    std::string expected_output6 = "u  1     *\\rw  4     ****\\rx  2     **\\rz  1     *";
    std::string expected_output7 = "u  5     *****\\rw  4     ****\\rx  4     ****\\rz  4     ****";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Tic-Tac-Toe (3D) Kata Tests - Not Solved

/*TEST(Tic_Tac_Toe_3D, play_OX_3D) {
    std::vector<std::vector<int>> input1 = {{0,0,0},
                                            {1,1,1},
                                            {2,2,2},
                                            {3,3,3}};
    std::vector<std::vector<int>> input2 = {{0,2,1},
                                            {0,2,2},
                                            {1,2,1},
                                            {1,2,2},
                                            {2,2,1},
                                            {2,2,2},
                                            {3,2,1}};
    std::vector<std::vector<int>> input3 = {{0,1,1},
                                            {0,0,0},
                                            {0,2,2},
                                            {1,1,1},
                                            {1,2,2},
                                            {2,2,2},
                                            {2,1,2},
                                            {3,3,3},
                                            {0,2,1}};
    std::vector<std::vector<int>> input4 = {{2, 1, 2},
                                            {0, 0, 2},
                                            {2, 3, 0},
                                            {2, 2, 1},
                                            {2, 1, 3},
                                            {3, 3, 0},
                                            {0, 2, 2},
                                            {1, 2, 2},
                                            {1, 3, 0},
                                            {3, 0, 2},
                                            {0, 1, 1},
                                            {0, 2, 3},
                                            {1, 3, 1},
                                            {3, 1, 3},
                                            {1, 3, 2},
                                            {0, 1, 2},
                                            {0, 1, 3},
                                            {2, 2, 2},
                                            {0, 2, 1},
                                            {0, 3, 2},
                                            {2, 2, 3},
                                            {1, 1, 2},
                                            {3, 3, 2},
                                            {1, 0, 3},
                                            {2, 0, 3},
                                            {2, 1, 1},
                                            {1, 2, 0},
                                            {1, 2, 1},
                                            {0, 0, 0},
                                            {3, 1, 1},
                                            {2, 0, 1},
                                            {2, 2, 0},
                                            {1, 0, 2},
                                            {3, 3, 1},
                                            {3, 0, 1},
                                            {3, 0, 0},
                                            {2, 3, 2},
                                            {1, 1, 0},
                                            {1, 1, 1},
                                            {0, 3, 0},
                                            {0, 3, 1},
                                            {0, 0, 1},
                                            {0, 3, 3},
                                            {3, 2, 1},
                                            {1, 3, 3},
                                            {1, 2, 3},
                                            {2, 0, 2}};
    std::vector<std::vector<int>> input5 = {{0, 2, 3},
                                            {1, 0, 0},
                                            {3, 3, 3},
                                            {2, 1, 1},
                                            {0, 1, 2},
                                            {0, 3, 0},
                                            {2, 2, 1},
                                            {2, 0, 3},
                                            {3, 3, 1},
                                            {1, 3, 2},
                                            {3, 0, 3},
                                            {2, 0, 1},
                                            {2, 2, 2},
                                            {3, 2, 3},
                                            {1, 3, 0},
                                            {0, 3, 2},
                                            {0, 0, 2},
                                            {3, 1, 3},
                                            {3, 0, 1},
                                            {2, 0, 0},
                                            {1, 2, 3},
                                            {0, 1, 0},
                                            {1, 3, 1},
                                            {1, 0, 2},
                                            {1, 1, 1},
                                            {2, 1, 0},
                                            {3, 2, 0},
                                            {2, 3, 3},
                                            {1, 3, 3},
                                            {1, 1, 0},
                                            {2, 3, 2},
                                            {2, 1, 2},
                                            {1, 0, 3},
                                            {0, 3, 1},
                                            {3, 3, 2},
                                            {0, 2, 2},
                                            {1, 2, 1},
                                            {0, 2, 0},
                                            {2, 1, 3},
                                            {0, 0, 3},
                                            {3, 1, 2},
                                            {2, 3, 1},
                                            {3, 2, 1},
                                            {1, 1, 3},
                                            {3, 2, 2},
                                            {2, 2, 3},
                                            {1, 1, 2},
                                            {2, 3, 0},
                                            {1, 2, 2},
                                            {0, 1, 1},
                                            {0, 2, 1}};
    std::vector<std::vector<int>> input6 = {{1, 0, 3},
                                            {0, 2, 3},
                                            {2, 2, 2},
                                            {0, 2, 1},
                                            {2, 0, 3},
                                            {3, 1, 0},
                                            {1, 3, 0},
                                            {2, 2, 3},
                                            {0, 3, 0},
                                            {1, 1, 3},
                                            {3, 0, 0},
                                            {1, 0, 2},
                                            {2, 1, 3},
                                            {3, 1, 2},
                                            {3, 3, 0},
                                            {2, 0, 2},
                                            {3, 2, 1},
                                            {2, 1, 0},
                                            {1, 2, 1},
                                            {2, 3, 1},
                                            {1, 2, 0},
                                            {3, 3, 3},
                                            {3, 3, 1},
                                            {0, 2, 2},
                                            {1, 0, 1},
                                            {1, 3, 1},
                                            {2, 2, 0},
                                            {0, 0, 0},
                                            {1, 1, 2},
                                            {3, 1, 3},
                                            {0, 0, 3},
                                            {0, 3, 3},
                                            {2, 0, 0},
                                            {2, 3, 0},
                                            {2, 3, 3},
                                            {2, 0, 1},
                                            {2, 1, 2},
                                            {0, 1, 2},
                                            {1, 2, 3},
                                            {0, 1, 1}};

    //std::string output1 = CodeWars().play_OX_3D(input1);
    //std::string output2 = CodeWars().play_OX_3D(input2);
    //std::string output3 = CodeWars().play_OX_3D(input3);
    //std::string output4 = CodeWars().play_OX_3D(input4);
    //std::string output5 = CodeWars().play_OX_3D(input5);
    std::string output6 = CodeWars().play_OX_3D(input6);

    std::string expected_output1 = "No winner";
    std::string expected_output2 = "O wins after 7 moves";
    std::string expected_output3 = "X wins after 8 moves";
    std::string expected_output4 = "O wins after 43 moves";
    std::string expected_output5 = "O wins after 47 moves";
    std::string expected_output6 = "O wins after 29 moves";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
}*/

// ----------------------------------------------------------------------------------------------------------

// Connect Four Kata Tests

/*TEST(Connect_Four, who_is_winner) {
    std::vector<std::string> input1 = {
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "G_Red",
            "B_Yellow"
    };
    std::vector<std::string> input2 = {
            "C_Yellow",
            "E_Red",
            "G_Yellow",
            "B_Red",
            "D_Yellow",
            "B_Red",
            "B_Yellow",
            "G_Red",
            "C_Yellow",
            "C_Red",
            "D_Yellow",
            "F_Red",
            "E_Yellow",
            "A_Red",
            "A_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "F_Yellow",
            "D_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "A_Red",
            "G_Yellow",
            "D_Red",
            "D_Yellow",
            "C_Red"
    };
    std::vector<std::string> input3 = {
            "A_Yellow",
            "B_Red",
            "B_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "C_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "F_Yellow",
            "E_Red",
            "D_Yellow"
    };
    std::vector<std::string> input4 = {
            "F_Yellow",
            "G_Red",
            "D_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "E_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "B_Yellow",
            "E_Red",
            "C_Yellow",
            "D_Red",
            "F_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "G_Yellow",
            "C_Red",
            "F_Yellow",
            "E_Red",
            "A_Yellow",
            "A_Red",
            "C_Yellow",
            "B_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "G_Red",
            "A_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "B_Yellow",
            "E_Red",
            "F_Yellow",
            "G_Red",
            "G_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red"
    };
    std::vector<std::string> input5 = {
            "C_Yellow",
            "B_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "G_Red",
            "B_Yellow",
            "G_Red",
            "E_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "D_Yellow",
            "B_Red",
            "G_Yellow",
            "A_Red",
            "F_Yellow",
            "B_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "F_Red",
            "B_Yellow",
            "F_Red",
            "F_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "E_Red"
    };
    std::vector<std::string> input6 = {
            "A_Yellow",
            "A_Red",
            "A_Yellow",
            "A_Red",
            "A_Yellow",
            "A_Red",
            "B_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red",
            "D_Yellow",
            "D_Red",
            "D_Yellow",
            "D_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "E_Red",
            "E_Yellow",
            "E_Red",
            "E_Yellow",
            "E_Red",
            "C_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "C_Yellow",
            "C_Red",
            "C_Yellow",
            "F_Red",
            "F_Yellow",
            "F_Red",
            "F_Yellow",
            "F_Red",
            "G_Yellow",
            "G_Red",
            "G_Yellow",
            "G_Red",
            "G_Yellow",
            "G_Red"
    };

    std::string output1 = CodeWars().who_is_winner(input1);
    std::string output2 = CodeWars().who_is_winner(input2);
    std::string output3 = CodeWars().who_is_winner(input3);
    std::string output4 = CodeWars().who_is_winner(input4);
    //std::string output5 = CodeWars().who_is_winner(input5);
    //std::string output6 = CodeWars().who_is_winner(input6);

    std::string expected_output1 = "Yellow";
    std::string expected_output2 = "Yellow";
    std::string expected_output3 = "Red";
    std::string expected_output4 = "Red";
    std::string expected_output5 = "Yellow";
    std::string expected_output6 = "Draw";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    //EXPECT_EQ(output5, expected_output5);
    //EXPECT_EQ(output6, expected_output6);
}*/

// ----------------------------------------------------------------------------------------------------------

// Battleship Field Validator Kata Tests

/*TEST(Battleship_Field_Validator, validate_battlefield) {
    std::vector<std::vector<int>> input1 = {
            {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input2 = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input3 = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input4 = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input5 = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input6 = {
            {1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<int>> input7 = {
            {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1}};
    std::vector <std::vector<int>> input8 = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    bool output1 = CodeWars().validate_battlefield(input1);
    bool output2 = CodeWars().validate_battlefield(input2);
    bool output3 = CodeWars().validate_battlefield(input3);
    bool output4 = CodeWars().validate_battlefield(input4);
    bool output5 = CodeWars().validate_battlefield(input5);
    bool output6 = CodeWars().validate_battlefield(input6);
    bool output7 = CodeWars().validate_battlefield(input7);
    bool output8 = CodeWars().validate_battlefield(input8);

    EXPECT_TRUE(output1);
    EXPECT_FALSE(output2);
    EXPECT_FALSE(output3);
    EXPECT_FALSE(output4);
    EXPECT_TRUE(output5);
    EXPECT_TRUE(output6);
    EXPECT_TRUE(output7);
    EXPECT_FALSE(output8);
}*/

// ----------------------------------------------------------------------------------------------------------

// Sort - one, three, two Kata Tests

/*TEST(Sort_one_three_two, sort) {
    std::vector<int> input1 = {8, 8, 9, 9, 10, 10};
    std::vector<int> input2 = {1, 2, 3, 4};
    std::vector<int> input3 = {9, 99, 999};
    std::vector<int> input4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                               25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
                               47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
                               69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                               91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
                               110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
                               128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
                               146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163,
                               164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181,
                               182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
                               200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217,
                               218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235,
                               236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253,
                               254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
                               272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289,
                               290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307,
                               308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325,
                               326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343,
                               344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361,
                               362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
                               380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397,
                               398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415,
                               416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433,
                               434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451,
                               452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469,
                               470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487,
                               488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505,
                               506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523,
                               524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541,
                               542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559,
                               560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577,
                               578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595,
                               596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613,
                               614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631,
                               632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649,
                               650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667,
                               668, 669, 670, 671, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685,
                               686, 687, 688, 689, 690, 691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703,
                               704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721,
                               722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739,
                               740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757,
                               758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775,
                               776, 777, 778, 779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792, 793,
                               794, 795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811,
                               812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829,
                               830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847,
                               848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865,
                               866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883,
                               884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900, 901,
                               902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919,
                               920, 921, 922, 923, 924, 925, 926, 927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937,
                               938, 939, 940, 941, 942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955,
                               956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973,
                               974, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991,
                               992, 993, 994, 995, 996, 997, 998, 999};
    std::vector<int> input5 = {251, 31, 882, 800, 418, 523, 409, 880, 648, 413};

    std::vector<int> output1 = CodeWars().sort(input1);
    std::vector<int> output2 = CodeWars().sort(input2);
    std::vector<int> output3 = CodeWars().sort(input3);
    std::vector<int> output4 = CodeWars().sort(input4);
    std::vector<int> output5 = CodeWars().sort(input5);

    std::vector<int> expected_output1 = {8, 8, 9, 9, 10, 10};
    std::vector<int> expected_output2 = {4, 1, 3, 2};
    std::vector<int> expected_output3 = {9, 999, 99};
    std::vector<int> expected_output4 = {8, 800, 808, 818, 880, 888, 885, 884, 889, 881, 887, 886, 883, 882, 811, 815,
                                         850, 858, 855, 854, 859, 851, 857, 856, 853, 852, 805, 840, 848, 845, 844, 849,
                                         841, 847, 846, 843, 842, 804, 814, 809, 819, 890, 898, 895, 894, 899, 891, 897,
                                         896, 893, 892, 801, 807, 817, 870, 878, 875, 874, 879, 871, 877, 876, 873, 872,
                                         806, 816, 860, 868, 865, 864, 869, 861, 867, 866, 863, 862, 810, 813, 830, 838,
                                         835, 834, 839, 831, 837, 836, 833, 832, 803, 812, 820, 828, 825, 824, 829, 821,
                                         827, 826, 823, 822, 802, 18, 80, 88, 85, 84, 89, 81, 87, 86, 83, 82, 11, 15,
                                         50, 58, 55, 54, 59, 51, 57, 56, 53, 52, 5, 500, 508, 518, 580, 588, 585, 584,
                                         589, 581, 587, 586, 583, 582, 511, 515, 550, 558, 555, 554, 559, 551, 557, 556,
                                         553, 552, 505, 540, 548, 545, 544, 549, 541, 547, 546, 543, 542, 504, 514, 509,
                                         519, 590, 598, 595, 594, 599, 591, 597, 596, 593, 592, 501, 507, 517, 570, 578,
                                         575, 574, 579, 571, 577, 576, 573, 572, 506, 516, 560, 568, 565, 564, 569, 561,
                                         567, 566, 563, 562, 510, 513, 530, 538, 535, 534, 539, 531, 537, 536, 533, 532,
                                         503, 512, 520, 528, 525, 524, 529, 521, 527, 526, 523, 522, 502, 40, 48, 45,
                                         44, 49, 41, 47, 46, 43, 42, 4, 400, 408, 418, 480, 488, 485, 484, 489, 481,
                                         487, 486, 483, 482, 411, 415, 450, 458, 455, 454, 459, 451, 457, 456, 453, 452,
                                         405, 440, 448, 445, 444, 449, 441, 447, 446, 443, 442, 404, 414, 409, 419, 490,
                                         498, 495, 494, 499, 491, 497, 496, 493, 492, 401, 407, 417, 470, 478, 475, 474,
                                         479, 471, 477, 476, 473, 472, 406, 416, 460, 468, 465, 464, 469, 461, 467, 466,
                                         463, 462, 410, 413, 430, 438, 435, 434, 439, 431, 437, 436, 433, 432, 403, 412,
                                         420, 428, 425, 424, 429, 421, 427, 426, 423, 422, 402, 14, 9, 900, 908, 918,
                                         980, 988, 985, 984, 989, 981, 987, 986, 983, 982, 911, 915, 950, 958, 955, 954,
                                         959, 951, 957, 956, 953, 952, 905, 940, 948, 945, 944, 949, 941, 947, 946, 943,
                                         942, 904, 914, 909, 919, 990, 998, 995, 994, 999, 991, 997, 996, 993, 992, 901,
                                         907, 917, 970, 978, 975, 974, 979, 971, 977, 976, 973, 972, 906, 916, 960, 968,
                                         965, 964, 969, 961, 967, 966, 963, 962, 910, 913, 930, 938, 935, 934, 939, 931,
                                         937, 936, 933, 932, 903, 912, 920, 928, 925, 924, 929, 921, 927, 926, 923, 922,
                                         902, 19, 90, 98, 95, 94, 99, 91, 97, 96, 93, 92, 1, 100, 108, 118, 180, 188,
                                         185, 184, 189, 181, 187, 186, 183, 182, 111, 115, 150, 158, 155, 154, 159, 151,
                                         157, 156, 153, 152, 105, 140, 148, 145, 144, 149, 141, 147, 146, 143, 142, 104,
                                         114, 109, 119, 190, 198, 195, 194, 199, 191, 197, 196, 193, 192, 101, 107, 117,
                                         170, 178, 175, 174, 179, 171, 177, 176, 173, 172, 106, 116, 160, 168, 165, 164,
                                         169, 161, 167, 166, 163, 162, 110, 113, 130, 138, 135, 134, 139, 131, 137, 136,
                                         133, 132, 103, 112, 120, 128, 125, 124, 129, 121, 127, 126, 123, 122, 102, 7,
                                         700, 708, 718, 780, 788, 785, 784, 789, 781, 787, 786, 783, 782, 711, 715, 750,
                                         758, 755, 754, 759, 751, 757, 756, 753, 752, 705, 740, 748, 745, 744, 749, 741,
                                         747, 746, 743, 742, 704, 714, 709, 719, 790, 798, 795, 794, 799, 791, 797, 796,
                                         793, 792, 701, 707, 717, 770, 778, 775, 774, 779, 771, 777, 776, 773, 772, 706,
                                         716, 760, 768, 765, 764, 769, 761, 767, 766, 763, 762, 710, 713, 730, 738, 735,
                                         734, 739, 731, 737, 736, 733, 732, 703, 712, 720, 728, 725, 724, 729, 721, 727,
                                         726, 723, 722, 702, 17, 70, 78, 75, 74, 79, 71, 77, 76, 73, 72, 6, 600, 608,
                                         618, 680, 688, 685, 684, 689, 681, 687, 686, 683, 682, 611, 615, 650, 658, 655,
                                         654, 659, 651, 657, 656, 653, 652, 605, 640, 648, 645, 644, 649, 641, 647, 646,
                                         643, 642, 604, 614, 609, 619, 690, 698, 695, 694, 699, 691, 697, 696, 693, 692,
                                         601, 607, 617, 670, 678, 675, 674, 679, 671, 677, 676, 673, 672, 606, 616, 660,
                                         668, 665, 664, 669, 661, 667, 666, 663, 662, 610, 613, 630, 638, 635, 634, 639,
                                         631, 637, 636, 633, 632, 603, 612, 620, 628, 625, 624, 629, 621, 627, 626, 623,
                                         622, 602, 16, 60, 68, 65, 64, 69, 61, 67, 66, 63, 62, 10, 13, 30, 38, 35, 34,
                                         39, 31, 37, 36, 33, 32, 3, 300, 308, 318, 380, 388, 385, 384, 389, 381, 387,
                                         386, 383, 382, 311, 315, 350, 358, 355, 354, 359, 351, 357, 356, 353, 352, 305,
                                         340, 348, 345, 344, 349, 341, 347, 346, 343, 342, 304, 314, 309, 319, 390, 398,
                                         395, 394, 399, 391, 397, 396, 393, 392, 301, 307, 317, 370, 378, 375, 374, 379,
                                         371, 377, 376, 373, 372, 306, 316, 360, 368, 365, 364, 369, 361, 367, 366, 363,
                                         362, 310, 313, 330, 338, 335, 334, 339, 331, 337, 336, 333, 332, 303, 312, 320,
                                         328, 325, 324, 329, 321, 327, 326, 323, 322, 302, 12, 20, 28, 25, 24, 29, 21,
                                         27, 26, 23, 22, 2, 200, 208, 218, 280, 288, 285, 284, 289, 281, 287, 286, 283,
                                         282, 211, 215, 250, 258, 255, 254, 259, 251, 257, 256, 253, 252, 205, 240, 248,
                                         245, 244, 249, 241, 247, 246, 243, 242, 204, 214, 209, 219, 290, 298, 295, 294,
                                         299, 291, 297, 296, 293, 292, 201, 207, 217, 270, 278, 275, 274, 279, 271, 277,
                                         276, 273, 272, 206, 216, 260, 268, 265, 264, 269, 261, 267, 266, 263, 262, 210,
                                         213, 230, 238, 235, 234, 239, 231, 237, 236, 233, 232, 203, 212, 220, 228, 225,
                                         224, 229, 221, 227, 226, 223, 222, 202, 0};
    std::vector<int> expected_output5 = {800, 880, 882, 523, 418, 409, 413, 648, 31, 251};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Multiplying Numbers as Strings Kata Tests

/*TEST(Multiplying_Numbers_as_Strings, multiply) {
    std::string input1a = "2";
    std::string input2a = "30";
    std::string input3a = "11";
    std::string input4a = "2";
    std::string input5a = "0";
    std::string input6a = "0000001";
    std::string input7a = "98765";
    std::string input8a = "1020303004875647366210";
    std::string input9a = "58608473622772837728372827";
    std::string input10a = "9007199254740991";
    std::string input11a = "1009";
    std::string input12a = "99";
    std::string input13a = "91";
    std::string input14a = "102030300";

    std::string input1b = "3";
    std::string input2b = "69";
    std::string input3b = "85";
    std::string input4b = "0";
    std::string input5b = "30";
    std::string input6b = "3";
    std::string input7b = "56894";
    std::string input8b = "2774537626200857473632627613";
    std::string input9b = "7586374672263726736374";
    std::string input10b = "9007199254740991";
    std::string input11b = "03";
    std::string input12b = "25";
    std::string input13b = "119";
    std::string input14b = "27745376";

    std::string output1 = CodeWars().multiply(input1a, input1b);
    std::string output2 = CodeWars().multiply(input2a, input2b);
    std::string output3 = CodeWars().multiply(input3a, input3b);
    std::string output4 = CodeWars().multiply(input4a, input4b);
    std::string output5 = CodeWars().multiply(input5a, input5b);
    std::string output6 = CodeWars().multiply(input6a, input6b);
    std::string output7 = CodeWars().multiply(input7a, input7b);
    std::string output8 = CodeWars().multiply(input8a, input8b);
    std::string output9 = CodeWars().multiply(input9a, input9b);
    std::string output10 = CodeWars().multiply(input10a, input10b);
    std::string output11 = CodeWars().multiply(input11a, input11b);
    std::string output12 = CodeWars().multiply(input12a, input12b);
    std::string output13 = CodeWars().multiply(input13a, input13b);
    std::string output14 = CodeWars().multiply(input14a, input14b);

    std::string expected_output1 = "6";
    std::string expected_output2 = "2070";
    std::string expected_output3 = "935";
    std::string expected_output4 = "0";
    std::string expected_output5 = "0";
    std::string expected_output6 = "3";
    std::string expected_output7 = "5619135910";
    std::string expected_output8 = "2830869077153280552556547081187254342445169156730";
    std::string expected_output9 = "444625839871840560024489175424316205566214109298";
    std::string expected_output10 = "81129638414606663681390495662081";
    std::string expected_output11 = "3027";
    std::string expected_output12 = "2475";
    std::string expected_output13 = "10829";
    std::string expected_output14 = "2830869036892800";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
    EXPECT_EQ(output11, expected_output11);
    EXPECT_EQ(output12, expected_output12);
    EXPECT_EQ(output13, expected_output13);
    EXPECT_EQ(output14, expected_output14);
}*/

// ----------------------------------------------------------------------------------------------------------

// Integers: Recreation One Kata Tests

/*TEST(Integers_Recreation_One, list_squared) {
    long long input1a = 1;
    long long input2a = 42;
    long long input3a = 250;
    long long input4a = 300;

    long long input1b = 250;
    long long input2b = 250;
    long long input3b = 500;
    long long input4b = 600;

    std::vector<std::pair<long long, long long>> output1 = CodeWars().list_squared(input1a, input1b);
    std::vector<std::pair<long long, long long>> output2 = CodeWars().list_squared(input2a, input2b);
    std::vector<std::pair<long long, long long>> output3 = CodeWars().list_squared(input3a, input3b);
    std::vector<std::pair<long long, long long>> output4 = CodeWars().list_squared(input4a, input4b);

    std::vector<std::pair<long long, long long>> expected_output1 = {{1, 1}, {42, 2500}, {246, 84100}};
    std::vector<std::pair<long long, long long>> expected_output2 = {{42, 2500}, {246, 84100}};
    std::vector<std::pair<long long, long long>> expected_output3 = {{287, 84100}};
    std::vector<std::pair<long long, long long>> expected_output4 = {};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
*/

// ----------------------------------------------------------------------------------------------------------

// Best Travel Kata Tests

/*TEST(Best_Travel, choose_best_sum) {
    int input1a = 174;
    int input2a = 163;
    int input3a = 163;
    int input4a = 230;
    int input5a = 331;
    int input6a = 331;
    int input7a = 331;
    int input8a = 331;
    int input9a = 700;

    int input1b = 3;
    int input2b = 3;
    int input3b = 3;
    int input4b = 3;
    int input5b = 2;
    int input6b = 4;
    int input7b = 5;
    int input8b = 1;
    int input9b = 8;

    std::vector<int> input1c = {50, 55, 57, 58, 60};
    std::vector<int> input2c = {50, 55, 56, 57, 58};
    std::vector<int> input3c = {50};
    std::vector<int> input4c = {91, 74, 73, 85, 73, 81, 87};
    std::vector<int> input5c = {91, 74, 73, 85, 73, 81, 87};
    std::vector<int> input6c = {91, 74, 73, 85, 73, 81, 87};
    std::vector<int> input7c = {91, 74, 73, 85, 73, 81, 87};
    std::vector<int> input8c = {91, 74, 73, 85, 73, 81, 87};
    std::vector<int> input9c = {91, 74, 73, 85, 73, 81, 87};

    int output1 = CodeWars().choose_best_sum(input1a, input1b, input1c);
    int output2 = CodeWars().choose_best_sum(input2a, input2b, input2c);
    int output3 = CodeWars().choose_best_sum(input3a, input3b, input3c);
    int output4 = CodeWars().choose_best_sum(input4a, input4b, input4c);
    int output5 = CodeWars().choose_best_sum(input5a, input5b, input5c);
    int output6 = CodeWars().choose_best_sum(input6a, input6b, input6c);
    int output7 = CodeWars().choose_best_sum(input7a, input7b, input7c);
    int output8 = CodeWars().choose_best_sum(input8a, input8b, input8c);
    int output9 = CodeWars().choose_best_sum(input9a, input9b, input9c);

    int expected_output1 = 173;
    int expected_output2 = 163;
    int expected_output3 = -1;
    int expected_output4 = 228;
    int expected_output5 = 178;
    int expected_output6 = 331;
    int expected_output7 = -1;
    int expected_output8 = 91;
    int expected_output9 = -1;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
}*/

// ----------------------------------------------------------------------------------------------------------

// Get the Middle Character Kata Tests

/*TEST(Get_the_Middle_Character, get_middle) {
    std::string input1 = "test";
    std::string input2 = "testing";

    std::string output1 = CodeWars().get_middle(input1);
    std::string output2 = CodeWars().get_middle(input2);

    std::string expected_output1 = "es";
    std::string expected_output2 = "t";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
}*/

// ----------------------------------------------------------------------------------------------------------

// The Supermarket Queue Kata Tests

/*TEST(The_Supermarket_Queue, queue_time) {
    std::vector<int> input1a = {};
    std::vector<int> input2a = {1,2,3,4};
    std::vector<int> input3a = {2,2,3,3,4,4};
    std::vector<int> input4a = {1,2,3,4,5};

    int input1b = 1;
    int input2b = 1;
    int input3b = 2;
    int input4b = 100;

    int output1 = CodeWars().queue_time(input1a, input1b);
    int output2 = CodeWars().queue_time(input2a, input2b);
    int output3 = CodeWars().queue_time(input3a, input3b);
    int output4 = CodeWars().queue_time(input4a, input4b);

    int expected_output1 = 0;
    int expected_output2 = 10;
    int expected_output3 = 9;
    int expected_output4 = 5;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
}*/

// ----------------------------------------------------------------------------------------------------------

// Permutations Kata Tests

/*TEST(Permutations, permutations) {
    std::string input1 = "a";
    std::string input2 = "ab";
    std::string input3 = "aabb";

    std::vector<std::string> output1 = CodeWars().permutations(input1);
    std::vector<std::string> output2 = CodeWars().permutations(input2);
    std::vector<std::string> output3 = CodeWars().permutations(input3);

    std::vector<std::string> expected_output1 = {"a"};
    std::vector<std::string> expected_output2 = {"ab", "ba"};
    std::vector<std::string> expected_output3 = {"aabb", "abab", "abba", "baab", "baba", "bbaa"};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Human Readable Duration Format Kata Tests---

/*TEST(Human_Readable_Duration_Format, format_duration) {
    int input1 = 0;
    int input2 = 1;
    int input3 = 62;
    int input4 = 120;
    int input5 = 3662;

    std::string output1 = CodeWars().format_duration(input1);
    std::string output2 = CodeWars().format_duration(input2);
    std::string output3 = CodeWars().format_duration(input3);
    std::string output4 = CodeWars().format_duration(input4);
    std::string output5 = CodeWars().format_duration(input5);

    std::string expected_output1 = "now";
    std::string expected_output2 = "1 second";
    std::string expected_output3 = "1 minute and 2 seconds";
    std::string expected_output4 = "2 minutes";
    std::string expected_output5 = "1 hour, 1 minute and 2 seconds";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Infix to Postfix Converter Kata Tests

/*TEST(Infix_to_Postfix_Converter, to_postfix) {
    std::string input1 = "2+7*5";
    std::string input2 = "3*3/(7+1)";
    std::string input3 = "5+(6-2)*9+3^(7-1)";
    std::string input4 = "(5-4-1)+9/5/2-7/1/7";
    std::string input5 = "5+(6-2)*9+3^(7-1)";

    std::string output1 = CodeWars().to_postfix(input1);
    std::string output2 = CodeWars().to_postfix(input2);
    std::string output3 = CodeWars().to_postfix(input3);
    std::string output4 = CodeWars().to_postfix(input4);
    std::string output5 = CodeWars().to_postfix(input5);

    std::string expected_output1 = "275*+";
    std::string expected_output2 = "33*71+/";
    std::string expected_output3 = "562-9*+371-^+";
    std::string expected_output4 = "54-1-95/2/+71/7/-";
    std::string expected_output5 = "562-9*+371-^+";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
}*/

// ----------------------------------------------------------------------------------------------------------

// Third Angle of a Triangle Kata Tests

/*TEST(Third_Angle_of_a_Triangle, other_angle) {
    int input1a = 30;
    int input2a = 60;
    int input3a = 43;
    int input4a = 10;

    int input1b = 60;
    int input2b = 60;
    int input3b = 78;
    int input4b = 20;

    int output1 = CodeWars().other_angle(input1a, input1b);
    int output2 = CodeWars().other_angle(input2a, input2b);
    int output3 = CodeWars().other_angle(input3a, input3b);
    int output4 = CodeWars().other_angle(input4a, input4b);

    int expected_output1 = 90;
    int expected_output2 = 60;
    int expected_output3 = 59;
    int expected_output4 = 150;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
}*/

// ----------------------------------------------------------------------------------------------------------

// Block Sequence Kata Tests

/*TEST(Block_Sequence, solve) {
    long long input1 = 1;
    long long input2 = 2;
    long long input3 = 3;
    long long input4 = 100;
    long long input5 = 2100;
    long long input6 = 31000;
    long long input7 = 55;

    int output1 = CodeWars().solve(input1);
    int output2 = CodeWars().solve(input2);
    int output3 = CodeWars().solve(input3);
    int output4 = CodeWars().solve(input4);
    int output5 = CodeWars().solve(input5);
    int output6 = CodeWars().solve(input6);
    int output7 = CodeWars().solve(input7);

    int expected_output1 = 1;
    int expected_output2 = 1;
    int expected_output3 = 2;
    int expected_output4 = 1;
    int expected_output5 = 2;
    int expected_output6 = 2;
    int expected_output7 = 1;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Count by X Kata Tests

/*TEST(Count_by_X, count_by) {
    int input1a = 1;
    int input2a = 2;
    int input3a = 100;

    int input1b = 10;
    int input2b = 5;
    int input3b = 5;

    std::vector<int> output1 = CodeWars().count_by(input1a, input1b);
    std::vector<int> output2 = CodeWars().count_by(input2a, input2b);
    std::vector<int> output3 = CodeWars().count_by(input3a, input3b);

    std::vector<int> expected_output1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> expected_output2 = {2,4,6,8,10};
    std::vector<int> expected_output3 = {100,200,300,400,500};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Disease Spread Kata Tests

/*TEST(Disease_Spread, epidemic) {
    int input1a = 18;
    int input2a = 12;

    int input1b = 432;
    int input2b = 288;

    int input1c = 1004;
    int input2c = 1007;

    int input1d = 1;
    int input2d = 2;

    double input1e = 0.00209;
    double input2e = 0.00206;

    double input1f = 0.51;
    double input2f = 0.45;

    int output1 = CodeWars().epidemic(input1a, input1b, input1c, input1d, input1e, input1f);
    int output2 = CodeWars().epidemic(input2a, input2b, input2c, input2d, input2e, input2f);

    int expect_output1 = 420;
    int expect_output2 = 461;

    EXPECT_EQ(output1, expect_output1);
    EXPECT_EQ(output2, expect_output2);
}*/

// ----------------------------------------------------------------------------------------------------------

// Find the Next Perfect Square Kata Tests

/*TEST(Find_the_Next_Perfect_Square, find_next_square) {
    long int input1 = 121;
    long int input2 = 625;
    long int input3 = 114;
    long int input4 = 319225;
    long int input5 = 15241383936;
    long int input6 = 155;

    long int output1 = CodeWars().find_next_square(input1);
    long int output2 = CodeWars().find_next_square(input2);
    long int output3 = CodeWars().find_next_square(input3);
    long int output4 = CodeWars().find_next_square(input4);
    long int output5 = CodeWars().find_next_square(input5);
    long int output6 = CodeWars().find_next_square(input6);

    long int expected_output1 = 144;
    long int expected_output2 = 676;
    long int expected_output3 = -1;
    long int expected_output4 = 320356;
    long int expected_output5 = 15241630849;
    long int expected_output6 = -1;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
}*/

// ----------------------------------------------------------------------------------------------------------

// Operating System Scheduling: FCFS Scheduling Kata Tests

/*TEST(Operating_System_Schedulign_FCFS_Scheduling, fcfs) {
    std::vector<std::pair<int, int>> input1 = {{0, 4}, {2, 1}, {3, 3}, {7, 13}};
    std::vector<std::pair<int, int>> input2 = {{0, 2}, {1, 2}, {5, 3}, {6, 4}, {7, 9}};
    std::vector<std::pair<int, int>> input3 = {{4, 4}, {12, 1}, {20, 3}};

    std::tuple<double, double, double, double> output1 = CodeWars().fcfs(input1);
    std::tuple<double, double, double, double> output2 = CodeWars().fcfs(input2);
    std::tuple<double, double, double, double>  output3 = CodeWars().fcfs(input3);

    std::tuple<double, double, double, double> output_sandbox = CodeWars().fcfs({{{4, 4}, {5, 1}, { 7, 5}, {8, 10},
                                                                                  {12, 1}, {20, 3}}});

    std::tuple<double, double, double, double> expected_output1 = {9.5, 6.5, 1.25, 5.25};
    std::tuple<double, double, double, double> expected_output2 = {9.4, 5.6, 1.6, 4.0};
    std::tuple<double, double, double, double> expected_output3 = {14.67, 2.67, 0.0, 2.67};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Consonant Value Kata Tests

/*TEST(Consonant_Value, solve2) {
    std::string input1 = "zodiac";
    std::string input2 = "chruschtschov";
    std::string input3 = "khrushchev";
    std::string input4 = "strength";
    std::string input5 = "catchphrase";
    std::string input6 = "twelfthstreet";
    std::string input7 = "mischtschenkoana";

    int output1 = CodeWars().solve2(input1);
    int output2 = CodeWars().solve2(input2);
    int output3 = CodeWars().solve2(input3);
    int output4 = CodeWars().solve2(input4);
    int output5 = CodeWars().solve2(input5);
    int output6 = CodeWars().solve2(input6);
    int output7 = CodeWars().solve2(input7);

    int expected_output1 = 26;
    int expected_output2 = 80;
    int expected_output3 = 38;
    int expected_output4 = 57;
    int expected_output5 = 73;
    int expected_output6 = 103;
    int expected_output7 = 80;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Palindrome Integer Composition Kata Tests

/*TEST(Palindrome_Integer_Composition, value) {
    int input1 = 100;
    int input2 = 200;
    int input3 = 300;
    int input4 = 400;
    int input5 = 1000;
    int input6 = 1000000;
    int input7 = 5000000;

    int output1 = CodeWars().values(input1);
    int output2 = CodeWars().values(input2);
    int output3 = CodeWars().values(input3);
    int output4 = CodeWars().values(input4);
    int output5 = CodeWars().values(input5);
    int output6 = CodeWars().values(input6);
    int output7 = CodeWars().values(input7);

    int expected_output1 = 3;
    int expected_output2 = 4;
    int expected_output3 = 4;
    int expected_output4 = 5;
    int expected_output5 = 11;
    int expected_output6 = 60;
    int expected_output7 = 78;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
}*/

// ----------------------------------------------------------------------------------------------------------

// Snail Kata Tests

/*TEST(Snail, snail) {
    std::vector<std::vector<int>> input1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> input2 = {{1, 2}, {4, 3}};
    std::vector<std::vector<int>> input3 = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    std::vector<std::vector<int>> input4 = {{1, 2, 3}, {8,9,4}, {7,6,5}};
    std::vector<std::vector<int>> input5 = {{}};
    std::vector<std::vector<int>> input6 = {{1}};

    std::vector<int> output1 = CodeWars().snail(input1);
    std::vector<int> output2 = CodeWars().snail(input2);
    std::vector<int> output3 = CodeWars().snail(input3);
    std::vector<int> output4 = CodeWars().snail(input4);
    std::vector<int> output5 = CodeWars().snail(input5);
    std::vector<int> output6 = CodeWars().snail(input6);

    std::vector<int> expected_output1 = {1,2,3,6,9,8,7,4,5};
    std::vector<int> expected_output2 = {1, 2, 3, 4};
    std::vector<int> expected_output3 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    std::vector<int> expected_output4 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> expected_output5 = {};
    std::vector<int> expected_output6 = {1};

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
}*/

// ----------------------------------------------------------------------------------------------------------

// Scheduling Round Robin Kata Tests

/*TEST(Scheduling_Round_Robin, round_robin) {
    std::vector<int> input1a = {10};
    std::vector<int> input2a = {10, 20};
    std::vector<int> input3a = {10, 20, 1, 2, 3};

    int input1b = 4;
    int input2b = 5;
    int input3b = 5;

    int input1c = 0;
    int input2c = 0;
    int input3c = 2;

    int output1 = CodeWars().round_robin(input1a, input1b, input1c);
    int output2 = CodeWars().round_robin(input2a, input2b, input2c);
    int output3 = CodeWars().round_robin(input3a,input3b, input3c);

    int expected_output1 = 10;
    int expected_output2 = 15;
    int expected_output3 = 11;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Scheduling Shortest Job First Kata Tests

/*TEST(Scheduling_Shortest_Job_First, SJF) {
    std::vector<int> input1a = {10};
    std::vector<int> input2a = {3, 10, 20, 1, 2, 3};
    std::vector<int> input3a = {3, 10, 20, 1, 2};

    int input1b = 0;
    int input2b = 5;
    int input3b = 0;

    int output1 = CodeWars().SJF(input1a, input1b);
    int output2 = CodeWars().SJF(input2a, input2b);
    int output3 = CodeWars().SJF(input3a, input3b);

    int expected_output1 = 10;
    int expected_output2 = 9;
    int expected_output3 = 6;

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
}*/

// ----------------------------------------------------------------------------------------------------------

// Connect Four Kata Tests

/*TEST(Connect_Four, who_is_winner) {
    std::vector<std::string> input1 = {
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "G_Red",
            "B_Yellow"
    };
    std::vector<std::string> input2 = {
            "C_Yellow",
            "E_Red",
            "G_Yellow",
            "B_Red",
            "D_Yellow",
            "B_Red",
            "B_Yellow",
            "G_Red",
            "C_Yellow",
            "C_Red",
            "D_Yellow",
            "F_Red",
            "E_Yellow",
            "A_Red",
            "A_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "F_Yellow",
            "D_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "A_Red",
            "G_Yellow",
            "D_Red",
            "D_Yellow",
            "C_Red"
    };
    std::vector<std::string> input3 = {
            "A_Yellow",
            "B_Red",
            "B_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "C_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "F_Yellow",
            "E_Red",
            "D_Yellow"
    };
    std::vector<std::string> input4 = {
            "F_Yellow",
            "G_Red",
            "D_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "E_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "B_Yellow",
            "E_Red",
            "C_Yellow",
            "D_Red",
            "F_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "G_Yellow",
            "C_Red",
            "F_Yellow",
            "E_Red",
            "A_Yellow",
            "A_Red",
            "C_Yellow",
            "B_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "G_Red",
            "A_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "B_Yellow",
            "E_Red",
            "F_Yellow",
            "G_Red",
            "G_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red"
    };
    std::vector<std::string> input5 = {
            "C_Yellow",
            "B_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "G_Red",
            "B_Yellow",
            "G_Red",
            "E_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "D_Yellow",
            "B_Red",
            "G_Yellow",
            "A_Red",
            "F_Yellow",
            "B_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "F_Red",
            "B_Yellow",
            "F_Red",
            "F_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "E_Red"
    };
    std::vector<std::string> input6 = {
            "A_Yellow",
            "A_Red",
            "A_Yellow",
            "A_Red",
            "A_Yellow",
            "A_Red",
            "B_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red",
            "D_Yellow",
            "D_Red",
            "D_Yellow",
            "D_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "E_Red",
            "E_Yellow",
            "E_Red",
            "E_Yellow",
            "E_Red",
            "C_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "C_Yellow",
            "C_Red",
            "C_Yellow",
            "F_Red",
            "F_Yellow",
            "F_Red",
            "F_Yellow",
            "F_Red",
            "G_Yellow",
            "G_Red",
            "G_Yellow",
            "G_Red",
            "G_Yellow",
            "G_Red"
    };

    std::vector<std::string> input7 = {
            "A_Yellow",
            "B_Red",
            "B_Yellow",
            "C_Red",
            "C_Yellow",
            "D_Red",
            "C_Yellow",
            "D_Red",
            "D_Yellow",
            "G_Red",
            "D_Yellow",
            "G_Red"
    };

    std::vector<std::string> input8 = {
            "G_Yellow",
            "F_Red",
            "F_Yellow",
            "E_Red",
            "E_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "D_Yellow",
            "A_Red",
            "D_Yellow",
            "A_Red"
    };

    std::vector<std::string> input9 = {
            "B_Yellow",
            "D_Red",
            "C_Yellow",
            "C_Red",
            "D_Yellow",
            "F_Red",
            "B_Yellow",
            "G_Red",
            "C_Yellow",
            "F_Red",
            "F_Yellow",
            "C_Red",
            "G_Yellow",
            "E_Red",
            "A_Yellow",
            "F_Red",
            "E_Yellow",
            "E_Red",
            "C_Yellow",
            "B_Red",
            "G_Yellow",
            "E_Red",
            "F_Yellow",
            "D_Red",
            "A_Yellow",
            "F_Red",
            "D_Yellow"
    };

    std::vector<std::string> input10 = {
            "D_Red",
            "B_Yellow",
            "B_Red",
            "A_Yellow",
            "E_Red",
            "F_Yellow",
            "B_Red",
            "C_Yellow",
            "F_Red",
            "D_Yellow",
            "E_Red",
            "A_Yellow",
            "B_Red",
            "D_Yellow",
            "D_Red",
            "B_Yellow",
            "G_Red",
            "F_Yellow",
            "E_Red",
            "A_Yellow",
            "F_Red",
            "B_Yellow",
            "D_Red",
            "C_Yellow"
    };

    std::vector<std::string> input11 = {
            "A_Yellow",
            "G_Red",
            "F_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "B_Yellow",
            "F_Red",
            "F_Yellow",
            "B_Red",
            "G_Yellow",
            "B_Red",
            "A_Yellow",
            "G_Red",
            "C_Yellow",
            "D_Red",
            "F_Yellow",
            "C_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "B_Red",
            "E_Yellow",
            "A_Red",
            "B_Yellow",
            "G_Red",
            "G_Yellow",
            "F_Red",
            "G_Yellow"
    };

    std::string output1 = CodeWars().who_is_winner(input1);
    std::string output2 = CodeWars().who_is_winner(input2);
    std::string output3 = CodeWars().who_is_winner(input3);
    std::string output4 = CodeWars().who_is_winner(input4);
    std::string output5 = CodeWars().who_is_winner(input5);
    std::string output6 = CodeWars().who_is_winner(input6);
    std::string output7 = CodeWars().who_is_winner(input7);
    std::string output8 = CodeWars().who_is_winner(input8);
    std::string output9 = CodeWars().who_is_winner(input9);
    std::string output10 = CodeWars().who_is_winner(input10);
    std::string output11 = CodeWars().who_is_winner(input11);

    std::string expected_output1 = "Yellow";
    std::string expected_output2 = "Yellow";
    std::string expected_output3 = "Red";
    std::string expected_output4 = "Red";
    std::string expected_output5 = "Yellow";
    std::string expected_output6 = "Yellow";
    std::string expected_output7 = "Yellow";
    std::string expected_output8 = "Yellow";
    std::string expected_output9 = "Red";
    std::string expected_output10 = "Red";
    std::string expected_output11 = "Red";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
    EXPECT_EQ(output5, expected_output5);
    EXPECT_EQ(output6, expected_output6);
    EXPECT_EQ(output7, expected_output7);
    EXPECT_EQ(output8, expected_output8);
    EXPECT_EQ(output9, expected_output9);
    EXPECT_EQ(output10, expected_output10);
    EXPECT_EQ(output11, expected_output11);
}*/

// ----------------------------------------------------------------------------------------------------------

// Crack the Pin Kata Tests

/*TEST(Crack_the_Pin, crack) {
    std::string input1 = "827ccb0eea8a706c4c34a16891f84e7b";
    std::string input2 = "86aa400b65433b608a9db30070ec60cd";

    std::string output1 = CodeWars().crack(input1);
    std::string output2 = CodeWars().crack(input2);

    std::string expected_output1 = "12345";
    std::string expected_output2 = "00078";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
}*/

// ----------------------------------------------------------------------------------------------------------

// Alphabet War Kata Tests

TEST(Alphabet_War, alphabetWar) {
    std::string input1 = "z";
    std::string input2 = "zdqmwpbs";
    std::string input3 = "zzzzs";
    std::string input4 = "wwwwww";

    std::string output1 = CodeWars().alphabetWar(input1);
    std::string output2 = CodeWars().alphabetWar(input2);
    std::string output3 = CodeWars().alphabetWar(input3);
    std::string output4 = CodeWars().alphabetWar(input4);

    std::string expected_output1 = "Right side wins!";
    std::string expected_output2 = "Let's fight again!";
    std::string expected_output3 = "Right side wins!";
    std::string expected_output4 = "Left side wins!";

    EXPECT_EQ(output1, expected_output1);
    EXPECT_EQ(output2, expected_output2);
    EXPECT_EQ(output3, expected_output3);
    EXPECT_EQ(output4, expected_output4);
}