#include <stdio.h>
#include <stdbool.h>

/*
---Are the Numbers in Order?---
In this Kata, your function receives an array of integers as input. Your task is to determine whether the numbers are
in ascending order. An array is said to be in ascending order if there are no two adjacent integers where the left
integer exceeds the right integer in value.

For the purposes of this Kata, you may assume that all inputs are valid, i.e. non-empty arrays containing only integers.

Note that an array of 1 integer is automatically considered to be sorted in ascending order since all (zero)
adjacent pairs of integers satisfy the condition that the left integer does not exceed the right integer in value.
An empty list is considered a degenerate case and therefore will not be tested in this Kata - feel free to raise an
Issue if you see such a list being tested.

For example:

in_asc_order({1,2,4,7,19}, 5); // returns true
in_asc_order({1,2,3,4,5}, 5); // returns true
in_asc_order({1,6,10,18,2,4,20}, 7); // returns false
in_asc_order({9,8,7,6,5,4,3,2,1}, 9); // returns false because the numbers are in DESCENDING order
N.B. If your solution passes all fixed tests but fails at the random tests, make sure you aren't mutating the input
array.
 */

bool in_asc_order(const int *arr, size_t arr_size);

int main() {
    const int arr0[] = { 1, 2, 4, 7, 19};
    const int arr1[] = { 1, 2, 3, 4, 5};
    const int arr2[] = { 1, 6, 10, 18, 2, 4, 20};
    const int arr3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};

    bool output1 = in_asc_order(arr0, 5);
    bool output2 = in_asc_order(arr1, 5);
    bool output3 = in_asc_order(arr2, 7);
    bool output4 = in_asc_order(arr3, 9);

    if (output1) {
        printf("Test #1 Passed.\n");
    } else {
        printf("Test #1 Failed.\n");
    }

    if (output2) {
        printf("Test #2 Passed.\n");
    } else {
        printf("Test #2 Failed.\n");
    }

    if (!output3) {
        printf("Test #3 Passed.\n");
    } else {
        printf("Test #3 Failed.\n");
    }

    if (!output4) {
        printf("Test #4 Passed.\n");
    } else {
        printf("Test #4 Failed.\n");
    }

    return 0;
}

bool in_asc_order(const int *arr, size_t arr_size) {
    if (arr[0] > arr[1]) {
        return false;
    }

    int previous_value = arr[1];
    for (size_t i = 2; i < arr_size; ++i) {
        if (arr[i] < previous_value) {
            return false;
        }

        previous_value = arr[i];
    }

    return true;
}