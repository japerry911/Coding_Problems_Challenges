"""
The idea for this Kata came from 9gag today.here

You'll have to translate a string to Pilot's alphabet (NATO phonetic alphabet) wiki.

Like this:

** Input: ** If you can read

** Output: ** India Foxtrot Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta

** Some notes **

Keep the punctuation, and remove the spaces.
Use Xray without dash or space.
"""

def to_nato(words):
    # Declaring return variable & split the words input string into a list (split by space)
    return_element = list()
    words_split = words.split(' ')
    
    # Loop through the words_split list and then loop through each character and make the translation
    for word in words_split:
        for character in word:
            if character.upper() in nato_alphabet().keys():
                return_element.append(nato_alphabet()[character.upper()])
            else:
                return_element.append(character)
            
    # Join the return list into a string separated by spaces
    return ' '.join(return_element)

# The whole nato pilot alphabet in a function definition that is returned as a dictionary
def nato_alphabet():
    return {
        'A': 'Alfa',
        'B': 'Bravo',
        'C': 'Charlie',
        'D': 'Delta',
        'E': 'Echo',
        'F': 'Foxtrot',
        'G': 'Golf',
        'H': 'Hotel',
        'I': 'India',
        'J': 'Juliett',
        'K': 'Kilo',
        'L': 'Lima',
        'M': 'Mike',
        'N': 'November',
        'O': 'Oscar',
        'P': 'Papa',
        'Q': 'Quebec',
        'R': 'Romeo',
        'S': 'Sierra',
        'T': 'Tango',
        'U': 'Uniform',
        'V': 'Victor',
        'W': 'Whiskey',
        'X': 'Xray',
        'Y': 'Yankee',
        'Z': 'Zulu'
    }