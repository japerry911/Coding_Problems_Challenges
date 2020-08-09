"""
Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

For example:

 persistence(39) => 3  # Because 3*9 = 27, 2*7 = 14, 1*4=4
                       # and 4 has only one digit.

 persistence(999) => 4 # Because 9*9*9 = 729, 7*2*9 = 126,
                       # 1*2*6 = 12, and finally 1*2 = 2.

 persistence(4) => 0   # Because 4 is already a one-digit number.
 persistence(39) # returns 3, because 3*9=27, 2*7=14, 1*4=4
                 # and 4 has only one digit

 persistence(999) # returns 4, because 9*9*9=729, 7*2*9=126,
                  # 1*2*6=12, and finally 1*2=2

 persistence(4) # returns 0, because 4 is already a one-digit number
 """

from functools import reduce

def persistence(n):
    # Converting input to a list of digits (string elements)
    list_value = list(str(n))
    
    # If the length of the digit list is 1, then it's already a single digit, so return 0
    if len(list_value) == 1:
        return 0

    # Declare counter to 0, which is used in the while to calculate the iterations it
    # takes to get a single digit as result
    counter = 0
    while True:
        # Reduce (multiply each digit by each other) to result value
        # Increment counter
        result = reduce(lambda x, y: int(x) * int(y), list_value)
        counter += 1        
        
        # If the result is 1 length as string, return the counter
        if len(str(result)) == 1:
            return counter
        
        # Update the list_value variable 
        list_value = list(str(result))