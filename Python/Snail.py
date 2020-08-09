"""
---Snail---
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
"""

def snail(snail_map):
    if len(snail_map) == 0:
        return []
    elif len(snail_map) == 1:
        return snail_map[0]

    return_list = list()

    start_row = 0
    end_row = len(snail_map) - 1
    start_column = 0
    end_column = end_row

    while start_row <= end_row and start_column <= end_column:
        for i in range(start_column, end_column + 1):
            return_list.append(snail_map[start_row][i])
        start_row += 1

        for i in range(start_row, end_row + 1):
            return_list.append(snail_map[i][end_column])
        end_column -= 1

        for i in range(end_column, start_column - 1, -1):
            return_list.append(snail_map[end_row][i])
        end_row -= 1

        for i in range(end_row, start_row - 1, -1):
            return_list.append(snail_map[i][start_column])
        start_column += 1

    return return_list