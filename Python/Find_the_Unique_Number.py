"""
There is an array with some numbers. All numbers are equal except for one. Try to find it!

find_uniq([ 1, 1, 1, 2, 1, 1 ]) == 2
find_uniq([ 0, 0, 0.55, 0, 0 ]) == 0.55
It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.
"""

def find_uniq(arr):
    # Make the input list unique
    integers = list(set(arr))
    
    # Filter out all instances in input array for each number in unique array
    integer1_times = list(filter(lambda x: x == integers[0], arr))
    integer2_times = list(filter(lambda x: x == integers[1], arr))
    
    # return the correct unique number 
    return integer1_times[0] if len(integer1_times) < len(integer2_times) else integer2_times[0]