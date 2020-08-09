/*
Sum of Pairs
Given a list of integers and a single sum value, return the first two values (parse from the left please) in order of appearance that add up to form the sum.

sum_pairs([11, 3, 7, 5],         10)
#              ^--^      3 + 7 = 10
== [3, 7]

sum_pairs([4, 3, 2, 3, 4],         6)
#          ^-----^         4 + 2 = 6, indices: 0, 2 *
#             ^-----^      3 + 3 = 6, indices: 1, 3
#                ^-----^   2 + 4 = 6, indices: 2, 4
#  * entire pair is earlier, and therefore is the correct answer
== [4, 2]

sum_pairs([0, 0, -2, 3], 2)
#  there are no pairs of values that can be added to produce 2.
== None/nil/undefined (Based on the language)

sum_pairs([10, 5, 2, 3, 7, 5],         10)
#              ^-----------^   5 + 5 = 10, indices: 1, 5
#                    ^--^      3 + 7 = 10, indices: 3, 4 *
#  * entire pair is earlier, and therefore is the correct answer
== [3, 7]
Negative numbers and duplicate numbers can and will appear.

NOTE: There will also be lists tested of lengths upwards of 10,000,000 elements. Be sure your code doesn't time out.
*/

var sum_pairs=function(ints, s) {
    let sumPairs = [];
      
    for (let i = 0; i <= ints.length / 2; i++) {
      for (let r = i + 1; r < ints.length; r++) {
        if (ints[i] + ints[r] === s) {
          const matchObject = {};
          
          matchObject['start'] = [i, ints[i]];
          matchObject['end'] = [r, ints[r]];
          
          sumPairs.push(matchObject);
          
          break;
        }
      }
    }
          
    if (sumPairs.length === 0) {
      return undefined;
    } else if (sumPairs.length === 1) {
      return [sumPairs[0]['start'][1], sumPairs[0]['end'][1]];
    } else {
      const returnObject = sumPairs.reduce((accumulator, currentPair) => {
        if (currentPair['end'][0] < accumulator['endIndex']) {
          accumulator['endIndex'] = currentPair['end'][0];
          accumulator['pair'] = [currentPair['start'][1], currentPair['end'][1]];
        }
        return accumulator
      }, { 'pair': [], 'endIndex': 1000000000 });
      
      return returnObject['pair'];
    }
  }