"""
Given: an array containing hashes of names

Return: a string formatted as a list of names separated by commas except for the last two names, which should be separated by an ampersand.

Example:

namelist([ {'name': 'Bart'}, {'name': 'Lisa'}, {'name': 'Maggie'} ])
# returns 'Bart, Lisa & Maggie'

namelist([ {'name': 'Bart'}, {'name': 'Lisa'} ])
# returns 'Bart & Lisa'

namelist([ {'name': 'Bart'} ])
# returns 'Bart'

namelist([])
# returns ''
Note: all the hashes are pre-validated and will only contain A-Z, a-z, '-' and '.'.
"""

def namelist(names):
    # If length of names input is 0, then return ''
    if len(names) == 0:
        return ''
    # If the length of names input is 1, then return the only name
    elif len(names) == 1:
        return names[0]['name']
    # If the length of names input is 2, then return the 2 names separated by & symbol
    elif len(names) == 2:
        return '{} & {}'.format(names[0]['name'], names[1]['name'])
    # Else the length > 2, then cycle through and make it name, name,..., name & name format
    else:
        return_string = ''
        
        for obj in names[0:-2]:
            return_string += '{}, '.format(obj['name'])
        
        return_string += '{} & {}'.format(names[-2]['name'], names[-1]['name'])
        
        return return_string
            