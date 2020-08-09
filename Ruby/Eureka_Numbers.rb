"""
The number 89 is the first integer with more than one digit that fulfills the property partially introduced in the title of this kata. What's the use of saying "Eureka"? Because this sum gives the same number.

In effect: 89 = 8^1 + 9^2

The next number in having this property is 135.

See this property again: 135 = 1^1 + 3^2 + 5^3

We need a function to collect these numbers, that may receive two integers a, b that defines the range [a, b] (inclusive) and outputs a list of the sorted numbers in the range that fulfills the property described above.

Let's see some cases:

sum_dig_pow(1, 10) == [1, 2, 3, 4, 5, 6, 7, 8, 9]

sum_dig_pow(1, 100) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 89]
If there are no numbers of this kind in the range [a, b] the function should output an empty list.

sum_dig_pow(90, 100) == []
"""

def sum_dig_pow(a, b)
  # Initialize empty array for returning 'Eureka' numbers
  return_array = []
  
  # Loop through a (including) to b (including)
  # start by spliting up the integer into array separated by digits
  # then loop through the digits and see if they form 'Eureka' number
  for i in a..b
    temp_sum = 0
    digits_array = i.to_s.split("")
    counter = 0
    
    while counter < digits_array.length do
      temp_sum += digits_array[counter].to_i ** (counter + 1)
      
      if temp_sum > i
        break
      end
      
      counter += 1
    end
    
    temp_sum == i ? return_array << i : nil    
  end
  
  return return_array
end
