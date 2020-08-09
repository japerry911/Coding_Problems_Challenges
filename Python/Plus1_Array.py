"""
Given an array of integers of any length, return an array that has 1 added to the value represented by the array.

the array can't be empty
only non-negative, single digit integers are allowed
Return nil (or your language's equivalent) for invalid inputs.

Examples
For example the array [2, 3, 9] equals 239, adding one would return the array [2, 4, 0].

[4, 3, 2, 5] would return [4, 3, 2, 6]
"""

def up_array(arr):
    # Check if list length is 0, if yes return None
    if len(arr) == 0:
        return None
    
    # Pull negative number list & double digit list, if any of the two lists are over 0
    # in length, then return None since it's invalid
    negative_list = list(filter(lambda x: x < 0, arr))
    double_digit_list = list(filter(lambda x: x >= 10, arr))

    if len(negative_list) > 0 or len(double_digit_list):
        return None
    
    # Return a incremented input list by 1, and separate as integer elements in array
    return list(map(lambda x: int(x), str(int(''.join(str(ele) for ele in arr)) + 1)))
