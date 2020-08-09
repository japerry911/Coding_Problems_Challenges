"""
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

Please note that using encode is considered cheating.
"""

def rot13(message):
    # Initialize an empty encoded_string variable
    encoded_string = ''
    
    # Loop through the message-to-encode by character
    for character in message:    
        # Check if character is alphabet letter, if it is do the proper encodings
        if character.isalpha():
            # Greater than 97 means that this character is lowercase
            if ord(character) >= 97:
                new_character = chr(ord(character) + 13 if ord(character) + 13 <= 122 else ord(character) + 13 - 123 + 97)
            else:
                new_character = chr(ord(character) + 13 if ord(character) + 13 <= 90 else ord(character) + 13 - 91 + 65)
            
            encoded_string += new_character
        # Else if it is not alphabet letter, then just add it how it is to the encoded_string
        else:
            encoded_string += character
    
    # Return encoded_string variable
    return encoded_string
