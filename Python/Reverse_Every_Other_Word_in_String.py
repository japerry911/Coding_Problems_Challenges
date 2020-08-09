"""
Reverse every other word in a given string, then return the string. 
Throw away any leading or trailing whitespace, while ensuring there is exactly one space between each word. 
Punctuation marks should be treated as if they are apart of the word in this kata.
"""

import re

def reverse_alternate(string):
  # Check if the string input is whitespace only, if yes, return ''
  space_only_regex = re.compile('^\s+$')
  if space_only_regex.match(string):
    return ''

  # Declare variables and create string split which is array with no white space elements
  counter = 0
  string_split = list(filter(lambda x: x != '', string.split(' ')))
  return_string = list()
  
  # While loop through the string split array and create return_string variable
  while counter < len(string_split):
      if counter % 2 == 0:
          return_string.append(string_split[counter])
      else:
          return_string.append(string_split[counter][::-1])
      
      counter += 1
  
  # Return return_string array converted to string with a space divider
  return ' '.join(return_string)