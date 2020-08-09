"""
Build Tower
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Python: return a list;
JavaScript: returns an Array;
C#: returns a string[];
PHP: returns an array;
C++: returns a vector<string>;
Haskell: returns a [String];
Ruby: returns an Array;
Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ', 
  ' *** ', 
  '*****'
]
and a tower of 6 floors looks like below

[
  '     *     ', 
  '    ***    ', 
  '   *****   ', 
  '  *******  ', 
  ' ********* ', 
  '***********'
]
"""

def towerBuilder(n_floors)
  # Declaring Variables to use
  return_array = []
  max_asteriks = (n_floors * 2) - 1
  start_spot = (max_asteriks + 1) / 2
  end_spot = start_spot
  counter = 0
  
  # Loop through the floors and creating them
  while counter < max_asteriks
    sub_array = Array.new(max_asteriks, " ")
    sub_counter = start_spot - 1
    
    while sub_counter < end_spot
      sub_array[sub_counter] = "*"
      sub_counter += 1
    end
    
    start_spot -= 1
    end_spot += 1
    counter += 2
    
    return_array << sub_array.join("")
  end

  return return_array
end