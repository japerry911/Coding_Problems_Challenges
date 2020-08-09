"""
Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

Example:
createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) # => returns "(123) 456-7890"
The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses!
"""

def createPhoneNumber(numbers)
  # Return String
  return_string = ""
  
  counter = 0
  
  # Forms Phone Number
  while counter < numbers.length do
    case counter
    when 0
      return_string += "(#{numbers[counter]}"
    when 2
      return_string += "#{numbers[counter]}) "
    when 6 
      return_string += "-#{numbers[counter]}"
    else
      return_string += "#{numbers[counter]}"
    end
    
    counter += 1
  end
  
  # Return return_string
  return_string
end