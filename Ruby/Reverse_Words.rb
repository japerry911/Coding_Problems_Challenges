"""
Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

Examples
'This is an example!' ==> 'sihT si na !elpmaxe'
'double  spaces'      ==> 'elbuod  secaps'
"""

def reverse_words(str)
  # Split the string on a single whitespace
  # used regex since a manual space overwrote 2+ spaces
  # once converted to array, map through and transform each word element
  # to a reversed word, and then join the transformed array by a space
  str.split(/\s/).map {|word| word.reverse}.join(" ")
end