"""
In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

Example:

high_and_low('1 2 3 4 5')  # return '5 1'
high_and_low('1 2 -3 4 5') # return '5 -3'
high_and_low('1 9 3 4 -5') # return '9 -5'
Notes:

All numbers are valid Int32, no need to validate them.
There will always be at least one number in the input string.
Output string must be two numbers separated by a single space, and highest number is first.
"""

def high_and_low(numbers)
  # Create an array of all of the string numbers (convert to integers once made into array w/ map)
  array = numbers.split(" ").map {|number| number.to_i}
  
  # Find max / min number
  max = array.max
  min = array.min
  
  # Return a string interopulation of "max min"
  "#{max} #{min}"
end