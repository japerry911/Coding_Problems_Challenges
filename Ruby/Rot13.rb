"""
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 'implementation'.
"""

def rot13(string)
  # Alphabet array that is used in cypher conversion
  alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i",
              "j", "k", "l", "m", "n", "o", "p", "q", "r",
              "s", "t", "u", "v", "w", "x", "y", "z"]
  
  counter = 0
  return_string = ""
  
  # Loop through the string with while loop
  while counter < string.length do
    # Check that the string char is a letter and not a symbol, if symbol add to string and skip
    if Regexp.new("[A-Za-z]").match?(string[counter])
      letter_index = alphabet.index(string[counter].downcase)
    else
      return_string += string[counter]
      counter += 1
      next
    end
    
    # Add 13 character spots to the letter_index of current char (cypher translation component)
    new_index = letter_index + 13
    
    # If it's over 25, it's gone over the alphabet length and needs to be reset
    if new_index > 25
      new_index -= 26
    end
  
    # Check if it's lowercase, otherwise makes it uppercase
    if alphabet.index(string[counter]) == nil 
      return_string += alphabet[new_index].upcase
    else
      return_string += alphabet[new_index]
    end
    
    counter += 1
  end
  
  # Return translated string
  return_string
end