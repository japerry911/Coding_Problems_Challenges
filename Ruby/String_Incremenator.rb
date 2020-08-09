"""
Your job is to write a function which increments a string, to create a new string.

If the string already ends with a number, the number should be incremented by 1.
If the string does not end with a number. the number 1 should be appended to the new string.
Examples:

foo -> foo1

foobar23 -> foobar24

foo0042 -> foo0043

foo9 -> foo10

foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.
"""

def increment_string(input)
  if input == nil || input == ""
    return "1"
  elsif Regexp.new("^[0-9]+$").match(input)
    return (input.to_i + 1).to_s.rjust(input.length, "0")
  end
  
  regexp = Regexp.new("([A-Za-z]+)([0123456789]*)")
  if regexp.match(input)[2]
    number_input = regexp.match(input)[2]
  else
    number_input = nil
  end

  if number_input != nil && Regexp.new("[0-9]").match(input[-1])
    number = (number_input.to_i + 1).to_s.rjust(number_input.length, "0")
    return input[0...-number_input.length].concat(number)
  else
    return input.concat("1")
  end
end