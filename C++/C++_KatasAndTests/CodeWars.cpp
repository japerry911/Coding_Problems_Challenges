//
// Created by John Perry on 2020-06-24.
//

#include "CodeWars.h"
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <algorithm>
#include <map>
#include <regex>

/*
---Mumbling---
This time no story, no theory. The examples below show you how to write function accum:

Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z.
 */

// Solution 1
/*std::string CodeWars::mumbling(const std::string &input_string) const {
    std::string return_string;

    for (size_t i = 0; i < input_string.size(); ++i) {
        for (size_t a = 0; a < i + 1; ++a) {
            if (a == 0) {
                return_string += static_cast<char>(std::toupper(input_string[i]));
            } else {
                return_string += static_cast<char>(std::tolower(input_string[i]));
            }
        }

        if (i < input_string.size() - 1) {
            return_string += "-";
        }
    }

    return return_string;
}*/

// Solution 2
std::string CodeWars::mumbling(const std::string &input_string) const {
    std::stringstream return_stream;

    for (size_t i = 0; i < input_string.size(); ++i) {
        return_stream << std::string(1, std::toupper(input_string[i]));
        return_stream << std::string(i, std::tolower(input_string[i]));

        if (i < input_string.size() - 1) {
            return_stream << "-";
        }
    }

    return return_stream.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---Alternating Split Encryption---
For building the encrypted string:
Take every 2nd char from the string, then the other chars, that are not every 2nd char, and concat them as new String.
Do this n times!

Examples:

"This is a test!", 1 -> "hsi  etTi sats!"
"This is a test!", 2 -> "hsi  etTi sats!" -> "s eT ashi tist!"
Write two methods:

std::string encrypt(std::string text, int n)
std::string decrypt(std::string encryptedText, int n)
For both methods:
If the input-string is null or empty return exactly this value!
If n is <= 0 then return the input text.
 */

// Solution 1
std::string CodeWars::encrypt_alternating_split(const std::string &text, int n) const {
    if (n <= 0 || text.empty()) {
        return text;
    }

    std::string encrypted_string;

    for (size_t i = 1; i < text.size(); i+=2) {
        encrypted_string += text[i];
    }

    for (size_t i = 0; i < text.size(); i+=2) {
        encrypted_string += text[i];
    }

    return encrypt_alternating_split(encrypted_string, n - 1);
}

std::string CodeWars::decrypt_alternating_split(const std::string &encrypted_text, int n) const {
    if (n <= 0 || encrypted_text.empty()) {
        return encrypted_text;
    }

    std::string decrypted_text(encrypted_text.size(), '*');

    int current_index = 1;
    for (size_t i = 0; i < floor(encrypted_text.size() / 2); ++i) {
        decrypted_text[current_index] = encrypted_text[i];
        current_index += 2;
    }

    current_index = 0;
    for (size_t i = floor(encrypted_text.size() / 2); i < encrypted_text.size(); ++i) {
        decrypted_text[current_index] = encrypted_text[i];
        current_index += 2;
    }

    return decrypt_alternating_split(decrypted_text, n - 1);
}

// ----------------------------------------------------------------------------------------------------------

/*
---Take a Ten Minute Walk---
You live in the city of Cartesia where all roads are laid out in a perfect grid. You arrived ten minutes too early to
an appointment, so you decided to take the opportunity to go for a short walk. The city provides its citizens with a
Walk Generating App on their phones -- everytime you press the button it sends you an array of one-letter strings
representing directions to walk (eg. ['n', 's', 'w', 'e']). You always walk only a single block in a direction and
you know it takes you one minute to traverse one city block, so create a function that will return true if the walk
the app gives you will take you exactly ten minutes (you don't want to be early or late!) and will, of course,
return you to your starting point. Return false otherwise.

Note: you will always receive a valid array containing a random assortment of direction letters
('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).
 */

bool CodeWars::is_valid_walk(const std::vector<char> &walk) const {
    if (walk.size() != 10) {
        return false;
    }

    int vertical = 0;
    int horizontal = 0;

    for (const auto &walk_direction : walk) {
        switch (walk_direction) {
            case 'n':
                ++vertical;
                break;

            case 's':
                --vertical;
                break;

            case 'e':
                ++horizontal;
                break;

            case 'w':
                --horizontal;
                break;

            default:
                throw std::invalid_argument("Not a valid direction.");
        }
    }

    return vertical == 0 && horizontal == 0;
}

// ----------------------------------------------------------------------------------------------------------


/*
---Bit Counting---
Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary
representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
 */

unsigned int CodeWars::count_bits(const unsigned long long &n) const {
    std::string bits_string = std::bitset<64>(n).to_string();
    int one_counter = 0;

    for (const auto &bit : bits_string) {
        if (bit == '1') {
            ++one_counter;
        }
    }

    return one_counter;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Consecutive Strings---
You are given an array strarr of strings and an integer k. Your task is to return the first longest string
consisting of k consecutive strings taken in the array.

Example:
longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"], 2) --> "abigailtheta"

n being the length of the string array, if n = 0 or k > n or k <= 0 return "".

Note
consecutive strings : follow one after another without an interruption

Rules from discussion:
 - No using duplicates, only first appearance
 - First longest match if there is tie
 */

std::string CodeWars::longest_consec(const std::vector<std::string> &str_arr, const int &k) const {
    if (k <= 0) {
        return "";
    }

    std::string return_string;
    int max_length = 0;

    for (size_t i = 0; i < str_arr.size(); ++i) {
        std::string temp_string;
        int current_length = 0;

        if (i + k > str_arr.size()) {
            break;
        }

        for (size_t c = i; c < i + k; ++c) {
            temp_string += str_arr[c];
            current_length += str_arr[c].size();
        }

        if (current_length > max_length) {
            max_length = current_length;
            return_string = temp_string;
        }
    }

    return return_string;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Alternate Capitalization---
 Given a string, capitalize the letters that occupy even indexes and odd indexes separately, and return as shown below.
 Index 0 will be considered even.

For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF']. See test cases for more examples.

The input will be a lowercase string with no spaces.

Good luck!

If you like this Kata, please try:
 */

std::pair<std::string, std::string> CodeWars::capitalize(const std::string &s) const {
    std::string string_even = s;
    std::string string_odd = s;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            string_even[i] = std::toupper(string_even[i]);
        } else {
            string_odd[i] = std::toupper(string_odd[i]);
        }
    }

    return {string_even, string_odd};
}

// ----------------------------------------------------------------------------------------------------------

/*
---SumsOfPairs---
Let us consider this example (array written in general format):

ls = [0, 1, 3, 6, 10]

Its following parts:

ls = [0, 1, 3, 6, 10]
ls = [1, 3, 6, 10]
ls = [3, 6, 10]
ls = [6, 10]
ls = [10]
ls = []
The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]

The function parts_sums (or its variants in other languages) will take as parameter a list ls and return a list of
the sums of its parts as defined above.

Other Examples:
ls = [1, 2, 3, 4, 5, 6]
parts_sums(ls) -> [21, 20, 18, 15, 11, 6, 0]

ls = [744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358]
parts_sums(ls) -> [10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414, 9291270, 2581057, 2580168, 2579358,
                   0]
Notes
Some lists can be long.
Please ask before translating: some translations are already written and published when/if the kata is approved.
 */

std::vector<unsigned long long> CodeWars::parts_sum(const std::vector<unsigned long long> &ls) {
    std::vector<unsigned long long> return_vector;
    unsigned long long vector_current_total = 0;

    for (const auto &part : ls) {
        vector_current_total += part;
    }

    for (const auto part : ls) {
        return_vector.push_back(vector_current_total);
        vector_current_total -= part;
    }

    return_vector.push_back(0);

    return return_vector;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Validate Credit Card Number---
In this Kata, you will implement the Luhn Algorithm, which is used to help validate credit card numbers.

Given a positive integer of up to 16 digits, return true if it is a valid credit card number, and false if it is not.

Here is the algorithm:

Double every other digit, scanning from right to left, starting from the second digit (from the right).

Another way to think about it is: if there are an even number of digits, double every other digit starting with the
first; if there are an odd number of digits, double every other digit starting with the second:

1714 ==> [1*, 7, 1*, 4] ==> [2, 7, 2, 4]

12345 ==> [1, 2*, 3, 4*, 5] ==> [1, 4, 3, 8, 5]

891 ==> [8, 9*, 1] ==> [8, 18, 1]
If a resulting number is greater than 9, replace it with the sum of its own digits (which is the same as subtracting 9
from it):

[8, 18*, 1] ==> [8, (1+8), 1] ==> [8, 9, 1]

or:

[8, 18*, 1] ==> [8, (18-9), 1] ==> [8, 9, 1]
Sum all of the final digits:

[8, 9, 1] ==> 8 + 9 + 1 = 18
Finally, take that sum and divide it by 10. If the remainder equals zero, the original credit card number is valid.

18 (modulus) 10 ==> 8 , which is not equal to 0, so this is not a valid credit card number

Notes:
 -
   a. even: double 0 += 2
   b. odd: double 1 += 2
 - Over 9, subtract 9 from it
 - Sum the final digits, and return true if divisible by 10, otherwise return false (not valid credit card)
 */

bool CodeWars::validate(long long int n) const {
    std::vector<int> n_vector;

    while (n != 0) {
        n_vector.push_back(n % 10);
        n = n / 10;
    }

    std::reverse(n_vector.begin(), n_vector.end());

    bool is_even = (n_vector.size() % 2 == 0);
    int validation_total = 0;

    for (size_t i = 0; i < n_vector.size(); ++i) {
        if (is_even) {
            if (i % 2 == 0) {
                int squared_number = n_vector[i] * 2;
                squared_number = (squared_number > 9 ? squared_number - 9 : squared_number);
                validation_total += squared_number;
            } else {
                validation_total += n_vector[i];
            }
        } else {
            if (i % 2 != 0) {
                int squared_number = n_vector[i] * 2;
                squared_number = (squared_number > 9 ? squared_number - 9 : squared_number);
                validation_total += squared_number;
            } else {
                validation_total += n_vector[i];
            }
        }
    }

    return validation_total % 10 == 0;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Help the Bookseller!---
A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or
more characters. The 1st character of a code is a capital letter which defines the book category.

In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which
indicates the quantity of books of this code in stock.

For example an extract of a stocklist could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or
L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

M = {"A", "B", "C", "W"}
or
M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity
according to each category.

For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):

  (A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to
"BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.

If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).

Note:
In the result codes and their values are in the same order as in M.
 */

std::string CodeWars::stock_summary(const std::vector<std::string> &lst,
                                    const std::vector<std::string> &categories) const {
    if (lst.empty() || categories.empty()) {
        return "";
    }

    std::map<char, int> stock_map;

    for (const auto &category :categories) {
        stock_map[category[0]] = 0;
    }

    for (const auto &book_string : lst) {
        char first_letter = book_string[0];
        std::string quantity_in_stock_raw;
        bool numbers_bool = false;

        for (const auto &character : book_string) {
            if (std::isspace(character)) {
                numbers_bool = true;
            } else if (numbers_bool) {
                quantity_in_stock_raw += character;
            }
        }

        int quantity_int_stock = std::stoi(quantity_in_stock_raw);

        if (stock_map.count(first_letter) == 1) {
            stock_map[first_letter] += quantity_int_stock;
        }
    }

    std::stringstream return_string;
    bool first = true;

    for (const auto &category: categories) {
        const char current_category = category[0];
        const int total_quantity = stock_map[category[0]];

        if (first) {
            return_string << "(" << current_category << " : " << total_quantity << ")";
            first = false;
        } else {
            return_string << " - (" << current_category << " : " << total_quantity << ")";
        }
    }

    return return_string.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---The Deaf Rats of Hamelin---
The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

But some of the rats are deaf and are going the wrong way!

Kata Task
How many deaf rats are there?

Legend
P = The Pied Piper
O~ = Rat going left
~O = Rat going right
Example
ex1 ~O~O~O~O P has 0 deaf rats
ex2 P O~ O~ ~O O~ has 1 deaf rat
ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
 */

int CodeWars::count_deaf_rats(const std::string &town) const {
    int deaf_rat_count = 0;
    bool face_right = true;
    char *first_half_part = nullptr;

    for (auto element : town) {
        if (element == 'P') {
            face_right = false;
        } else if (std::isspace(element)) {
            continue;
        } else if (first_half_part) {
            if (face_right) {
                if (*first_half_part == '~') {
                    first_half_part = nullptr;
                    ++deaf_rat_count;
                } else {
                    first_half_part = nullptr;
                }
            } else {
                if (*first_half_part == '~') {
                    first_half_part = nullptr;
                } else {
                    ++deaf_rat_count;
                    first_half_part = nullptr;
                }
            }
        } else {
            first_half_part = &element;
        }
    }

    return deaf_rat_count;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Roman Numerals Encoder---
Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral
representation of that integer.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping
any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is
written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Example:

solution(1000); // should return "M"
Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
Remember that there can't be more than 3 identical symbols in a row.

More about roman numerals - http://en.wikipedia.org/wiki/Roman_numerals

Examples:
 - 1666 = MDCLXVI
 - 2008 = MMVIII
 - 1990 = MCMXC
 - 69 = LXIX
 - 98 = XCVIII
 - 109 = CIX
 - 786 = DCCLXXXVI
 - 1298 = MCCXCVIII
 - 2018 = MMXVIII

Looked-Up Rules:
 - D, L, V can only appear once
 - Numerals must be arranged in descending order of size
 - M, C, and X cannot be equal or exceeded by smaller denominations
 - I can only be subtracted from V and X
 - X can only be subtracted from L, and C
 - C can be subtracted from D
 - Subtraction can only happen with one element being subtractor
 */

// Solution 1:
/*std::string CodeWars::solution(int number) const {
    std::stringstream return_roman_numerals;
    int number_added = 0;

    if (number >= 1000) {
        number_added = floor(number / 1000);

        for (size_t i = 0; i < number_added; ++i) {
            return_roman_numerals << 'M';
        }

        number %= 1000;
    }

    if (number >= 900) {
        return_roman_numerals << 'C' << 'M';
        number -= 900;
    }

    if (number >= 500) {
        return_roman_numerals << 'D';
        number %= 500;
    }

    if (number >= 400) {
        return_roman_numerals << 'C' << 'D';
        number -= 400;
    }

    if (number >= 100) {
        number_added = floor(number / 100);

        for (size_t i = 0; i < number_added; ++i) {
            return_roman_numerals << 'C';
        }

        number %= 100;
    }

    if (number >= 90) {
        return_roman_numerals << 'X' << 'C';
        number -= 90;
    }

    if (number >= 50 && number < 90) {
        return_roman_numerals << 'L';
        number -= 50;
    }

    if (number >= 40 && number < 50) {
        return_roman_numerals << 'X' << 'L';
        number -= 40;
    }

    if (number >= 10) {
        number_added = floor(number / 10);

        for (size_t i = 0; i < number_added; ++i) {
            return_roman_numerals << 'X';
        }

        number %= 10;
    }

    if (number == 9) {
        return_roman_numerals << 'I' << 'X';
        number -= 9;
    }

    if (number < 9 && number >= 5) {
        return_roman_numerals << 'V';
        number -= 5;
    }

    if (number == 4) {
        return_roman_numerals << 'I' << 'V';
        number -= 4;
    }

    for (size_t i = 0; i < number; ++i) {
        return_roman_numerals << 'I';
    }

    return return_roman_numerals.str();
}*/

// Solution 2:
std::string CodeWars::solution(int number) const {
    std::stringstream return_roman_numerals;
    const std::map<int, std::string> bases = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (auto it = bases.crbegin(); it != bases.crend();) {
        if (number >= it->first) {
            number -= it->first;
            return_roman_numerals << it->second;
        } else {
            ++it;
        }
    }

    return return_roman_numerals.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---Primorial of a Number---
Definition (Primorial Of a Number)
Is similar to factorial of a number, In primorial, not all the natural numbers get multiplied, only prime numbers are
 multiplied to calculate the primorial of a number. It's denoted with P#.

Task
Given a number N , calculate its primorial.!alt!alt
Notes
Only positive numbers will be passed (N > 0) .
Input >> Output Examples:
1- numPrimorial (3) ==> return (30)
Explanation:
Since the passed number is (3) ,Then the primorial should obtained by multiplying 2 * 3 * 5 = 30 .

Mathematically written as , P3# = 30 .
2- numPrimorial (5) ==> return (2310)
Explanation:
Since the passed number is (5) ,Then the primorial should obtained by multiplying 2 * 3 * 5 * 7 * 11 = 2310 .

Mathematically written as , P5# = 2310 .
3- numPrimorial (6) ==> return (30030)
Explanation:
Since the passed number is (6) ,Then the primorial should obtained by multiplying 2 * 3 * 5 * 7 * 11 * 13 = 30030 .

Mathematically written as , P6# = 30030 .
 */

unsigned long long CodeWars::num_primorial(const unsigned short int &number) const {
    if (number == 0) {
        return 0;
    }

    int counter = 1;
    unsigned long long return_output = 2;
    int current_number = 3;

    while (counter < number) {
        if (current_number == 3 || current_number == 5) {
            return_output *= current_number;
            ++current_number;
            ++counter;
            continue;
        } else if (current_number % 2 == 0 || current_number % 3 == 0 || current_number % 5 == 0) {
            ++current_number;
            continue;
        }

        return_output *= current_number;

        ++counter;
        ++current_number;
    }

    return return_output;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Convert all the Cases!---
You must write a function that changes to a given case. It must be able to handle all three case types:

cpp> changeCase("snakeCase", "snake")
"snake_case"
cpp> changeCase("some-lisp-name", "camel")
"someLispName"
cpp> changeCase("map_to_all", "kebab")
"map-to-all"
cpp> changeCase("doHTMLRequest", "kebab")
"do-h-t-m-l-request"
cpp> changeCase("invalid-inPut_bad", "kebab")
""
cpp> changeCase("valid-input", "huh???")
""
cpp> changeCase("", "camel")
""
Your function must deal with invalid input as shown, though it will only be passed strings. Furthermore, all valid
identifiers will be lowercase except when necessary, in other words on word boundaries in camelCase.
 */ //https://www.codewars.com/kata/59be8c08bf10a49a240000b1/train/cpp

std::string CodeWars::change_case(const std::string &identifier, const std::string &target_case) const {
    if ((target_case != "snake" && target_case != "camel" && target_case != "kebab") || identifier == "") {
        return "";
    }

    std::stringstream return_string;
    char delimiter = '\0';
    int types = 0;
    bool has_uppercase = false;

    for (const auto &character : identifier) {
        if (std::isupper(character) && !has_uppercase) {
            ++types;
            delimiter = 'C';
            has_uppercase = true;
        } else if (character == '_' && delimiter != '_') {
            ++types;
            delimiter = '_';
        } else if (character == '-' && delimiter != '-') {
            ++types;
            delimiter = '-';
        }

        if (types > 1) {
            return "";
        }
    }
    if (types == 0) {
        return identifier;
    }

    bool is_upper = false;

    for (const auto &character : identifier) {
        if ((delimiter == 'C' && std::isupper(character)) || (character == delimiter)) {
            if (target_case == "snake") {
                return_string << '_';
            } else if (target_case == "kebab") {
                return_string << '-';
            } else { //Must be camel
                is_upper = true;
            }

            if (delimiter != 'C') {
                continue;
            }
        }

        if (is_upper) {
            return_string << std::string(1, std::toupper(character));
            is_upper = false;
        } else {
            return_string << std::string(1, std::tolower(character));
        }
    }

    return return_string.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---Sudoku Solution Validator--- GOOD LUCK :D Rank Points: 4 kyu
Sudoku Background
Sudoku is a game played on a 9x9 grid. The goal of the game is to fill all cells of the grid with digits from 1 to 9,
so that each column, each row, and each of the nine 3x3 sub-grids (also known as blocks) contain all of the digits from 1 to 9.
(More info at: http://en.wikipedia.org/wiki/Sudoku)

Sudoku Solution Validator
Write a function validSolution/ValidateSolution/valid_solution() that accepts a 2D array representing a Sudoku board,
and returns true if it is a valid solution, or false otherwise. The cells of the sudoku board may also contain 0's,
which will represent empty cells. Boards containing one or more zeroes are considered to be invalid solutions.

The board is always 9 cells by 9 cells, and every cell only contains integers from 0 to 9.

Examples
validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2],
  [6, 7, 2, 1, 9, 5, 3, 4, 8],
  [1, 9, 8, 3, 4, 2, 5, 6, 7],
  [8, 5, 9, 7, 6, 1, 4, 2, 3],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 6, 1, 5, 3, 7, 2, 8, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 4, 5, 2, 8, 6, 1, 7, 9]
]); // => true
validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2],
  [6, 7, 2, 1, 9, 0, 3, 4, 8],
  [1, 0, 0, 3, 4, 2, 5, 6, 0],
  [8, 5, 9, 7, 6, 1, 0, 2, 0],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 0, 1, 5, 3, 7, 2, 1, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 0, 0, 4, 8, 1, 1, 7, 9]
]); // => false
 */

bool CodeWars::valid_solution(const unsigned int board[9][9]) const {
    int total_sum = 45;
    std::map<int, int> column_sums = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}};
    std::map<int, int> box_sums = {{0, 0}, {3, 0}, {6, 0}};

    for (size_t r = 0; r < 9; ++r) {
        int row_sum = 0;

        for (size_t c = 0; c < 9; ++c) {
            if (board[r][c] > 9 || board[r][c] < 1) {
                return false;
            }

            row_sum += board[r][c];

            column_sums[c] += board[r][c];

            if (c < 3) {
                box_sums[0] += board[r][c];
            } else if (c >= 3 && c < 6) {
                box_sums[3] += board[r][c];
            } else {
                box_sums[6] += board[r][c];
            }
        }

        if (row_sum != 45) {
            return false;
        }

        if ((r + 1) % 3 == 0 && r != 0) {
            if (box_sums[0] != 45 || box_sums[3] != 45 || box_sums[6] != 45) {
                return false;
            }

            box_sums[0] = 0;
            box_sums[3] = 0;
            box_sums[6] = 0;
        }
    }

    for (const auto &column_sum : column_sums) {
        if (column_sum.second != 45) {
            return false;
        }
    }

    return true;
}

// ----------------------------------------------------------------------------------------------------------

/*
NOT SOLVED: ---Explosive Sum---
- https://www.codewars.com/kata/52ec24228a515e620b0005ef/discuss
How many ways can you make the sum of a number?
From wikipedia: https://en.wikipedia.org/wiki/Partition_(number_theory)#

In number theory and combinatorics, a partition of a positive integer n, also called an integer partition, is a way of
writing n as a sum of positive integers. Two sums that differ only in the order of their summands are considered the
same partition. If order matters, the sum becomes a composition. For example, 4 can be partitioned in five distinct
ways:

4
3 + 1
2 + 2
2 + 1 + 1
1 + 1 + 1 + 1
Examples
Basic
exp_sum(1) // 1
exp_sum(2) // 2  -> 1+1 , 2
exp_sum(3) // 3 -> 1+1+1, 1+2, 3
exp_sum(4) // 5 -> 1+1+1+1, 1+1+2, 1+3, 2+2, 4
exp_sum(5) // 7 -> 1+1+1+1+1, 1+1+1+2, 1+1+3, 1+2+2, 1+4, 5, 2+3

exp_sum(10) // 42
Explosive
exp_sum(50) // 204226
exp_sum(80) // 15796476
exp_sum(100) // 190569292
 */

unsigned long long CodeWars::exp_sum(const unsigned int &n) const {
    unsigned long long counter[n + 2][n + 2];

    counter[0][n + 1] = 1;

    for (int i = n; i >= 1; --i) {
        for (int a = 0; a <= n; ++a) {
            counter[a][i] = counter[a][i + 1];

            if (a - i >= 0) {
                counter[a][i] = (counter[a][i] + counter[a - i][i]);
            }
        }
    }

    return counter[n][1];

    /*unsigned long long explosive_sum = 0;
    unsigned int partition[n];
    int last_element_index = 0;
    partition[last_element_index] = n;

    while (true) {
        ++explosive_sum;

        unsigned int rem_val = 0;
        while (last_element_index >= 0 && partition[last_element_index] == 1) {
            rem_val += partition[last_element_index];
            --last_element_index;
        }

        if (last_element_index < 0) {
            break;
        }

        --partition[last_element_index];
        ++rem_val;

        while (rem_val > partition[last_element_index]) {
            partition[last_element_index + 1] = partition[last_element_index];
            rem_val -= partition[last_element_index];
            ++last_element_index;
        }

        partition[last_element_index + 1] = rem_val;
        ++last_element_index;
    }

    return explosive_sum;*/
}

// ----------------------------------------------------------------------------------------------------------

/*
---Unwanted Dollars---
If you're faced with an input box, like this:

                                           +--------------+
  Enter the price of the item, in dollars: |              |
                                           +--------------+
do you put the $ sign in, or not? Inevitably, some people will type a $ sign and others will leave it out.
The instructions could be made clearer - but that won't help those annoying people who never read instructions anyway.

A better solution is to write code that can handle the input whether it includes a $ sign or not.

So, we need a simple function that converts a string representing a number (possibly with a $ sign in front of it)
into the number itself.

Remember to consider negative numbers (the - sign may come either before or after the $ sign, if there is one), and
any extraneous space characters (leading, trailing, or around the $ sign) that the users might put in. You do not need
to handle trailing characters other than spaces (e.g. "1.2 3"). If the given string does not represent a number,
(either with or without a $ sign), return 0.0 .
 */

double CodeWars::money_value(const std::string &s) const {
    double return_double = 0.0;
    std::stringstream  ss;

    for (const auto &character : s) {
        if (character != '$' && !std::isspace(character)) {
            ss << character;
        }
    }

    ss >> return_double;

    return return_double;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Help Mrs Jefferson---
Mrs Jefferson is a great teacher. One of her strategies that helped her to reach astonishing results in the learning
process is to have some fun with her students. At school, she wants to make an arrangement of her class to play a
certain game with her pupils. For that, she needs to create the arrangement with the minimum amount of groups that
have consecutive sizes.

Let's see. She has 14 students. After trying a bit she could do the needed arrangement: [5, 4, 3, 2]

one group of 5 students
another group of 4 students
then, another one of 3
and finally, the smallest group of 2 students.
As the game was a success, she was asked to help to the other classes to teach and show the game. That's why she
desperately needs some help to make this required arrangements that make her spend a lot of time.

To make things worse, she found out that there are some classes with some special number of students that is
impossible to get that arrangement.

Please, help this teacher!

Your code will receive the number of students of the class. It should output the arrangement as an array with the
consecutive sizes of the groups in decreasing order.

For the special case that no arrangement of the required feature is possible the code should output [-1]

The value of n is unknown and may be pretty high because some classes joined to to have fun with the game.

You may see more example tests in the Example Tests Cases Box.
 */

std::vector<int> CodeWars::shortest_arrang(const int &n) const {
    std::vector<int> return_vector;
    int start_point = ceil(n / 2.0);

    for (size_t i = start_point; i > 0; --i) {
        return_vector.clear();
        return_vector.push_back(i);
        int total = i;

        for (size_t a = i - 1; a > 0; --a) {
            total += a;

            if (total > n) {
                break;
            } else if (total == n) {
                return_vector.push_back(a);
                return return_vector;
            } else {
                return_vector.push_back(a);
            }
        }
    }

    return {-1};
}

// ----------------------------------------------------------------------------------------------------------

/*
---Alphabet War - Airstrike - Letters Massacre---
There is a war and nobody knows - the alphabet war! There are two groups of hostile letters. The tension between
left side letters and right side letters was too high and the war began. The letters called airstrike to help them in
war - dashes and dots are spreaded everywhere on the battlefield.

Task
Write a function that accepts fight string consists of only small letters and * which means a bomb drop place.
Return who wins the fight after bombs are exploded. When the left side wins return Left side wins!, when the right
side wins return Right side wins!, in other case return Let's fight again!.

The left side letters and their power:

 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3
 d - 2
 z - 1
The other letters don't have power and are only victims.
The * bombs kills the adjacent letters ( i.e. aa*aa => a___a, **aa** => ______ );

Example
AlphabetWar("s*zz");           //=> Right side wins!
AlphabetWar("*zd*qm*wp*bs*"); //=> Let's fight again!
AlphabetWar("zzzz*s*");       //=> Right side wins!
AlphabetWar("www*www****z");  //=> Left side wins!
 */

// Was working on - Abandoned due to trying different method
/*std::string CodeWars::alphabet_war(const std::string &fight) const {
    std::string fight_copy = fight;
    int adjuster = 0;
    std::map<char, int> scoring_key_left = {{'w', 4}, {'p', 3}, {'b', 2}, {'s', 1}};
    std::map<char, int> scoring_key_right = {{'m', 4}, {'q', 3}, {'d', 2}, {'z', 1}};

    for (size_t i = 0; i < fight.size(); ++i) {
        if (fight[i] == '*') {
            bool before_bomb = false;
            bool after_bomb = false;

            if (fight[i - 1] == '*' || i == 0 || i - adjuster == 0) {
                before_bomb = true;
            }

            if (fight[i + 1] == '*') {
                after_bomb = true;
            }

            int erase_starting_index = (before_bomb ? i : i - 1);

            int erase_explosion_radius = (before_bomb && after_bomb ? 1 : !before_bomb && !after_bomb ? 3 : 2);

            fight_copy.erase(erase_starting_index - adjuster, erase_explosion_radius);
            adjuster += erase_explosion_radius;
        }
    }

    int score_left = 0;
    int score_right = 0;

    for (const auto &character : fight_copy) {
        if (scoring_key_left.find(character) != scoring_key_left.end()) {
            score_left += scoring_key_left[character];
        } else if (scoring_key_right.find(character) != scoring_key_right.end()) {
            score_right += scoring_key_right[character];
        }
    }

    if (score_left == score_right) {
        return "Let's fight again!";
    } else if (score_left > score_right) {
        return "Left side wins!";
    } else {
        return "Right side wins!";
    }
}*/

std::string CodeWars::alphabet_war(const std::string &fight) const {
    std::map<char, int> scoring_key_left = {{'w', 4}, {'p', 3}, {'b', 2}, {'s', 1}};
    std::map<char, int> scoring_key_right = {{'m', 4}, {'q', 3}, {'d', 2}, {'z', 1}};
    int left_score = 0;
    int right_score = 0;
    bool before_explosion_radius = false;
    bool after_explosion_radius = false;

    for (size_t i = 0; i < fight.size(); ++i) {
        if (fight[i] == '*') {
            before_explosion_radius = true;
        } else {
            if (i + 1 < fight.size() && fight[i + 1] == '*') {
                after_explosion_radius = true;
            } else {
                after_explosion_radius = false;
            }

            if (!before_explosion_radius && !after_explosion_radius) {
                if (scoring_key_left.find(fight[i]) != scoring_key_left.end()) {
                    left_score += scoring_key_left[fight[i]];
                } else if (scoring_key_right.find(fight[i]) != scoring_key_right.end()) {
                    right_score += scoring_key_right[fight[i]];
                }
            }

            before_explosion_radius = false;
        }
    }

    if (left_score == right_score) {
        return "Let's fight again!";
    } else if (left_score > right_score) {
        return "Left side wins!";
    } else {
        return "Right side wins!";
    }
}

// ----------------------------------------------------------------------------------------------------------

/*
---Complete the Pattern #8 - Number Pyramid---
###Task:

You have to write a function pattern which creates the following Pattern(See Examples) upto n(parameter) number of rows.

####Rules/Note:

If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.
All the lines in the pattern have same length i.e equal to the number of characters in the last line.
Range of n is (-∞,100]
###Examples:

pattern(5):

    1
   121
  12321
 1234321
123454321
pattern(10):

         1
        121
       12321
      1234321
     123454321
    12345654321
   1234567654321
  123456787654321
 12345678987654321
1234567890987654321
pattern(15):

              1
             121
            12321
           1234321
          123454321
         12345654321
        1234567654321
       123456787654321
      12345678987654321
     1234567890987654321
    123456789010987654321
   12345678901210987654321
  1234567890123210987654321
 123456789012343210987654321
12345678901234543210987654321
pattern(20):

                   1
                  121
                 12321
                1234321
               123454321
              12345654321
             1234567654321
            123456787654321
           12345678987654321
          1234567890987654321
         123456789010987654321
        12345678901210987654321
       1234567890123210987654321
      123456789012343210987654321
     12345678901234543210987654321
    1234567890123456543210987654321
   123456789012345676543210987654321
  12345678901234567876543210987654321
 1234567890123456789876543210987654321
123456789012345678909876543210987654321
 */

std::string CodeWars::pattern(const int &n) const {
    if (n <= 0) {
        return "";
    }

    std::stringstream pyramid;
    int row_size = (n * 2) - 1;
    int mid_point = ceil(row_size / 2.0);

    for (size_t i = 0 ;i < n; ++i) {
        int start = mid_point - i;
        int end = mid_point + i;
        int counter = 1;
        bool count_down = false;

        for (size_t r = 0; r < row_size; ++r) {
            if (r + 1 >= start && r + 1 <= end) {
                int output;

                if (counter >= 10) {
                    output = counter % 10;
                } else {
                    output = counter;
                }

                pyramid << output;

                if (counter == i + 1) {
                    count_down = true;
                }

                count_down ? --counter : ++counter;
            } else {
                pyramid << ' ';
            }
        }

        if (i + 1 < n) {
            pyramid << '\n';
        }
    }

    return pyramid.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---Strings Mix---
Given two strings s1 and s2, we want to visualize how different the two strings are. We will only take into account the
lowercase letters (a to z). First let us count the frequency of each lowercase letters in s1 and s2.

s1 = "A aaaa bb c"

s2 = "& aaa bbb c d"

s1 has 4 'a', 2 'b', 1 'c'

s2 has 3 'a', 3 'b', 1 'c', 1 'd'

So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following we will not
consider letters when the maximum of their occurrences is less than or equal to 1.

We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in 1:aaaa stands for
string s1 and aaaa because the maximum for a is 4. In the same manner 2:bbb stands for string s2 and bbb because the
maximum for b is 3.

The task is to produce a string in which each lowercase letters of s1 or s2 appears as many times as its maximum if
this maximum is strictly greater than 1; these letters will be prefixed by the number of the string where they appear
with their maximum value and :. If the maximum is in s1 as well as in s2 the prefix is =:.

In the result, substrings (a substring is for example 2:nnnnn or 1:hhh; it contains the prefix) will be in decreasing
order of their length and when they have the same length sorted in ascending lexicographic order (letters and digits -
more precisely sorted by codepoint); the different groups will be separated by '/'. See examples and "Example Tests".

Hopefully other examples can make this clearer.

s1 = "my&friend&Paul has heavy hats! &"
s2 = "my friend John has many many friends &"
mix(s1, s2) --> "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &"
s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&"
mix(s1, s2) --> "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1="Are the kids at home? aaaaa fffff"
s2="Yes they are here! aaaaa fffff"
mix(s1, s2) --> "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh"

Notes:
 - Return_String order:
    - 1) Qty 2) String number 3) Alphabet
 */

std::string CodeWars::mix(const std::string &s1, const std::string &s2) const {
    std::stringstream ss;
    std::map<char, int> map_s1;
    std::map<char, int> map_s2;
    std::map<int, std::map<int, std::vector<std::string>>, std::greater<int>> final_map;

    for (const auto &character : s1) {
        if (std::islower(character)) {
            if (map_s1.find(character) != map_s1.cend()) {
                ++map_s1[character];
            } else {
                map_s1[character] = 1;
            }
        }
    }

    for (const auto &character : s2) {
        if (std::islower(character)) {
            if (map_s2.find(character) != map_s2.cend()) {
                ++map_s2[character];
            } else {
                map_s2[character] = 1;
            }
        }
    }

    for (const auto &pair : map_s1) {
        if (pair.second < 2) {
            continue;
        }

        std::string value = std::string(pair.second, pair.first);

        if (map_s2.find(pair.first) != map_s2.cend()) {
            if (pair.second > map_s2[pair.first]) {
                final_map[pair.second][1].emplace_back(value);
            } else if (pair.second == map_s2[pair.first]) {
                final_map[pair.second][3].emplace_back(value);
            } else {
                std::string value_s2 = std::string(map_s2[pair.first], pair.first);
                final_map[map_s2[pair.first]][2].emplace_back(value_s2);
            }

            map_s2.erase(pair.first);
        } else {
            final_map[pair.second][1].emplace_back(value);
        }
    }

    for (const auto &pair : map_s2) {
        if (pair.second < 2) {
            continue;
        }

        std::string value = std::string(pair.second, pair.first);

        final_map[pair.second][2].emplace_back(value);
    }

    for (const auto &pair : final_map) {
        for (const auto &pair2 : pair.second) {
            std::vector<std::string> copy_of_vector = pair2.second;
            std::sort(copy_of_vector.begin(), copy_of_vector.end());

            std::string string_number = (pair2.first == 1 ? "1" : pair2.first == 2 ? "2" : "=");

            for (size_t i = 0; i < copy_of_vector.size(); ++i) {
                ss << string_number << ":" << copy_of_vector[i] << "/";
            }
        }
    }

    std::string return_string = ss.str();

    if (return_string == "") {
        return return_string;
    } else {
        return_string.pop_back();
        return return_string;
    }
}

// ----------------------------------------------------------------------------------------------------------

/*
---Errors: Histogram---
In a factory a printer prints labels for boxes. The printer uses colors which, for the sake of simplicity, are named
with letters from a to z (except letters u, w, x or z that are for errors).

The colors used by the printer are recorded in a control string. For example a control string would be aaabbbbhaijjjm
meaning that the printer used three times color a, four times color b, one time color h then one time color a... and
so on.

Sometimes there are problems: lack of colors, technical malfunction and a control string is produced e.g.
uuaaaxbbbbyyhwawiwjjjwwxym where errors are reported with letters u, w, x or z.

You have to write a function hist which given a string will output the errors as a string representing a histogram of
the encountered errors.

Format of the output string:

letter (error letters are sorted in alphabetical order) in a field of 2 characters, a white space, number of error for
that letter in a field of 6, as many "*" as the number of errors for that letter and "\r".

The string has a length greater or equal to one and contains only letters from a to z.

Examples
s="uuaaaxbbbbyyhwawiwjjjwwxym"
hist(s) => "u  2     **\rw  5     *****\rx  2     **"

or with dots to see white spaces:
hist(s) => "u..2.....**\rw..5.....*****\rx..2.....**"

s="uuaaaxbbbbyyhwawiwjjjwwxymzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
hist(s) => "u..2.....**\rw..5.....*****\rx..2.....**\rz..31....*******************************"
or printed:
u  2     **
w  5     *****
x  2     **
z  31    *******************************
Notes
Unfortunately most often Codewars compresses all white spaces into one.
You can see another examples in the "Sample tests".
Translators are welcome for all languages.
 */

std::string CodeWars::hist(const std::string &s) {
    std::stringstream ss;
    std::map<char, int> error_map= {{'u', 0}, {'w', 0}, {'x', 0}, {'z', 0}};

    for (const auto &character : s) {
        if (error_map.find(character) != error_map.cend()) {
            ++error_map[character];
        }
    }

    for (const auto &pair : error_map) {
        int spaces = 5;

        if (pair.second == 0) {
            continue;
        } else if (pair.second >= 10) {
            spaces = 4;
        }

        ss << pair.first << "  " << pair.second << std::string(spaces, ' ');

        for (size_t i = 0; i < pair.second; ++i) {
            ss << '*';
        }

        ss << "\\r";
    }

    std::string return_string = ss.str();

    if (return_string != "") {
        return_string.pop_back();
        return_string.pop_back();
    }

    return return_string;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Tic-Tac-Toe (3D)--- - Not Solved
Regular Tic-Tac-Toe is boring.

That's why in this Kata you will be playing Tic-Tac-Toe in 3D using a 4 x 4 x 4 matrix!

Kata Task
Play the game. Work out who wins.

Return a string

O wins after <n> moves
X wins after <n> moves
No winner
Rules
Player O always goes first
Input moves is list/array/tuple of [x,y,z] (zero based)
Each player takes a turn until you find a winner, or there are no moves left
Four of the same symbols in a row wins
There may be more moves provided than are necessary to finish the game - that is for you to figure out

e e e e
e e e e
e e e e
e e e e
--------
e e e e
e e e e
O O O O
e e e e
--------
e e e e
e e e e
X X X e
e e e e
--------
e e e e
e e e e
e e e e
e e e e


 */

// Solution 1
/*std::string CodeWars::play_OX_3D(const std::vector<std::vector<int>> &moves) const {
    std::vector<std::vector<std::vector<char>>> board(4, std::vector<std::vector<char>>(4, std::vector<char>(4, 'e')));
    int move_counter = 0;
    char current_player = 'O';
    std::string return_string = "No winner";

    for (const auto &move : moves) {
        board[move[2]][move[1]][move[0]] = current_player;
        ++move_counter;

        if (is_game_over(board, move, current_player)) {
            if (current_player == 'O') {
                return_string = "O wins after " + std::to_string(move_counter) + " moves";
            } else {
                return_string = "X wins after " + std::to_string(move_counter) + " moves";
            }

            return return_string;
        }

        if (current_player == 'O') {
            current_player = 'X';
        } else {
            current_player = 'O';
        }
    }

    return return_string;
}

bool CodeWars::is_game_over(const std::vector<std::vector<std::vector<char>>> &board,
        const std::vector<int> &last_move, const char &current_player) const {
    int in_a_row = 0;
    int selected_x = last_move[0];
    int selected_y = last_move[1];
    int selected_z = last_move[2];

    for (size_t i = 0; i < 4; ++i) {
        if (board[selected_z][selected_y][i] == current_player) {
            ++in_a_row;
        } else {
            break;
        }
    }

    if (in_a_row == 4) {
        return true;
    } else {
        in_a_row = 0;
    }

    for (size_t i = 0; i < 4; ++i) {
        if (board[selected_z][i][selected_x] == current_player) {
            ++in_a_row;
        } else {
            break;
        }
    }

    if (in_a_row == 4) {
        return true;
    } else {
        in_a_row = 0;
    }

    for (size_t i = 0; i < 4; ++i) {
        if (board[i][i][i] == current_player) {
            ++in_a_row;
        } else {
            break;
        }
    }

    return in_a_row == 4;
}*/

std::string CodeWars::play_OX_3D(const std::vector<std::vector<int>> &moves) const {
    std::vector<std::vector<std::vector<char>>> board(4, std::vector<std::vector<char>>(4, std::vector<char>(4, 'e')));
    int move_counter = 0;
    char current_player = 'O';
    std::string return_string = "No winner";

    for (const auto &move : moves) {
        std::cout << "{" << move[0] << ", " << move[1] << ", " << move[2] << "}," << std::endl;

        board[move[2]][move[1]][move[0]] = current_player;
        ++move_counter;

        if (move_counter >= 4) {
            int in_a_row_xydl= 0;
            int in_a_row_xydr = 0;
            int in_a_row_x = 0;
            int in_a_row_y = 0;
            int in_a_row_zd = 0;
            int in_a_row_zc = 0;
            int in_a_row_zr = 0;
            int selected_x = move[0];
            int selected_y = move[1];
            int selected_z = move[2];
            bool game_over = false;

            if (selected_x == 1 && selected_y == 1 && selected_z == 2) {

            }

            for (size_t i = 0; i < 4; ++i) {
                if (board[selected_z][i][i] == current_player) {
                    ++in_a_row_xydl;
                }

                if (board[selected_z][i][3 - i] == current_player) {
                    ++in_a_row_xydr;
                }

                if (board[selected_z][selected_y][i] == current_player) {
                    ++in_a_row_x;
                }

                if (board[selected_z][i][selected_x] == current_player) {
                    ++in_a_row_y;
                }

                if (board[i][i][i] == current_player) {
                    ++in_a_row_zd;
                }

                if (board[i][i][selected_x] == current_player) {
                    ++in_a_row_zc;
                }

                if (selected_x == 0 && selected_y == 0 && selected_z == 0) {

                }

                if (board[i][selected_y][i] == current_player) {
                    ++in_a_row_zr;
                }

                if (in_a_row_x == 4 || in_a_row_y == 4 || in_a_row_zd == 4 || in_a_row_zc == 4 ||
                in_a_row_zr == 4 || in_a_row_xydl == 4 || in_a_row_xydr == 4) {
                    game_over = true;
                    break;
                }
            }

            if (game_over) {
                if (current_player == 'O') {
                    return_string = "O wins after " + std::to_string(move_counter) + " moves";
                } else {
                    return_string = "X wins after " + std::to_string(move_counter) + " moves";
                }

                for (const auto a : board) {
                    for (const auto b : a) {
                        for (const auto c : b) {
                            std::cout << c << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "---------------------" << std::endl;
                }

                return return_string;
            }
        }

        if (current_player == 'O') {
            current_player = 'X';
        } else {
            current_player = 'O';
        }
    }

    for (const auto a : board) {
        for (const auto b : a) {
            for (const auto c : b) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------" << std::endl;
    }

    return return_string;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Connect Four---
Take a look at wiki description of Connect Four game:

Wiki Connect Four

The grid is 6 row by 7 columns, those being named from A to G.

You will receive a list of strings showing the order of the pieces which dropped in columns:

std::vector<std::string> pieces_position_list
{
  "A_Red",
  "B_Yellow",
  "A_Red",
  "B_Yellow",
  "A_Red",
  "B_Yellow",
  "G_Red",
  "B_Yellow"
}
The list may contain up to 42 moves and shows the order the players are playing.

The first player who connects four items of the same color is the winner.

You should return "Yellow", "Red" or "Draw" accordingly.
 */

//WRONG CODE / FIRST ATTEMPT
/*std::string CodeWars::who_is_winner(const std::vector<std::string> &pieces_position_list) const {
    std::string result = "Draw";
    std::map<char, std::vector<char>> board = {{'A', {}}, {'B', {}}, {'C', {}}, {'D', {}}, {'E', {}}, {'F', {}},
                                                      {'G', {}}};
    int move_counter = 0;

    for (const auto move : pieces_position_list) {
        char column = move[0];
        char color = move[2];

        board[column].push_back(color);
        ++move_counter;

        if (move_counter >= 8) {
            int vertical_count = 0;
            int horizontal_count = 0;
            int diagonal_count = 0;
            int height = board[column].size();

            if (height >= 4) {
                for (size_t i = 0; i < height; ++i) {
                    if (board[column][i] == color) {
                        ++vertical_count;
                    } else {
                        if (i >= 3) {
                            break;
                        }

                        vertical_count = 0;
                    }
                }

                if (vertical_count >= 4) {
                    result = color == 'Y' ? "Yellow" : "Red";
                    //return result;
                }
            }

            for (size_t i = 0; i < 7; ++i) {
                char column_to_check = 'A' + i;

                if (board[column_to_check].size() < height) {
                    break;
                }

                if (board[column_to_check][height - 1] == color) {
                    ++horizontal_count;
                } else {
                    if (i >= 4) {
                        break;
                    }

                    horizontal_count = 0;
                }
            }

            if (horizontal_count >= 4) {
                result = color == 'Y' ? "Yellow" : "Red";
                //return result;
            }
        }
    }

    // Prints Board in wrong direction :D
    for (const auto &pair : board) {
        for (const auto &piece : pair.second) {
            std::cout << piece << " ";
        }
        std::cout << std::endl;
    }

    return result;
}*/

// ----------------------------------------------------------------------------------------------------------

/*
---Battleship Field Validator---
Write a method that takes a field for well-known board game "Battleship" as an argument and returns true if it has a
valid disposition of ships, false otherwise. Argument is guaranteed to be 10*10 two-dimension array. Elements in the
array are numbers, 0 if the cell is free and 1 if occupied by ship.

Battleship (also Battleships or Sea Battle) is a guessing game for two players. Each player has a 10x10 grid containing
several "ships" and objective is to destroy enemy's forces by targetting individual cells on his field. The ship
occupies one or more cells in the grid. Size and number of ships may differ from version to version. In this kata we
will use Soviet/Russian version of the game.


Before the game begins, players set up the board and place the ships accordingly to the following rules:
There must be single battleship (size of 4 cells), 2 cruisers (size 3), 3 destroyers (size 2) and 4 submarines (size 1).
Any additional ships are not allowed, as well as missing ships.
Each ship must be a straight line, except for submarines, which are just single cell.

The ship cannot overlap or be in contact with any other ship, neither by edge nor by corner.

This is all you need to solve this kata. If you're interested in more information about the game, visit this link.

 {
            {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1}}


 */

bool CodeWars::validate_battlefield(const std::vector<std::vector<int>> &field) const {
    std::map<int, int> ship_count = {{4, 1}, {3, 2}, {2, 3}, {1, 4}};
    std::map<int, int> in_row_column_map = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0},
                                            {9, 0}};

    for (int r = 0; r < field.size(); ++r) {
        int in_horizontal_row_counter = 0;

        for (int c = 0; c < field[r].size(); ++c) {
            if (field[r][c] == 1) {
                if (r > 0) {
                    if (in_row_column_map[c] > 0 && in_horizontal_row_counter > 0) {
                        return false;
                    } else if (c < field[r].size() - 1 && field[r - 1][c + 1] == 1) {
                        return false;
                    } else if (in_row_column_map[c] == 0 && in_horizontal_row_counter > 0) {
                        ++in_horizontal_row_counter;
                    } else if (in_row_column_map[c] > 0 && in_horizontal_row_counter == 0) {
                        ++in_row_column_map[c];
                    } else {
                        ++in_row_column_map[c];
                        ++in_horizontal_row_counter;
                    }
                } else {
                    ++in_row_column_map[c];
                    ++in_horizontal_row_counter;
                }
            } else {
                if (in_row_column_map[c] > 0 && in_horizontal_row_counter > 0) {
                    return false;
                } else if (in_row_column_map[c] > 0) {
                    --ship_count[in_row_column_map[c]];
                    if (ship_count[in_row_column_map[c]] < 0) {
                        return false;
                    }

                    in_row_column_map[c] = 0;
                } else if (in_horizontal_row_counter > 1) {
                    --ship_count[in_horizontal_row_counter];
                    if (ship_count[in_horizontal_row_counter] < 0) {
                        return false;
                    }

                    for (int i = 1; i < in_horizontal_row_counter + 1; ++i) {
                        in_row_column_map[c - i] = 0;
                    }
                }

                in_horizontal_row_counter = 0;
            }
        }

        if (in_horizontal_row_counter > 0) {
            --ship_count[in_horizontal_row_counter];
            if (ship_count[in_horizontal_row_counter] < 0) {
                return false;
            }

            for (int i = 0; i < in_horizontal_row_counter + 1; ++i) {
                in_row_column_map[field[r].size() - 1 - i] = 0;
            }
        }

        if (r == field.size() - 1) {
            for (int i = 0; i < field[r].size(); ++i) {
                if (in_row_column_map[i] > 0) {
                    --ship_count[in_row_column_map[i]];
                    if (ship_count[in_row_column_map[i]] < 0) {
                        return false;
                    }
                }
            }
        }
    }

    for (const auto &pair : ship_count) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Sort - one, three, two---
Hey You !
Sort these integers for me ...

By name ...

Do it now !

Input
Range is 0-999

There may be duplicates

The array may be empty

Example
Input: 1, 2, 3, 4
Equivalent names: "one", "two", "three", "four"
Sorted by name: "four", "one", "three", "two"
Output: 4, 1, 3, 2
Notes
Don't pack words together:
e.g. 99 may be "ninety nine" or "ninety-nine"; but not "ninetynine"
e.g 101 may be "one hundred one" or "one hundred and one"; but not "onehundredone"
Don't fret about formatting rules, because if rules are consistently applied it has no effect anyway:
e.g. "one hundred one", "one hundred two"; is same order as "one hundred and one", "one hundred and two"
e.g. "ninety eight", "ninety nine"; is same order as "ninety-eight", "ninety-nine"
 */

std::vector<int> CodeWars::sort(const std::vector<int> &array) const {
    if (array.empty()) {
        return {};
    }

    std::vector<int> return_vector;
    std::map<int, std::string> look_up_map = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
                                              {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
                                              {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},
                                              {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
                                              {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"},
                                              {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"},
                                              {80, "eighty"}, {90, "ninety"}};
    std::map<std::string, std::vector<int>> sorted_map = {};

    for (const auto &number : array) {
        std::string number_string;

        if (number < 20 || (number % 10 == 0 && number < 100)) {
            if (number == 0) {
                number_string = "zero";
            } else {
                number_string = look_up_map[number];
            }
        } else if (number < 100 && number % 10 > 0) {
            std::string tens_place = look_up_map[number - (number % 10)];
            std::string ones_place = look_up_map[number % 10];

            number_string = tens_place + " " + ones_place;
        } else {
            std::string hundreds_place = look_up_map[floor(number / 100)] + " hundred";

            if (number - (100 * floor(number / 100)) > 20) {
                std::string tens_place = look_up_map[number - (100 * floor(number / 100)) - (number % 10)];
                std::string ones_place = look_up_map[number % 10];
                number_string = hundreds_place + " " + tens_place + " " + ones_place;
            } else {
                number_string = hundreds_place + " " + look_up_map[number - (100 * floor(number / 100))];
            }
        }

        sorted_map[number_string].push_back(number);
    }

    for (const auto &pair : sorted_map) {
        for (const auto &numb : pair.second) {
            return_vector.push_back(numb);
        }
    }

    return return_vector;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Multiplying Numbers as Strings---
This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

The arguments are passed as strings.
The numbers may be way very large
Answer should be returned as a string
The returned "number" should not start with zeros e.g. 0123 is invalid
Note: 100 randomly generated tests!
 */

std::string CodeWars::multiply(std::string &a, std::string &b) const {
    std::string grand_total;
    int zeroes = 0;

    for (int i = a.size() - 1; i >= 0; --i) {
        int number1 = a[i] - 48;

        if (number1 == 0) {
            ++zeroes;
            continue;
        }

        int carry_over = 0;
        std::vector<int> current_number(zeroes, 0);

        for (int c = b.size() - 1; c >= 0; --c) {
            int number2 = b[c] - 48;
            int result = (number1 * number2) + carry_over;

            carry_over = (result >= 10 ? floor(result / 10.0) : 0);
            result %= 10;

            current_number.push_back(result);
        }

        if (carry_over > 0) {
            current_number.push_back(carry_over);
        }

        char atd[current_number.size() + 1];
        atd[current_number.size()] = '\0';
        int counter = current_number.size() - 1;

        for (const char &digit : current_number) {
            atd[counter] = digit + 48;
            --counter;
        }

        if (grand_total.empty()) {
            for (const auto &digit : current_number) {
                grand_total = atd;
            }
        } else {
            counter = grand_total.size() - 1;
            int carry_over2 = 0;
            for (int x = current_number.size() - 1; x >= 0; --x) {
                int current = 0;
                if (grand_total[counter] > 0 && counter >= 0) {
                    current = grand_total[counter] - 48;
                }

                int new_number = current + atd[x] - 48 + carry_over2;

                carry_over2 = new_number >= 10 ? floor(new_number / 10.0) : 0;
                new_number %= 10;

                char insert = new_number + 48;

                if (counter >= 0) {
                    grand_total[counter] = insert;
                } else {
                    grand_total.insert(0, 1, insert);
                }

                --counter;
            }

            if (carry_over2 > 0) {
                char insert2 = carry_over2 + 48;
                grand_total.insert(0, 1, insert2);
            }
        }

        ++zeroes;
    }

    if (grand_total.empty()) {
        grand_total = "0";
    }

    while (grand_total[0] == '0' && grand_total.size() > 1) {
        grand_total.erase(0, 1);
    }

    return grand_total;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Integers: Recreation One---
Divisors of 42 are : 1, 2, 3, 6, 7, 14, 21, 42. These divisors squared are: 1, 4, 9, 36, 49, 196, 441, 1764. The sum of
the squared divisors is 2500 which is 50 * 50, a square!

Given two integers m, n (1 <= m <= n) we want to find all integers between m and n whose sum of squared divisors is
itself a square. 42 is such a number.

The result will be an array of arrays or of tuples (in C an array of Pair) or a string, each subarray having two
elements, first the number whose squared divisors is a square and then the sum of the squared divisors.

#Examples:

list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]
The form of the examples may change according to the language, see Example Tests: for more details.

Note

In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing
whitespace: you can use dynamically allocated character strings.
 */

std::vector<std::pair<long long, long long>> CodeWars::list_squared(const long long &m, const long long &n) const {
    std::vector<std::pair<long long, long long>> return_vector;

    for (size_t i = m; i <= n; ++i) {
        long long divisor_sum = 1 + pow(i, 2.0);

        if (i == 1) {
            return_vector.push_back({1, 1});
            continue;
        }

        for (size_t c = 2; c < (i / 2) + 1; ++c) {
            if (i % c == 0) {
                divisor_sum += pow(c, 2.0);
            }
        }

        long double sr = sqrt(divisor_sum);

        if (sr - floor(sr) == 0) {
            return_vector.push_back({i, divisor_sum});
        }
    }

    return return_vector;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Best Travel---
John and Mary want to travel between a few towns A, B, C ... Mary has on a sheet of paper a list of distances between
these towns. ls = [50, 55, 57, 58, 60]. John is tired of driving and he says to Mary that he doesn't want to drive more
than t = 174 miles and he will visit only 3 towns.

Which distances, hence which towns, they will choose so that the sum of the distances is the biggest possible to please
Mary and John?

Example:

With list ls and 3 towns to visit they can make a choice between: [50,55,57],[50,55,58],[50,55,60],[50,57,58],
[50,57,60],[50,58,60],[55,57,58],[55,57,60],[55,58,60],[57,58,60].

The sums of distances are then: 162, 163, 165, 165, 167, 168, 170, 172, 173, 175.

The biggest possible sum taking a limit of 174 into account is then 173 and the distances of the 3 corresponding towns
is [55, 58, 60].

The function chooseBestSum (or choose_best_sum or ... depending on the language) will take as parameters t (maximum sum
of distances, integer >= 0), k (number of towns to visit, k >= 1) and ls (list of distances, all distances are positive
or null integers and this list has at least one element). The function returns the "best" sum ie the biggest possible
sum of k distances less than or equal to the given limit t, if that sum exists, or otherwise nil, null, None, Nothing,
depending on the language. With C++, C, Rust, Swift, Go, Kotlin return -1.

Examples:

ts = [50, 55, 56, 57, 58] choose_best_sum(163, 3, ts) -> 163

xs = [50] choose_best_sum(163, 3, xs) -> nil (or null or ... or -1 (C++, C, Rust, Swift, Go)

ys = [91, 74, 73, 85, 73, 81, 87] choose_best_sum(230, 3, ys) -> 228

 -- need to rety sometime --
 */

int CodeWars::choose_best_sum(const int &t, const int &k, std::vector<int> &ls) const {


    return -1;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Get the Middle Character---
You are going to be given a word. Your job is to return the middle character of the word. If the word's length is odd,
 return the middle character. If the word's length is even, return the middle 2 characters.

#Examples:

Kata.getMiddle("test") should return "es"

Kata.getMiddle("testing") should return "t"

Kata.getMiddle("middle") should return "dd"

Kata.getMiddle("A") should return "A"
#Input

A word (string) of length 0 < str < 1000 (In javascript you may get slightly more than 1000 in some test cases due to
 an error in the test cases). You do not need to test for this. This is only here to tell you that you do not need to
 worry about your solution timing out.

#Output

The middle character(s) of the word represented as a string.
 */

std::string CodeWars::get_middle(const std::string &input) const {
    std::stringstream return_stream;

    bool is_even = input.size() % 2 == 0;
    int middle = floor(input.size() / 2.0);

    if (!is_even) {
        return_stream << input[middle];
    } else {
        return_stream << input[middle - 1] << input[middle];
    }

    return return_stream.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---The Supermarket Queue---
There is a queue for the self-checkout tills at the supermarket. Your task is write a function to calculate the total
time required for all the customers to check out!

input
customers: an array of positive integers representing the queue. Each integer represents a customer, and its value is
the amount of time they require to check out.
n: a positive integer, the number of checkout tills.
output
The function should return an integer, the total time required.

Important
Please look at the examples and clarifications below, to ensure you understand the task correctly :)

Examples
queueTime(std::vector<int>{5,3,4}, 1)
// should return 12
// because when n=1, the total time is just the sum of the times

queueTime(std::vector<int>{10,2,3,3}, 2)
// should return 10
// because here n=2 and the 2nd, 3rd, and 4th people in the
// queue finish before the 1st person has finished.

queueTime(std::vector<int>{2,3,10}, 2)
// should return 12
Clarifications
There is only ONE queue serving many tills, and
The order of the queue NEVER changes, and
The front person in the queue (i.e. the first element in the array/list) proceeds to a till as soon as it becomes free.
N.B. You should assume that all the test input will be valid, as specified above.

P.S. The situation in this kata can be likened to the more-computer-science-related idea of a thread pool, with
relation to running multiple processes at the same time: https://en.wikipedia.org/wiki/Thread_pool
 */

long CodeWars::queue_time(std::vector<int> customers, int n) const {
    if (customers.empty()) {
        return 0;
    }

    std::reverse(customers.begin(), customers.end());

    int total_time = 0;
    std::map<int, int> registers_map;

    for (size_t i = 1; i < n + 1; ++i) {
        registers_map[i] = 0;
    }

    while (true) {
        bool leave_loop = true;

        for (auto &register_pair : registers_map) {
            if (register_pair.second == 0 && customers.size() > 0) {
                register_pair.second = customers.back();
                customers.pop_back();
                leave_loop = false;
            } else if (register_pair.second > 0) {
                --register_pair.second;
                leave_loop = false;

                if (register_pair.second == 0 && customers.size() > 0) {
                    register_pair.second = customers.back();
                    customers.pop_back();
                }
            }
        }

        if (!leave_loop) {
            leave_loop = true;

            for (const auto &register_pair : registers_map) {
                if (register_pair.second > 0) {
                    leave_loop = false;
                    break;
                }
            }
        }

        if (leave_loop) {
            break;
        }

        ++total_time;
    }

    return total_time;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Permutations---
In this kata you have to create all permutations of an input string and remove duplicates, if present. This means,
you have to shuffle all letters from the input in all possible orders.

Examples:

permutations("a"); // => vector<string> {"a"}
permutations("ab"); // => vector<string> {"ab", "ba"}
permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}
 */

std::vector<std::string> CodeWars::permutations(std::string &s) const {
    std::vector<std::string> return_vec;

    std::sort(s.begin(), s.end());

    do {
        return_vec.emplace_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    return return_vec;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Human Readable Duration Format---
Your task in order to complete this Kata is to write a function which formats a duration, given as a number of seconds,
in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is
expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

format_duration(62)    // returns "1 minute and 2 seconds"
format_duration(3662)  // returns "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules
The resulting expression is made of components like 4 seconds, 1 year, etc. In general, a positive integer and one of
the valid units of time, separated by a space. The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). Except the last component, which is separated by " and ",
just like it would be written in English.

A more significant units of time will occur before than a least significant one. Therefore, 1 second and 1 year is not
correct, but 1 year and 1 second is.

Different components have different unit of times. So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0 seconds is not valid, but it
should be just 1 minute.

A unit of time must be used "as much as possible". It means that the function should not return 61 seconds, but 1 minute
and 1 second instead. Formally, the duration specified by of a component must not be greater than any valid more
significant unit of time.
 */

std::string CodeWars::format_duration(int seconds) const {
    if (seconds == 0) {
        return "now";
    }

    std::stringstream ss;
    std::map<std::string, int> format_map = {{"year", 0}, {"day", 0}, {"hour", 0}, {"minute", 0}, {"second", 0}};
    std::vector<std::string> keys = {"year", "day", "hour", "minute", "second"};

    if (seconds >= 31536000) {
        format_map["year"] = floor(seconds / 31536000.0);
        seconds %= 31536000;
    }

    if (seconds >= 86400) {
        format_map["day"] = floor(seconds / 86400.0);
        seconds %= 86400;
    }

    if (seconds >= 3600) {
        format_map["hour"] = floor(seconds / 3600.0);
        seconds %= 3600;
    }

    if (seconds >= 60) {
        format_map["minute"] = floor(seconds / 60.0);
        seconds %= 60;
    }

    if (seconds > 0) {
        format_map["second"] = seconds;
    }

    for (size_t i = 0; i < keys.size(); ++i) {
        if (format_map[keys[i]] == 0) {
            keys.erase(keys.begin() + i);
            i -= 1;
        }
    }

    if (keys.size() == 1) {
        if (format_map[keys[0]] == 1) {
            ss << format_map[keys[0]] << " " << keys[0];
        } else {
            ss << format_map[keys[0]] << " " << keys[0] + 's';
        }
    } else if (keys.size() == 2) {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (i == 1) {
                ss << " and ";
            }

            if (format_map[keys[i]] == 1) {
                ss << format_map[keys[i]] << " " << keys[i];
            } else {
                ss << format_map[keys[i]] << " " << keys[i] + 's';
            }
        }
    } else {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (i == keys.size() - 1) {
                if (format_map[keys[i]] == 1) {
                    ss << "and " << format_map[keys[i]] << " " << keys[i];
                } else {
                    ss << "and " << format_map[keys[i]] << " " << keys[i] + 's';
                }
            } else if (i == keys.size() - 2) {
                if (format_map[keys[i]] == 1) {
                    ss << format_map[keys[i]] << " " << keys[i] << " ";
                } else {
                    ss << format_map[keys[i]] << " " << keys[i] + 's' << " ";
                }
            } else if (format_map[keys[i]] == 1) {
                ss << format_map[keys[i]] << " " << keys[i] << ", ";
            } else {
                ss << format_map[keys[i]] << " " << keys[i] + 's' << ", ";
            }
        }
    }

    return ss.str();
}

// ----------------------------------------------------------------------------------------------------------

/*
---Infix to Postfix Converter---
Construct a function that, when given a string containing an expression in infix notation, will return an identical
expression in postfix notation.

The operators used will be +, -, *, /, and ^ with standard precedence rules and left-associativity of all operators
but ^.

The operands will be single-digit integers between 0 and 9, inclusive.

Parentheses may be included in the input, and are guaranteed to be in correct pairs.

to_postfix("2+7*5") // Should return "275*+"
to_postfix("3*3/(7+1)") // Should return "33*71+/"
to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
You may read more about postfix notation, also called Reverse Polish notation, here:
http://en.wikipedia.org/wiki/Reverse_Polish_notation
 */

std::string CodeWars::to_postfix(const std::string &infix) const {
    std::map<char, int> precedence_map = {{'^', 4}, {'*', 3}, {'/', 3}, {'+', 2}, {'-', 2}};
    std::vector<char> operators = {'*', '+', '-', '^', '/'};
    std::vector<char> output_queue;
    std::vector<char> operator_stack;

    for (const auto &token : infix) {
        if (std::isdigit(token)) {
            output_queue.push_back(token);
        } else if (std::find(operators.cbegin(), operators.cend(), token) != operators.cend()) {
            while (!operator_stack.empty() && ((precedence_map[operator_stack.back()] > precedence_map[token])
            || (precedence_map[operator_stack.back()] == precedence_map[token])) && (token != '(')) {
                output_queue.push_back(operator_stack.back());
                operator_stack.pop_back();
            }
            operator_stack.push_back(token);
        } else if (token == '(') {
            operator_stack.push_back(token);
        } else if (token == ')') {
            while (operator_stack.back() != '(') {
                output_queue.push_back(operator_stack.back());
                operator_stack.pop_back();
            }
            if (operator_stack.back() == '(') {
                operator_stack.pop_back();
            }
        }
    }

    while (!operator_stack.empty()) {
        output_queue.push_back(operator_stack.back());
        operator_stack.pop_back();
    }

    std::string postfix_expression(output_queue.begin(), output_queue.end());

    return postfix_expression;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Third Angle of a Triangle---
You are given two angles (in degrees) of a triangle.

Write a function to return the 3rd.

Note: only positive integers will be tested.
 */

int CodeWars::other_angle(const int &a, const int &b) const {
    return 180 - a - b;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Block Sequence---
Consider the following array:

[1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 12345678910, 1234567891011...]
If we join these blocks of numbers, we come up with an infinite sequence which starts with 112123123412345123456....
The list is infinite.

You will be given an number (n) and your task will be to return the element at that index in the sequence, where
1 ≤ n ≤ 10^18. Assume the indexes start with 1, not 0. For example:

solve(1) = 1, because the first character in the sequence is 1. There is no index 0.
solve(2) = 1, because the second character is also 1.
solve(3) = 2, because the third character is 2.
More examples in the test cases. Good luck!
 */

int CodeWars::solve(const long &n) const {
    std::stringstream ss;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t a = 1; a <= i; ++a) {
            ss << a;
        }
    }

    char return_char = ss.str()[n - 1];

    return (int)ss.str()[n - 1] - 48;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Count by X---
Create a function with two arguments that will return an array of the first (n) multiples of (x).

Assume both the given number and the number of times to count will be positive numbers greater than 0.

Return the results as an array (or list in Python, Haskell or Elixir).

Examples:

countBy(1,10)  should return  {1,2,3,4,5,6,7,8,9,10}
countBy(2,5)  should return {2,4,6,8,10}
 */

std::vector<int> CodeWars::count_by(const int &x, const int &n) const {
    std::vector<int> return_vector;

    for (size_t i = 1; i <= n; ++i) {
        return_vector.push_back(i * x);
    }

    return return_vector;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Disease Spread---
In 1978 the British Medical Journal reported on an outbreak of influenza at a British boarding school. There were 1000
students. The outbreak began with one infected student.

We want to study the spread of the disease through the population of this school. The total population may be divided
into three: the infected (i), those who have recovered (r), and those who are still susceptible (s) to get the disease.

We will study the disease on a period of tm days. One model of propagation uses 3 differential equations:

(1) s'(t) = -b * s(t) * i(t)
(2) i'(t) =  b * s(t) * i(t) - a * i(t)
(3) r'(t) =  a * i(t)
where s(t), i(t), r(t) are the susceptible, infected, recovered at time t and s'(t), i'(t), r'(t) the corresponding
derivatives. b and a are constants: b is representing a number of contacts which can spread the disease and a is a fraction of the infected that will recover.

We can transform equations (1), (2), (3) in finite differences (https://en.wikipedia.org/wiki/Finite_difference_method
#Example:_ordinary_differential_equation) (http://www.codewars.com/kata/56347fcfd086de8f11000014)

(I)    S[k+1] = S[k] - dt * b * S[k] * I[k]
(II)   I[k+1] = I[k] + dt * (b * S[k] * I[k] - a * I[k])
(III)  R[k+1] = R[k] + dt * I[k] *a
The interval [0, tm] will be divided in n small intervals of length dt = tm/n. Initial conditions here could be :
S0 = 999, I0 = 1, R0 = 0 Whatever S0 and I0, R0 (number of recovered at time 0) is always 0.

The function epidemic will return the maximum number of infected as an integer (truncate to integer the result of
max(I)).

Example:
tm = 14 ;n = 336 ;s0 = 996 ;i0 = 2 ;b = 0.00206 ;a = 0.41
epidemic(tm, n, s0, i0, b, a) --> 483
Notes:
You will pass the tests if abs(actual - expected) <= 1

Keeping track of the values of susceptible, infected and recovered you can plot the solutions of the 3 differential
equations.

susceptible = previousSusceptible - interval * numberOfContacts * previousSusceptible * previousInfected;
infected = previousInfected + interval * numberOfContacts * previousSusceptible * previousInfected - fractionOfRecover
                * previousInfected;
recovered = previousRecovered + interval * fractionOfRecover * previousInfected;
 */

int CodeWars::epidemic(int tm, int n, int s0, int i0, double b, double a) const {
    int max_sick = 0;
    double susceptible = s0;
    double infected = i0;
    double recovered = 0;

    double previous_susceptible, previous_infected, previous_recovered;

    for (int i = 0; i < n; ++i) {
        previous_susceptible = susceptible;
        previous_infected = infected;
        previous_recovered = recovered;

        susceptible = previous_susceptible - (double(tm) / n) * b * previous_susceptible * previous_infected;
        infected = previous_infected + (double(tm) / n) * (b * previous_susceptible * previous_infected -
                                                           a * previous_infected);
        recovered = previous_recovered + (double(tm) / n) * previous_infected * a;

        if (infected > max_sick) {
            max_sick = infected;
        }
    }

    return max_sick;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Sorted? yes? no? how?---
Description:
Complete the method which accepts an array of integers, and returns one of the following:

"yes, ascending" - if the numbers in the array are sorted in an ascending order
"yes, descending" - if the numbers in the array are sorted in a descending order
"no" - otherwise
You can assume the array will always be valid, and there will always be one correct answer.
 */

std::string CodeWars::is_sorted_and_how(const std::vector<int> array) const {
    int return_int = (array[0] < array[1] ? 1 : 0);
    bool first_run = true;
    int previous_value;

    for (const auto &value : array) {
        if (first_run) {
            first_run = false;
            previous_value = value;
            continue;
        }

        if ((return_int && previous_value > value) || (!return_int && previous_value < value)) {
            return "no";
        }
    }

    return (return_int ? "yes, ascending" : "yes, descending");
}

// ----------------------------------------------------------------------------------------------------------

/*
---Find the Next Perfect Square!---
You might know some pretty large perfect squares. But what about the NEXT one?

Complete the findNextSquare method that finds the next integral perfect square after the one passed as a parameter. Recall that an integral perfect square is an integer n such that sqrt(n) is also an integer.

If the parameter is itself not a perfect square then -1 should be returned. You may assume the parameter is positive.

Examples:

findNextSquare(121) --> returns 144
findNextSquare(625) --> returns 676
findNextSquare(114) --> returns -1 since 114 is not a perfect
 */

long int CodeWars::find_next_square(long int sq) const {
    if (sqrt(sq) - floor(sqrt(sq)) > 0) {
        return -1;
    } else {
        return pow(sqrt(sq) + 1, 2);
    }
}

// ----------------------------------------------------------------------------------------------------------

/*
---Operating System Scheduling: FCFS---
CPU scheduling is a process which allows one process to use the CPU while the execution of another process is on
hold(or in waiting state) due to unavailability of any resource like I/O etc, thereby making full use of CPU. The
 aim of CPU scheduling is to make the system efficient, fast and fair.read more about scheduling in operating system

Non-Preemptive Scheduling:
Under non-preemptive scheduling, once the CPU has been allocated to a process, the process keeps the CPU until it
releases the CPU either by terminating or by switching to the waiting state.
Preemptive Scheduling
In this type of Scheduling, the tasks are usually assigned with priorities. At times it is necessary to run a certain
task that has a higher priority before another task although it is running. Therefore, the running task is interrupted
for some time and resumed later when the priority task has finished its execution.
Scheduling Algorithms
To decide which process to execute first and which process to execute last to achieve maximum CPU utilisation, you
will implement these algorithms in follow-up series, they are
First Come First Serve(FCFS) Scheduling (current kata)
Shortest-Job-First(SJF) Scheduling (Non Pre-emptive)
Shortest-Job-First(SJF) Scheduling (Pre-emptive)
Priority Scheduling (Non Pre-emptive)
Priority Scheduling (Pre-emptive)
Round Robin(RR) Scheduling
Multilevel Queue Scheduling
Multilevel Feedback Queue Scheduling
Task: First Come First Serve(FCFS) Scheduling
Input:
Implement a function fcfs with given processes processes(array) which consist of arrival time and burst time as single
row for each process and given processes will be sorted by arrival time.(i.e [Arrival time, Burst time]). (No two
processes will have the same arrival time)
Terms:
As the name suggests, the process which arrives first, gets executed first, or we can say that the process which
requests the CPU first, gets the CPU allocated first. (just like FIFO if you will)

Arrival time : Point of time at which process enters into ready queue (or ram).
Burst Time : Time duration required by process to get executed on CPU.
Completion Time : Point of time at which process completes it's execution.
Response Time : RT = Time at which the CPU starts the execution of the process - Arrival Time
Turn Around Time : total time taken by process to get executed (including waiting time and all), formula : TAT =
Completion TIme - Arrival Time
Waitng Time : WT = Turn Around Time (total time) - Burst Time(useful time)
Throughput : Throughput means the efficiency of the scheduling algo that is the average "useful time" (time where the
CPU is actually used) per process.
Note: for the current task, RT and WT are actually the very same value.

General Steps:
CPU locates very first process arrived in ready queue and start executing it and complete it;s execution depending upon
Burst time of that process and if there;s no process arrived in ready queue then CPU have to wait until next process
arrives in ready queue. (NOTE: note various timing to get expected output (see example below))
Start again for next process in ready queue.
Output:
Return Average Completion Time, Average Turn Around Time, Average Waiting Time and Throughput in tuple (A-CT, A-TAT,
A-WT, Throughput) all rounded to two decimal places.
 */

std::tuple<double, double, double, double> CodeWars::fcfs(const std::vector<std::pair<int, int>> &processes) const {
    double avg_completion_time = 0.0;
    double avg_turnaround_time = 0.0;
    double avg_waiting_time = 0.0;
    double throughput_time = 0.0;

    std::map<int, std::vector<int>> scheduler;
    int time_clock = 0;

    for (const auto &process : processes) {
        if (time_clock < process.first) {
            time_clock += process.first - time_clock;
        }

        scheduler[process.first] = {time_clock, time_clock + process.second, process.second};

        time_clock += process.second;
    }

    for (const auto &pair : scheduler) {
        avg_completion_time += pair.second[1];
        avg_turnaround_time += pair.second[1] - pair.first;
        avg_waiting_time += pair.second[1] - pair.first - pair.second[2];
        throughput_time += pair.second[2];
    }

    avg_completion_time /= scheduler.size();
    avg_turnaround_time /= scheduler.size();
    avg_waiting_time /= scheduler.size();
    throughput_time /= scheduler.size();

    return std::make_tuple(
        ceil(avg_completion_time * 100) / 100,
        ceil(avg_turnaround_time * 100) / 100,
        ceil(avg_waiting_time * 100) / 100,
        ceil(throughput_time * 100) / 100
    );
}

// ----------------------------------------------------------------------------------------------------------

/*
---Consonant Value---
Given a lowercase string that has alphabetic characters only and no spaces, return the highest value of consonant
substrings. Consonants are any letters of the alphabet except "aeiou".

We shall assign the following values: a = 1, b = 2, c = 3, .... z = 26.

For example, for the word "zodiacs", let's cross out the vowels. We get: "z o d ia cs"

-- The consonant substrings are: "z", "d" and "cs" and the values are z = 26, d = 4 and cs = 3 + 19 = 22. The highest
is 26.
solve("zodiacs") = 26

For the word "strength", solve("strength") = 57
-- The consonant substrings are: "str" and "ngth" with values "str" = 19 + 20 + 18 = 57 and "ngth" = 14 + 7 + 20 + 8
= 49. The highest is 57.
 */

int CodeWars::solve2(const std::string &s) const {
    std::regex vowels_regex("[aeiou]");
    int highest_sum = 0;
    int segment_sum = 0;

    for (const auto &letter : s) {
        if (!std::regex_search(std::string(1, letter), vowels_regex)) {
            segment_sum += letter - 96;
        } else {
            highest_sum = (segment_sum > highest_sum ? segment_sum : highest_sum);
            segment_sum = 0;
        }
    }

    return (segment_sum > highest_sum ? segment_sum : highest_sum);
}

// ----------------------------------------------------------------------------------------------------------

/*
---Palindrome Integer Composition---
The palindromic number 595 is interesting because it can be written as the sum of consecutive squares: 6^2 + 7^2 +
8^2 + 9^2 + 10^2 + 11^2 + 12^2 = 595.

There are exactly eleven palindromes below one-thousand that can be written as consecutive square sums. Note that 1 =
0^2 + 1^2 has not been included as this problem is concerned with the squares of positive integers.

Given an input n, find the count of all the numbers less than n that are both palindromic and can be written as the sum
of consecutive squares.

For instance: values(1000) = 11. See test examples for more cases.

Good luck!
 */

int CodeWars::values(const int &n) const {
    std::vector<int> squared_palindromes;
    int sqrt_n = sqrt(n);

    for (size_t i = 1; i <= sqrt_n; ++i) {
        int inner_sum = pow(i, 2);

        for (size_t a = i + 1; a <= sqrt_n; ++a) {
            inner_sum += pow(a, 2);

            int inner_sum_copy = inner_sum;
            int reverse_inner_sum = 0;

            while (inner_sum_copy > 0) {
                reverse_inner_sum = reverse_inner_sum * 10 + inner_sum_copy % 10;
                inner_sum_copy /= 10;
            }

            if (inner_sum > n) {
                break;
            } else if (inner_sum == reverse_inner_sum) {
                if (std::find(squared_palindromes.cbegin(), squared_palindromes.cend(), inner_sum)
                    == squared_palindromes.cend()) {
                    squared_palindromes.push_back(inner_sum);
                }
            }
        }
    }

    return squared_palindromes.size();
}

//Slow
/*int CodeWars::values(const int &n) const {
    int counter = 0;

    for (size_t i = 5; i <= n; ++i) {
        if (i >= 10) {
            int rev_i = 0;
            int i_copy = i;

            while (i_copy > 0) {
                rev_i = rev_i * 10 + i_copy % 10;
                i_copy /= 10;
            }

            if (rev_i != i) {
                continue;
            }
        }

        int sqrt_i = sqrt(i);
        bool break_full = false;

        for (size_t r = 1; r <= sqrt_i; ++r) {
            int inner_sum = pow(r, 2);

            for (size_t k = r + 1; k <= sqrt_i; ++k) {
                inner_sum += pow(k, 2);

                if (inner_sum > i) {
                    break;
                } else if (inner_sum == i) {
                    ++counter;
                    break_full = true;
                    break;
                }
            }

            if (break_full) {
                break;
            }
        }
    }

    return counter;
}*/

// ----------------------------------------------------------------------------------------------------------

/*
---Snail---
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling
clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in
a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
 */

std::vector<int> CodeWars::snail(const std::vector<std::vector<int>> &snail_map) const {
    if (snail_map.empty()) {
        return {};
    } else if (snail_map.size() == 1) {
        return snail_map[0];
    }

    std::vector<int> snail_path;
    int start_column = 0;
    int end_column = snail_map.size() - 1;
    int start_row = 0;
    int end_row = snail_map.size() - 1;

    while (start_column <= end_column && start_row <= end_row) {
        for (int i = start_column; i <= end_column; ++i) {
            snail_path.push_back(snail_map[start_row][i]);
        }

        ++start_row;

        for (int i = start_row; i <= end_row; ++i) {
            snail_path.push_back(snail_map[i][end_column]);
        }

        --end_column;

        for (int i = end_column; i >= start_column; --i) {
            snail_path.push_back(snail_map[end_row][i]);
        }

        --end_row;

        for (int i = end_row; i >= start_row; --i) {
            snail_path.push_back(snail_map[i][start_column]);
        }

        ++start_column;
    }

    return snail_path;
}

// ----------------------------------------------------------------------------------------------------------

/*
---Scheduling Round Robin---
Scheduling is how the processor decides which jobs (processes) get to use the processor and for how long. This can
cause a lot of problems. Like a really long process taking the entire CPU and freezing all the other processes. One
solution is Round-Robin, which today you will be implementing.

Round-Robin works by queuing jobs in a First In First Out fashion, but the processes are only given a short slice of
time. If a processes is not finished in that time slice, it yields the proccessor and goes to the back of the queue.

For this Kata you will be implementing the

   function roundRobin(jobs, slice, index)
It takes in:

1. "jobs" a non-empty positive integer array. It represents the queue and clock-cycles(cc) remaining till the job[i]
is finished.

2. "slice" a positive integer. It is the amount of clock-cycles that each job is given till the job yields to the next
job in the queue.

3. "index" a positive integer. Which is the index of the job we're interested in.
roundRobin returns:

1. the number of cc till the job at index is finished.
Here's an example:

roundRobin([10,20,1], 5, 0)
at 0cc [10,20,1] jobs[0] starts
after 5cc [5,20,1] jobs[0] yields, jobs[1] starts
after 10cc [5,15,1] jobs[1] yields, jobs[2] starts
after 11cc [5,15,0] jobs[2] finishes, jobs[0] starts
after 16cc [0,15,0] jobs[0] finishes
so:

roundRobin([10,20,1], 5, 0) == 16
**You can assume that the processor can switch jobs between cc so it does not add to the total time.
 */

int CodeWars::round_robin(std::vector<int> jobs, const int &slice, const int &index) const {
    if (jobs[index] == 0) {
        return 0;
    }

    int total_time = 0;

    for (;;) {
        for (size_t i = 0; i < jobs.size(); ++i) {
            if (jobs[i] > slice) {
                jobs[i] -= slice;
                total_time += slice;
            } else if (jobs[i] < slice) {
                total_time += jobs[i];
                jobs[i] = 0;

                if (i == index) {
                    return total_time;
                }
            } else {
                jobs[i] -= slice;
                total_time += slice;

                if (i == index) {
                    return total_time;
                }
            }
        }
    }
}

// ----------------------------------------------------------------------------------------------------------

/*
---Scheduling Shortest Job First---
Scheduling is how the processor decides which jobs(processes) get to use the processor and for how long. This can cause
a lot of problems. Like a really long process taking the entire CPU and freezing all the other processes. One solution
is Shortest Job First(SJF), which today you will be implementing.

SJF works by, well, letting the shortest jobs take the CPU first. If the jobs are the same size then it is First In
First Out (FIFO). The idea is that the shorter jobs will finish quicker, so theoretically jobs won't get frozen because
of large jobs. (In practice they're frozen because of small jobs).

You will be implementing:

  function SJF(jobs, index)
It takes in:

"jobs" a non-empty array of positive integers. They represent the clock-cycles(cc) needed to finish the job.
"index" a positive integer. That represents the job we're interested in.
SJF returns:

A positive integer representing the cc it takes to complete the job at index.
Here's an example:

SJF([3, 10, 20, 1, 2], 0)
at 0cc [3, 10, 20, 1, 2] jobs[3] starts
at 1cc [3, 10, 20, 0, 2] jobs[3] finishes, jobs[4] starts
at 3cc [3, 10, 20, 0, 0] jobs[4] finishes, jobs[0] starts
at 6cc [0, 10, 20, 0, 0] jobs[0] finishes
so:

SJF([3,10,20,1,2], 0) == 6
 */

int CodeWars::SJF(std::vector<int> jobs, int index) const {
    if (jobs[index] == 0) {
        return 0;
    }

    int total_time = 0;

    for (;;) {
        int min_job_index;
        int min_job_time = -1;

        for (size_t i = 0; i < jobs.size(); ++i) {
            if (jobs[i] < min_job_time || min_job_time == -1) {
                min_job_time = jobs[i];
                min_job_index = i;
            }
        }

        total_time += jobs[min_job_index];

        if (min_job_index == index) {
            return total_time;
        }

        jobs.erase(jobs.begin() + min_job_index);

        if (min_job_index < index) {
            --index;
        }
    }
}

// ----------------------------------------------------------------------------------------------------------

/*
---Connect Four---
Take a look at wiki description of Connect Four game:

Wiki Connect Four

The grid is 6 row by 7 columns, those being named from A to G.

You will receive a list of strings showing the order of the pieces which dropped in columns:

std::vector<std::string> pieces_position_list
{
  "A_Red",
  "B_Yellow",
  "A_Red",
  "B_Yellow",
  "A_Red",
  "B_Yellow",
  "G_Red",
  "B_Yellow"
}
The list may contain up to 42 moves and shows the order the players are playing.

The first player who connects four items of the same color is the winner.

You should return "Yellow", "Red" or "Draw" accordingly.
 */

std::string CodeWars::who_is_winner(const std::vector<std::string> &pieces_position_list) const {
    std::map<int, std::vector<char>> board {{0, {}}, {1, {}}, {2, {}}, {3, {}}, {4, {}}, {5, {}}, {6, {}}};
    std::vector<int> board_keys = {0, 1, 2, 3, 4, 5};

    for (size_t i = 0; i < pieces_position_list.size(); ++i) {
        int column = pieces_position_list[i][0] - 65;
        char color_letter = pieces_position_list[i][2];

        board[column].push_back(color_letter);

        if (i >= 7) {
            int row = board[column].size() - 1;
            int in_row = 0;

            if (board[column].size() >= 4) {
                for (const auto &value : board[column]) {
                    if (in_row == 4) {
                        return (color_letter == 'R' ? "Red" : "Yellow");
                    } else if (value == color_letter) {
                        ++in_row;
                    } else {
                        in_row = 0;
                    }
                }
            }

            if (in_row == 4) {
                return (color_letter == 'R' ? "Red" : "Yellow");
            }
            in_row = 0;

            for (const auto &section : board) {
                if (in_row == 4) {
                    return (color_letter == 'R' ? "Red" : "Yellow");
                } else if (section.second.size() <= row) {
                    in_row = 0;
                    continue;
                } else if (section.second[row] == color_letter) {
                    ++in_row;
                } else {
                    in_row = 0;
                }
            }

            if (in_row == 4) {
                return (color_letter == 'R' ? "Red" : "Yellow");
            }

            int min = (column > row ? row : column);
            int max = (6 - column > 6 - row ? 6 - row : 6 - column);

            int index_column = column - min;
            int end_column = column + max;
            int index_row = row - min;
            int end_row = row + max;

            in_row = 0;

            while (index_column <= end_column && index_row <= end_row) {
                if (in_row == 4) {
                    return (color_letter == 'R' ? "Red" : "Yellow");
                } else if (board[index_column].size() >= index_row + 1) {
                    if (board[index_column][index_row] == color_letter) {
                        ++in_row;
                    }
                } else {
                    in_row = 0;
                }

                ++index_column;
                ++index_row;
            }

            if (in_row == 4) {
                return (color_letter == 'R' ? "Red" : "Yellow");
            }

            min = (column > row ? column : row);

            end_column = (column - min < 0 ? 0 : column - min);
            index_column = column + max;
            end_row = row + max;
            index_row = (row - min < 0 ? 0 : row - min);

            in_row = 0;

            while (index_column >= end_column && index_row <= end_row) {
                if (in_row == 4) {
                    return (color_letter == 'R' ? "Red" : "Yellow");
                } else if (board[index_column].size() >= index_row + 1) {
                    if (board[index_column][index_row] == color_letter) {
                        ++in_row;
                    }
                } else {
                    in_row = 0;
                }

                --index_column;
                ++index_row;
            }


            if (in_row == 4) {
                return (color_letter == 'R' ? "Red" : "Yellow");
            }
        }
    }

    return "Draw";
}

// ----------------------------------------------------------------------------------------------------------

/*
---Crack the Pin---
Given is a md5 hash of a five digits long PIN. It is given as string. Md5 is a function to hash your password:
 "password123" ===> "482c811da5d5b4bc6d497ffa98491e38"

Why is this usefull? Hash functions like md5 can create a hash from string in a short time and it is impossible to
find out the password, if you only got the hash. The only way is cracking it, means try every combination, hash it
and compare it with the hash you want to crack. (There are also other ways of attacking md5 but that's another story)
Every Website and OS is storing their passwords as hashes, so if a hacker gets access to the database, he can do
nothing, as long the password is safe enough.

What is a hash: https://en.wikipedia.org/wiki/Hash_function#:~:text=A%20hash%20function%20is%20any,
table%20called%20a%20hash%20table.

What is md5: https://en.wikipedia.org/wiki/MD5

Note: Many languages have build in tools to hash md5. If not, you can write your own md5 function or google
for an example.

Here is another kata on generating md5 hashes: https://www.codewars.com/kata/password-hashes

Your task is to return the cracked PIN as string.

This is a little fun kata, to show you, how weak PINs are and how important a bruteforce protection is,
if you create your own login.

If you liked this kata, here is an extension: https://www.codewars.com/kata/59146f7b4670ba520900000a
 */

// a small class for calculating MD5 hashes of strings or byte arrays
// it is not meant to be fast or secure
//
// usage: 1) feed it blocks of uchars with update()
//      2) finalize()
//      3) get hexdigest() string
//      or
//      MD5(std::string).hexdigest()
//
// assumes that char is 8 bit and int is 32 bit
class MD5
{
public:
    typedef unsigned int size_type; // must be 32bit

    MD5();
    MD5(const std::string& text);
    void update(const unsigned char *buf, size_type length);
    void update(const char *buf, size_type length);
    MD5& finalize();
    std::string hexdigest() const;
    friend std::ostream& operator<<(std::ostream&, MD5 md5);

private:
    void init();
    typedef unsigned char uint1; //  8bit
    typedef unsigned int uint4;  // 32bit
    enum {blocksize = 64}; // VC6 won't eat a const static int here

    void transform(const uint1 block[blocksize]);
    static void decode(uint4 output[], const uint1 input[], size_type len);
    static void encode(uint1 output[], const uint4 input[], size_type len);

    bool finalized;
    uint1 buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
    uint4 count[2];   // 64bit counter for number of bits (lo, hi)
    uint4 state[4];   // digest so far
    uint1 digest[16]; // the result

    // low level logic operations
    static inline uint4 F(uint4 x, uint4 y, uint4 z);
    static inline uint4 G(uint4 x, uint4 y, uint4 z);
    static inline uint4 H(uint4 x, uint4 y, uint4 z);
    static inline uint4 I(uint4 x, uint4 y, uint4 z);
    static inline uint4 rotate_left(uint4 x, int n);
    static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};

std::string md5(std::string str);

/* system implementation headers */
#include <cstdio>


// Constants for MD5Transform routine.
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

///////////////////////////////////////////////

// F, G, H and I are basic MD5 functions.
inline MD5::uint4 MD5::F(uint4 x, uint4 y, uint4 z) {
    return x&y | ~x&z;
}

inline MD5::uint4 MD5::G(uint4 x, uint4 y, uint4 z) {
    return x&z | y&~z;
}

inline MD5::uint4 MD5::H(uint4 x, uint4 y, uint4 z) {
    return x^y^z;
}

inline MD5::uint4 MD5::I(uint4 x, uint4 y, uint4 z) {
    return y ^ (x | ~z);
}

// rotate_left rotates x left n bits.
inline MD5::uint4 MD5::rotate_left(uint4 x, int n) {
    return (x << n) | (x >> (32-n));
}

// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
// Rotation is separate from addition to prevent recomputation.
inline void MD5::FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
    a = rotate_left(a+ F(b,c,d) + x + ac, s) + b;
}

inline void MD5::GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
    a = rotate_left(a + G(b,c,d) + x + ac, s) + b;
}

inline void MD5::HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
    a = rotate_left(a + H(b,c,d) + x + ac, s) + b;
}

inline void MD5::II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
    a = rotate_left(a + I(b,c,d) + x + ac, s) + b;
}

//////////////////////////////////////////////

// default ctor, just initailize
MD5::MD5()
{
    init();
}

//////////////////////////////////////////////

// nifty shortcut ctor, compute MD5 for string and finalize it right away
MD5::MD5(const std::string &text)
{
    init();
    update(text.c_str(), text.length());
    finalize();
}

//////////////////////////////

void MD5::init()
{
    finalized=false;

    count[0] = 0;
    count[1] = 0;

    // load magic initialization constants.
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
}

//////////////////////////////

// decodes input (unsigned char) into output (uint4). Assumes len is a multiple of 4.
void MD5::decode(uint4 output[], const uint1 input[], size_type len)
{
    for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
        output[i] = ((uint4)input[j]) | (((uint4)input[j+1]) << 8) |
                    (((uint4)input[j+2]) << 16) | (((uint4)input[j+3]) << 24);
}

//////////////////////////////

// encodes input (uint4) into output (unsigned char). Assumes len is
// a multiple of 4.
void MD5::encode(uint1 output[], const uint4 input[], size_type len)
{
    for (size_type i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = input[i] & 0xff;
        output[j+1] = (input[i] >> 8) & 0xff;
        output[j+2] = (input[i] >> 16) & 0xff;
        output[j+3] = (input[i] >> 24) & 0xff;
    }
}

//////////////////////////////

// apply MD5 algo on a block
void MD5::transform(const uint1 block[blocksize])
{
    uint4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    decode (x, block, blocksize);

    /* Round 1 */
    FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
    FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
    FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
    FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
    FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
    FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
    FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
    FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
    FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
    FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
    FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
    FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
    FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
    FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
    FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
    FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
    GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
    GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
    GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
    GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
    GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
    GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
    GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
    GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
    GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
    GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
    GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
    GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
    GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
    GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
    GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
    HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
    HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
    HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
    HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
    HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
    HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
    HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
    HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
    HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
    HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
    HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
    HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
    HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
    HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
    HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
    II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
    II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
    II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
    II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
    II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
    II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
    II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
    II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
    II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
    II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
    II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
    II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
    II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
    II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
    II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;

    // Zeroize sensitive information.
    memset(x, 0, sizeof x);
}

//////////////////////////////

// MD5 block update operation. Continues an MD5 message-digest
// operation, processing another message block
void MD5::update(const unsigned char input[], size_type length)
{
    // compute number of bytes mod 64
    size_type index = count[0] / 8 % blocksize;

    // Update number of bits
    if ((count[0] += (length << 3)) < (length << 3))
        count[1]++;
    count[1] += (length >> 29);

    // number of bytes we need to fill in buffer
    size_type firstpart = 64 - index;

    size_type i;

    // transform as many times as possible.
    if (length >= firstpart)
    {
        // fill buffer first, transform
        memcpy(&buffer[index], input, firstpart);
        transform(buffer);

        // transform chunks of blocksize (64 bytes)
        for (i = firstpart; i + blocksize <= length; i += blocksize)
            transform(&input[i]);

        index = 0;
    }
    else
        i = 0;

    // buffer remaining input
    memcpy(&buffer[index], &input[i], length-i);
}

//////////////////////////////

// for convenience provide a verson with signed char
void MD5::update(const char input[], size_type length)
{
    update((const unsigned char*)input, length);
}

//////////////////////////////

// MD5 finalization. Ends an MD5 message-digest operation, writing the
// the message digest and zeroizing the context.
MD5& MD5::finalize()
{
    static unsigned char padding[64] = {
            0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    if (!finalized) {
        // Save number of bits
        unsigned char bits[8];
        encode(bits, count, 8);

        // pad out to 56 mod 64.
        size_type index = count[0] / 8 % 64;
        size_type padLen = (index < 56) ? (56 - index) : (120 - index);
        update(padding, padLen);

        // Append length (before padding)
        update(bits, 8);

        // Store state in digest
        encode(digest, state, 16);

        // Zeroize sensitive information.
        memset(buffer, 0, sizeof buffer);
        memset(count, 0, sizeof count);

        finalized=true;
    }

    return *this;
}

//////////////////////////////

// return hex representation of digest as string
std::string MD5::hexdigest() const
{
    if (!finalized)
        return "";

    char buf[33];
    for (int i=0; i<16; i++)
        sprintf(buf+i*2, "%02x", digest[i]);
    buf[32]=0;

    return std::string(buf);
}

//////////////////////////////

std::ostream& operator<<(std::ostream& out, MD5 md5)
{
    return out << md5.hexdigest();
}

//////////////////////////////

std::string md5(const std::string str)
{
    MD5 md5 = MD5(str);

    return md5.hexdigest();
}


std::string CodeWars::crack(const std::string &hash) const {
    std::vector<char> pin_numbers = {'0', '1', '2', '3', '4', '5', '6', '7' , '8', '9',
                                     '0', '1', '2', '3', '4', '5', '6', '7' , '8', '9',
                                     '0', '1', '2', '3', '4', '5', '6', '7' , '8', '9',
                                     '0', '1', '2', '3', '4', '5', '6', '7' , '8', '9',
                                     '0', '1', '2', '3', '4', '5', '6', '7' , '8', '9'};
    std::vector<bool> bitset(pin_numbers.size() - 5, 0);
    bitset.resize(pin_numbers.size(), 1);

    do {
        std::string generated_pin = "";
        for (size_t i = 0; i != pin_numbers.size(); ++i) {
            if (bitset[i]) {
                generated_pin += pin_numbers[i];
            }
        }

        if (md5(generated_pin) == hash) {
            return generated_pin;
        }

    } while (std::next_permutation(bitset.begin(), bitset.end()));

    return "NO MATCH FOUND ADJUST ALGORITHM";
}

// ----------------------------------------------------------------------------------------------------------

/*
---Alphabet War---
There is a war and nobody knows - the alphabet war! There are two groups of hostile letters. The tension between left
side letters and right side letters was too high and the war began.

Task
Write a function that accepts fight string consists of only small letters and return who wins the fight. When the
left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's
fight again!.

The left side letters and their power:

 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3
 d - 2
 z - 1
The other letters don't have power and are only victims.

Example
AlphabetWar("z");        //=> Right side wins!
AlphabetWar("zdqmwpbs"); //=> Let's fight again!
AlphabetWar("zzzzs");    //=> Right side wins!
AlphabetWar("wwwwwwz");  //=> Left side wins!
 */

std::string CodeWars::alphabetWar(const std::string &fight) const {
    std::map<char, int> left_letter_strengths = {{'w', 4}, {'p', 3}, {'b', 2}, {'s', 1}};
    std::map<char, int> right_letter_strengths = {{'m', 4}, {'q', 3}, {'d', 2}, {'z', 1}};

    int score = 0;

    for (const auto &character : fight) {
        if (left_letter_strengths.find(character) != left_letter_strengths.cend()) {
            score += left_letter_strengths[character];
        } else if (right_letter_strengths.find(character) != right_letter_strengths.cend()) {
            score -= right_letter_strengths[character];
        }
    }

    return (score == 0 ? "Let's fight again!" : score > 0 ? "Left side wins!" : "Right side wins!");
}