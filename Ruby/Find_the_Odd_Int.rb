"""
Given an array, find the integer that appears an odd number of times.
There will always be only one integer that appears an odd number of times.
"""

def find_it(seq)  
    # Creates a hash that counts has a key of the input array value, and a value of the occurrences
    count_hash = seq.reduce(Hash.new(0)) do |hsh, v|
      hsh[v] += 1
      hsh
    end
    
    # Finds the first and only odd number occurring element with modulus % 2 == 1
    count_hash.find {|hsh, v| v % 2 == 1}[0]
  end