"""
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.
"""

def score(dice)
  # Set total_score to 0 to start
  total_score = 0
  
  # Score_Key_Hash -> The point look up converter/translator
  score_key_hash = {
    "1": {
          "3": 1000,
          "1": 100
        },
    "2": {
          "3": 200
        },
    "3": {
          "3": 300
        },
    "4": {
          "3": 400
        },
    "5": {
          "3": 500,
          "1": 50
        },
    "6": {
          "3": 600
        }
  }
  
  # Create occurrences hash for dice rolls
  dice_hash = dice.reduce(Hash.new(0)) do |hsh, dice|
    hsh[dice] += 1
    hsh
  end
  
  # Loop through all occurrences and check to see point total and aggregate to total_points
  dice_hash.each_pair do |key, value|
    if value >= 3 && value < 6      
      total_score += score_key_hash[key.to_s.to_sym][:"3"]
      if key == 1 || key == 5
        total_score += score_key_hash[key.to_s.to_sym][:"1"] * (value - 3)
      end
    elsif value == 6
      # since all 6 dice are the same, return the total for 3 dices * 2 points
      return score_key_hash[key.to_s.to_sym][:"3"] * 2
    elsif (key == 1 || key == 5) && (value < 3)
      total_score += score_key_hash[key.to_s.to_sym][:"1"] * value
    end
  end
  
  # return total score
  total_score
end