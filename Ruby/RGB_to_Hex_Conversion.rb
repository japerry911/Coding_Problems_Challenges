"""
The rgb() method is incomplete. Complete the method so that passing in RGB decimal values will result in a hexadecimal representation being returned. The valid decimal values for RGB are 0 - 255. Any (r,g,b) argument values that fall out of that range should be rounded to the closest valid value.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
"""

def rgb(r, g, b)
  # Check if over 255, or under 0
  r = r > 255 ? r = 255 : r < 0 ? r = 0 : r
  g = g > 255 ? g = 255 : g < 0 ? g = 0 : g
  b = b > 255 ? b = 255 : b < 0 ? b = 0 : b
  
  # Convert everything to hex and combine it together (make upcase also if it's a letter)
  r.to_s(16).rjust(2, "0").upcase + g.to_s(16).rjust(2, "0").upcase + b.to_s(16).rjust(2, "0").upcase
end