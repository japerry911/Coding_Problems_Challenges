"""
#Find the missing letter

Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.

You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at least 2.
The array will always contain letters in only one case.

Example:

['a','b','c','d','f'] -> 'e' ['O','Q','R','S'] -> 'P'

['a','b','c','d','f'] -> 'e'
['O','Q','R','S'] -> 'P'
(Use the English alphabet with 26 letters!)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have also created other katas. Take a look if you enjoyed this kata!
"""

def find_missing_letter(arr)
  # Declaring lowercase alphabet
  alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
              "n", "o", "p", "q" , "r", "s", "t", "u", "v", "w", "x", "y", "z"]

  # Counter for while loop and loop_index to see where in alphabet array starts at
  counter = 0
  loop_index = alphabet.find_index(arr[0].downcase)

  # Loop through the array pattern of letters
  # If the letter (downcased) doesn't match the current alpahbet loop_index, it returns the missing letter
  #   otherwise it keeps looping forward
  #   keeps track of case 
  while counter < arr.length do

  if arr[counter].downcase == alphabet[loop_index]
      loop_index += 1
    else 
      if alphabet.find_index(arr[counter])
        upper_case = false
      else 
        upper_case = true
      end
    
      return upper_case ? alphabet[loop_index].upcase : alphabet[loop_index]
    end
    
    counter += 1
  end
  
  upper_case ? alphabet[counter - 1].upcase : alphabet[counter - 1]
end