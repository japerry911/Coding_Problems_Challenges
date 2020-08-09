"""
What is an anagram? Well, two words are anagrams of each other if they both contain the same letters. For example:

'abba' & 'baab' == true

'abba' & 'bbaa' == true

'abba' & 'abbba' == false

'abba' & 'abca' == false
Write a function that will find all the anagrams of a word from a list. You will be given two inputs a word and an array with words. You should return an array of all the anagrams or an empty array if there are none. For example:

anagrams('abba', ['aabb', 'abcd', 'bbaa', 'dada']) => ['aabb', 'bbaa']

anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']) => ['carer', 'racer']

anagrams('laser', ['lazing', 'lazy',  'lacer']) => []
"""

def anagrams(word, words):
    # Initalize a dictionary to hold letters and occurrences of input word
    master_dict = dict()
    for i in word:
        if i not in master_dict.keys():
            master_dict[i] = 1
        else:
            master_dict[i] += 1
    
    return_list = list()
    
    # Loop throug heach words input word and check if it's valid return
    # if it is, it appends to return_list
    for check_word in words:
        temp_dict = master_dict.copy()
        break_early = False
    
        # If the word input length and check_word length aren't equal, then it is impossible
        # to match, so continue through loop
        if len(word) != len(check_word):
            continue
        # If word is exact match then add it to return_list and continue
        elif word == check_word:
            return_list.append(check_word)
            continue
        
        # Loop through each character in check_word and check if it is valid with the copied
        # master_dict
        for i in check_word:
            if i not in temp_dict.keys():
                break_early = True
                break
            
            temp_dict[i] -= 1
            
            if temp_dict[i] < 0:
                break_early = True
                break

        if break_early is False:
            return_list.append(check_word)
            
    return return_list