"""
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).

Examples
to_camel_case('the-stealth-warrior') # returns 'theStealthWarrior'

to_camel_case('The_Stealth_Warrior') # returns 'TheStealthWarrior'
"""

def to_camel_case(str)
  # Replace all of the hyphens with underscores, and then split on underscores
  str_array = str.gsub("-", "_").split("_")
  
  return_string = ""
  counter = 0 
  
  # loop through with the str_array split array with when statement
  while counter < str_array.length do 
    # if it's the first word check if the first letter is going to be capitalized or all lowercase
    if counter == 0
      if str_array[counter][0] == str_array[counter][0].upcase
        return_string += str_array[counter].capitalize
      else
        return_string += str_array[counter].downcase
      end
    else
      # if not first word, just make it camelcase capitalize style
      return_string += str_array[counter].capitalize
    end
    
    counter += 1
  end
    
  return_string
end