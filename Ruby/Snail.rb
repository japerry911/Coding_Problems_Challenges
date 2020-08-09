"""
Snail
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, 
traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse 
the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
"""

def snail(array)
  if array[0].empty? then
    return []
  end  
  
  return_array = []

  start_column = 0
  start_row = 0
  last_column = array.length() - 1
  last_row = array.length() - 1

  while start_row <= last_row && start_column <= last_column do 
    for i in start_column..last_column do
      return_array.append(array[start_row][i])
    end
    start_row += 1

    for i in start_row..last_row do
      return_array.append(array[i][last_column])
    end
    last_column -= 1

    for i in (start_column..last_column).to_a.reverse do 
      return_array.append(array[last_row][i])
    end
    last_row -= 1

    for i in (start_row..last_row).to_a.reverse do
      return_array.append(array[i][start_column])
    end
    start_column += 1
  end

  return_array
end

puts snail([[1,2,3],[4,5,6],[7,8,9]])
puts snail([[]])