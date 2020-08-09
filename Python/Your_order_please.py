"""
Your task is to sort a given string. Each word in the string will contain a single number. This number is the position the word should have in the result.

Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

If the input string is empty, return an empty string. The words in the input String will only contain valid consecutive numbers.

Examples
"is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
"4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
""  -->  ""
"""

import re

def order(sentence):
    # If sentence is blank, return blank string
    if len(sentence) == 0:
        return ''
    
    # Create a sorted_list (returning variable) variable that is empty list set to correct size
    sorted_list = [None] * len(sentence.split(' '))
    
    # Loop through the splitted (' ') sentence (converted to list), and resort it
    # with the help of basic regex
    for word in sentence.split(' '):
        position = re.search('.*([0-9]).*', word).group(1)
        sorted_list[int(position) - 1] = word
    
    # Return the sorted_list list with elements joined by a space
    return ' '.join(sorted_list)