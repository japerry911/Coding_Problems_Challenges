"""
Write a function

triple_double(num1, num2)
which takes numbers num1 and num2 and returns 1 if there is a straight triple of a number at any place in num1 and also a straight double of the same number in num2.

If this isn't the case, return 0

Examples
triple_double(451999277, 41177722899) == 1
# num1 has straight triple 999s and num2 has straight double 99s

triple_double(1222345, 12345) == 0
# num1 has straight triple 2s but num2 has only a single 2

triple_double(12345, 12345) == 0

triple_double(666789, 12345667) == 1
"""

def triple_double(num1, num2):
    # Declaring variables, and setting previous_value and counter at index 1
    triple = None
    previous_value = str(num1)[0]
    counter = 1
    first_run = True
    
    # Loop through the num1, skip the first digit
    for i in str(num1):
        if first_run:
            first_run = False
            continue
        
        # Look for triple repeated digits, and break after
        if i == previous_value:
            counter += 1
        else:
            previous_value = i
            counter = 1
        
        if counter == 3:
            triple = str(i)[0]
            break
            
    # If triple is not found, return 0
    if triple is None:
        return 0
    
    # Declare variables for double digit lookthrough in num2
    double = None
    previous_value = str(num2)[0]
    first_run = True
    
    # Loop through num2 
    for i in str(num2):
        if first_run:
            first_run = False
            continue
        
        # Check if the digit is repeated twice and the same one as the triple digit loop
        if i == previous_value and str(i) == triple:
            double = str(i)[0]
            break
        else:
            previous_value = i
    
    # If double is not found, return 0
    if double is None:
        return 0

    # Return 1 if the triple & double digit match, otherwise return 0
    return 1 if triple == double else 0
        