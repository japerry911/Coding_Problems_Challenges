"""
Write Number in Expanded Form
You will be given a number and you will need to return it as a string in Expanded Form. For example:

expanded_form(12); # Should return '10 + 2'
expanded_form(42); # Should return '40 + 2'
expanded_form(70304); # Should return '70000 + 300 + 4'
NOTE: All numbers will be whole numbers greater than 0.
"""

# Turn the input num into an array where each element is each digit
# Loop through the new array in a map and times the element by whatever ever 10 ** raise_by equals
# raise_by => This is the number of zeroes to add to the digit
# Lastly, compact out the nils and join with a plus sign and return the string
def expanded_form(num)
  num_split = num.to_s.split("")
  raise_by = num.to_s.length - 1
  
  num_split.map do |element| 
    adjusted_num = element.to_i * (10 ** raise_by)
    raise_by -= 1
    adjusted_num unless adjusted_num == 0
  end.compact.join(" + ")
end