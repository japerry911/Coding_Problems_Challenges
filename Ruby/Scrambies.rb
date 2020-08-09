"""
Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered
Input strings s1 and s2 are null terminated.
Examples
scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False
"""

def scramble(s1,s2)
  # Split the input strings into arrays
  s1_array = s1.split("")
  s2_array = s2.split("")
  
  # Create s1_hash & s2_hash utilizing reduce
  #   - These contain the number of occurences for each letter
  s1_hash = s1_array.reduce(Hash.new(0)) do |hsh, value|
    hsh[value] += 1
    hsh
  end
  s2_hash = s2_array.reduce(Hash.new(0)) do |hsh, value|
    hsh[value] += 1
    hsh
  end
  
  # Loop through the s2_hash and see if the number of occurences for each letter is >=, otherwise return false
  s2_hash.each_pair do |key, value|
    if s1_hash[key] < value
      return false
    end
  end
  
  # Got to the end, must be valid, return true
  true
end