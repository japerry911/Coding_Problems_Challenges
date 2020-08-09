"""
In this kata, you will write a function that returns the positions and the values of the "peaks" (or local maxima) of a numeric array.

For example, the array arr = [0, 1, 2, 5, 1, 0] has a peak at position 3 with a value of 5 (since arr[3] equals 5).

The output will be returned as an object with two properties: pos and peaks. Both of these properties should be arrays. If there is no peak in the given array, then the output should be {pos: [], peaks: []}.

Example: pickPeaks([3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3]) should return {pos: [3, 7], peaks: [6, 3]} (or equivalent in other languages)

All input arrays will be valid integer arrays (although it could still be empty), so you won't need to validate the input.

The first and last elements of the array will not be considered as peaks (in the context of a mathematical function, we don't know what is after and before and therefore, we don't know if it is a peak or not).

Also, beware of plateaus !!! [1, 2, 2, 2, 1] has a peak while [1, 2, 2, 2, 3] does not. In case of a plateau-peak, please only return the position and value of the beginning of the plateau. For example: pickPeaks([1, 2, 2, 2, 1]) returns {pos: [1], peaks: [2]} (or equivalent in other languages)

Have fun!
"""

def pick_peaks(arr)
  # delaring variables
  pos = []
  peaks = []
  counter = 1
  previous_value = arr[0]
  first_run = true
  valid_peak = true
  potential_peak = false
  potential_index = 0
  
  # Loop through array with while loop  
  while counter < arr.length do
    # If first run, make sure that it has increased once before adding anything to pos/peaks
    if first_run
      if arr[counter] < previous_value
        previous_value = arr[counter]
        counter += 1
        next
      else 
        first_run = false
      end
    end
  
    if valid_peak && arr[counter] < previous_value
      valid_peak = false
      
      if !potential_peak
        pos << counter - 1
        peaks << arr[counter - 1]
      else
        pos << potential_index
        peaks << arr[potential_index]
        potential_peak = false
      end
    elsif arr[counter] > previous_value
      valid_peak = true
      potential_peak = false
    elsif arr[counter] == previous_value
      if !potential_peak
        potential_index = counter - 1
      end
    
      potential_peak = true
    end
    
    previous_value = arr[counter]
  
    counter += 1
  end
  
  {"pos" => pos, "peaks" => peaks}
end