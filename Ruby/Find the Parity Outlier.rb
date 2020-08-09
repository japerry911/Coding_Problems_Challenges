"""
You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
"""

def find_outlier(integers)
  # Check first three indices for their modulus 2 value
  value1_modulus = integers[0] % 2
  value2_modulus = integers[1] % 2
  value3_modulus = integers[2] % 2
  
  # Create a hash to show how many odds and evens are in the first three elements
  occurrences_hash = {1 => 0, 0 => 0}
  occurrences_hash[value1_modulus] += 1
  occurrences_hash[value2_modulus] += 1
  occurrences_hash[value3_modulus] += 1
  
  # Determine if the array is predominately odd or even
  odd = occurrences_hash[1] > 1 ? true : false
  
  # Loop through the integers array and return the odd one out (or even one out)
  integers.each do |integer|
    if odd
      if integer % 2 == 0
        return integer
      end
    else
      if integer % 2 == 1
        return integer
      end
    end
  end
end