"""
Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements with the same value next to each other and preserving the original order of elements.

For example:

unique_in_order('AAAABBBCCDAABBB') == ['A', 'B', 'C', 'D', 'A', 'B']
unique_in_order('ABBCcAD')         == ['A', 'B', 'C', 'c', 'A', 'D']
unique_in_order([1,2,2,3,3])       == [1,2,3]
"""

def unique_in_order(iterable):
    # If input iterable is empty, return empty list
    if len(iterable) == 0:
        return []

    # Declare previous element as index 0 value, and set the return list as list with it in it
    previous_element = iterable[0]
    return_list = [previous_element]
    
    # Set first_run to True and pop_it to False, which are used in the for loop
    first_run = True
    pop_it = True
    
    # For loop used to generate return_list
    for element in iterable:
        # If it's the first_run, skip since we already took element 0 out already
        if first_run:
            first_run = False
            continue
        
        # If the element equals the previous element, then:
        # - check if the ending element in return_list is popable, and pop it if so
        # else: set the previous element as the new new element, and add it to the return_list
        # also reset pop_it to True
        if element == previous_element:
            if pop_it:
                return_list.pop
                pop_it = False    
            continue
        else:
            previous_element = element
            return_list.append(element)
            pop_it = True
            
    return return_list