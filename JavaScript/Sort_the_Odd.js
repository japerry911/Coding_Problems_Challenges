/*
You have an array of numbers.
Your task is to sort ascending odd numbers but even numbers must be on their places.

Zero isn't an odd number and you don't need to move it. If you have an empty array, you need to return it.

Example

sortArray([5, 3, 2, 8, 1, 4]) == [1, 3, 2, 8, 5, 4]
*/

function sortArray(array) {
  // Filter out the Odd Numbers
  const odds = array.filter(integer => integer % 2 == 1);
  odds.sort((a, b) => {
    return a - b;
  })
  
  // Loop through the array and reorder odds and keep evens in place
  let odds_counter = 0
  for (let i = 0; i < array.length; i++) {
    if (array[i] % 2 == 1) {
      array[i] = odds[odds_counter];
      odds_counter++;
    }
  }
  
  return array;
}