"""
A Narcissistic Number is a number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits):

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1634 (4 digits):

    1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256 = 1634
The Challenge:

Your code must return true or false depending upon whether the given number is a Narcissistic number in base 10.

Error checking for text strings or other invalid inputs is not required, only valid integers will be passed into the function.
"""

def narcissistic?(value)
  # Get digits length
  digits = value.to_s.length
  
  sum = 0
  counter = 0 
  
  # Loop through the digit as a string and convert to int and add to a sum holder
  while counter < digits do 
    sum += (value.to_s[counter].to_i**digits)
    counter += 1
  end
    
  # Return true or false based on if sum == value
  sum == value 
end