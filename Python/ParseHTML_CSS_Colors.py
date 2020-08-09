"""
In this kata you parse RGB colors represented by strings. The formats are primarily used in HTML and CSS. Your task is to implement a function which takes a color as a string and returns the parsed color as a map (see Examples).

Input:
The input string represents one of the following:

6-digit hexadecimal - "#RRGGBB"
e.g. "#012345", "#789abc", "#FFA077"
Each pair of digits represents a value of the channel in hexadecimal: 00 to FF
3-digit hexadecimal - "#RGB"
e.g. "#012", "#aaa", "#F5A"
Each digit represents a value 0 to F which translates to 2-digit hexadecimal: 0->00, 1->11, 2->22, and so on.
Preset color name
e.g. "red", "BLUE", "LimeGreen"
You have to use the predefined map PRESET_COLORS (JavaScript, Python, Ruby), presetColors (Java, C#, Haskell), or preset-colors (Clojure). The keys are the names of preset colors in lower-case and the values are the corresponding colors in 6-digit hexadecimal (same as 1. "#RRGGBB").
Examples:
parse_html_color('#80FFA0')   # => {'r': 128, 'g': 255, 'b': 160}
parse_html_color('#3B7')      # => {'r': 51,  'g': 187, 'b': 119}
parse_html_color('LimeGreen') # => {'r': 50,  'g': 205, 'b': 50 }
"""

def parse_html_color(color):
    # Check if we are given preset color and convert to hex if so
    if color.lower() in PRESET_COLORS.keys():
        use_value = PRESET_COLORS[color.lower()]
    else:
        use_value = color
  
    # Initialize variables
    counter = 0
    return_dict = dict()
    
    # Check if it's a short 3 hex digit number or larger and run loop accordingly
    if len(use_value) == 4:
        for i in use_value.lower():
            if counter == 1:
                return_dict['r'] = (16 * hex_to_dec_dict()[i]) + hex_to_dec_dict()[i]
            elif counter == 2:
                return_dict['g'] = (16 * hex_to_dec_dict()[i]) + hex_to_dec_dict()[i]
            elif counter == 3:
                return_dict['b'] = (16 * hex_to_dec_dict()[i]) + hex_to_dec_dict()[i]
            
            counter += 1
    
    else:
        for i in use_value.lower():
            if counter == 1:
                return_dict['r'] = 16 * hex_to_dec_dict()[i]
            elif counter == 2:
                return_dict['r'] += hex_to_dec_dict()[i]
            elif counter == 3:
                return_dict['g'] = 16 * hex_to_dec_dict()[i]
            elif counter == 4:
                return_dict['g'] += hex_to_dec_dict()[i]
            elif counter == 5:
                return_dict['b'] = 16 * hex_to_dec_dict()[i]
            elif counter == 6:
                return_dict['b'] += hex_to_dec_dict()[i]
            
            counter += 1
            
    return return_dict
    
    
# Dictionary to tell what hex value translates too decimal-wise
def hex_to_dec_dict():
    return {
        '0': 0,
        '1': 1,
        '2': 2,
        '3': 3,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 7,
        '8': 8,
        '9': 9,
        'a': 10,
        'b': 11,
        'c': 12,
        'd': 13,
        'e': 14,
        'f': 15
      }


