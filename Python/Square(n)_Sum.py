"""
Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.
"""

from functools import reduce

def square_sum(numbers):
    # Check if the numbers array is empty, if so return 0
    if len(numbers) == 0:
        return 0
    else:
        # If it's not empty, add in a 0 at the beginning so that the reduce starts at 0
        numbers.insert(0, 0)
    
    # Return the output of return (functools) where it adds each squared element to
    # the starting value of 0
    return reduce(lambda x, y: x + y**2, numbers)