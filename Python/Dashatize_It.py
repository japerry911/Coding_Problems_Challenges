"""
Given a number, return a string with dash'-'marks before and after each odd integer, but do not begin or end the string with a dash mark.

Ex:

dashatize(274) -> '2-7-4'
dashatize(6815) -> '68-1-5'
"""

def dashatize(num):
    # If num input is None, then return None
    if num is None:
        return 'None'
    
    # Set counter equal to 0, and make the num input a string, and initialize return_string
    # as blank
    counter = 0
    str_num = str(num).replace('-', '')
    return_string = ''
    
    # While loop through string version of num input and perform the Dashatize process on
    # num input
    while counter < len(str_num):
        if counter == 0 and int(str_num[counter]) % 2 == 1:
            return_string += '{}-'.format(str_num[counter])
        elif counter == len(str_num) - 1 and int(str_num[counter]) % 2 == 1:
            if return_string[-1] == '-':
                return_string += str_num[counter]
            else:
                return_string += '-{}'.format(str_num[counter])
        else:
            if int(str_num[counter]) % 2 == 1:
                if return_string[-1] == '-':
                    return_string += '{}-'.format(str_num[counter])
                else:
                    return_string += '-{}-'.format(str_num[counter])
            else:
                return_string += str_num[counter]
        
        counter += 1
      
    # Returns return_string as a whole if it doesn't end in hyphen, otherwise slash off ending
    # hyphen and return updated return_string
    return return_string[0:-1] if return_string[-1] == '-' else return_string