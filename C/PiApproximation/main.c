#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
---Pi Approximation---
The aim of the kata is to try to show how difficult it can be to calculate decimals of an irrational number with a
certain precision. We have chosen to get a few decimals of the number "pi" using the following infinite series
(Leibniz 1646–1716):

PI / 4 = 1 - 1/3 + 1/5 - 1/7 + ... which gives an approximation of PI / 4.

http://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80

To have a measure of the difficulty we will count how many iterations are needed to calculate PI with a given precision.

There are several ways to determine the precision of the calculus but to keep things easy we will calculate to
within epsilon of your language Math::PI constant. In other words we will stop the iterative process when the absolute
value of the difference between our calculation and the Math::PI constant of the given language is less than epsilon.

Your function returns an array or an arrayList or a string or a tuple depending on the language (See sample tests)
where your approximation of PI has 10 decimals

In Haskell you can use the function "trunc10Dble" (see "Your solution"); in Clojure you can use the function "round"
(see "Your solution");in OCaml or Rust the function "rnd10" (see "Your solution") in order to avoid discussions about
the result.

Example :

your function calculates 1000 iterations and 3.140592653839794 but returns:
iter_pi(0.001) --> [1000, 3.1405926538]
Unfortunately, this series converges too slowly to be useful, as it takes over 300 terms to obtain a 2 decimal place
precision. To obtain 100 decimal places of PI, it was calculated that one would need to use at least 10^50 terms of
this expansion!

About PI : http://www.geom.uiuc.edu/~huberty/math5337/groupe/expresspi.html
 */

char *iter_pi(double epsilon);

int main() {
    double input1 = 0.1;
    double input2 = 0.01;
    double input3 = 0.001;
    double input4 = 0.0001;

    char *output1 = iter_pi(input1);
    char *output2 = iter_pi(input2);
    char *output3 = iter_pi(input3);
    char *output4 = iter_pi(input4);

    char *expected_output1 = "[10, 3.0418396189]";
    char *expected_output2 = "[100, 3.1315929036]";
    char *expected_output3 = "[1000, 3.1405926538]";
    char *expected_output4 = "[10000, 3.1414926536]";
    
    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed. Output = %s || Expected_Output = %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed. Output = %s || Expected_Output = %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    if (strcmp(output3, expected_output3) != 0) {
        printf("Test 3 Failed. Output = %s || Expected_Output = %s\n", output3, expected_output3);
    } else {
        printf("Test 3 Passed.\n");
    }

    if (strcmp(output4, expected_output4) != 0) {
        printf("Test 4 Failed. Output = %s || Expected_Output = %s\n", output4, expected_output4);
    } else {
        printf("Test 4 Passed.\n");
    }

    return 0;
}

char *iter_pi(double epsilon) {
    double total = 1.0;
    double distance_from = (total * 4) - M_PI;
    int counter = 1;
    char *return_string = malloc(20 * sizeof(char));

    while (fabs(distance_from) > epsilon) {
        double top = pow(-1.0, counter);
        double bottom = (2.0 * counter) + 1.0;
        double add_to_total = top / bottom;

        total += add_to_total;

        distance_from = (total * 4) - M_PI;
        ++counter;
    }

    sprintf(return_string, "[%d, %.10f]%c", counter, total * 4.0, '\0');

    return return_string;
}