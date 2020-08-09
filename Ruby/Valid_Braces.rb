"""
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.
"""

def validBraces(braces)
  counter = 0 
  ending_array = []
  beginning_chars = ['(', '{', '[']

  p braces
  while counter < braces.length do
    if beginning_chars.include?(braces[counter])
      if braces[counter] == '('
        ending_array.prepend(')')
      elsif braces[counter] == '['
        ending_array.prepend(']')
      else
        ending_array.prepend('}')
      end
    else
      if ending_array[0] != braces[counter]
        return false
      else
        ending_array.shift
      end
    end
    
    counter += 1
  end
  
  ending_array.length == 0
end