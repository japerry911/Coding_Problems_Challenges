"""
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23. 
Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
Note: If the number is a multiple of both 3 and 5, only count it once.
"""

def solution(number)
    # First: create an array with 0...number loop (excluding 0 and number)
    # Second: Select/Filter out anything that has a modulus over 0 for % 5/% 2
    # Third: Reduce the new selected array values down to one single sum
    # Fourth: Return that sum
    (0...number).select {|num| num % 3 == 0 || num % 5 == 0}.reduce(0) {|sum, num| sum + num}
  end