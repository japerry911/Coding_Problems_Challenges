"""
Complete the solution so that the function will break up camel casing, using a space between words.

Example
solution("camelCasing")  ==  "camel Casing"
"""

def solution(s):
    # Initialize empty string that will be returned at end
    return_string = ''
    
    # Loop through each character in string input s
    # look at the character's ascii value and use that to determine if it's case,
    # from there add a space to uppercase characters, and no space for lowercase
    for character in s:
        if ord(character) < 97:
            return_string += ' {}'.format(character)
        else:
            return_string += character
      
    return return_string