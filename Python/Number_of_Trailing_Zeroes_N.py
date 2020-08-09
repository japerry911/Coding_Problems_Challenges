"""
Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 * ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros
Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.
"""

def zeros(n):
    # Initialize total_zeroes (return value) and five to 5
    total_zeroes = 0
    five = 5
    
    # While loop through the powers of 5 and don't stop loop until n can't be divided by
    # powers of five anymore
    # increase count of total zeroies by the input n by the current power of 5
    while n / five >= 1:
        total_zeroes += int(n / five)
        five *= 5
    
    # Return the count of total zeroes
    return total_zeroes