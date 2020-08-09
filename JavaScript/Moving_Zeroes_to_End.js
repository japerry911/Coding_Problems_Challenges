/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

moveZeros([false,1,0,1,2,0,1,3,"a"]) // returns[false,1,1,2,1,3,"a",0,0]
*/

var moveZeros = function (arr) {
  // Create new empty Array & pull all zeroes out of array input
  let return_array = []
  const zeroes = arr.filter(element => element === 0);
  
  // Fill the empty array with everything but the zeroes
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] !== 0) {
      return_array.push(arr[i]);
    }
  }
  
  // Add all of the zeroes to the end of the return_array
  for (let i = 0; i < zeroes.length; i++) {
    return_array.push(zeroes[i]);
  }
  
  // Return return_array
  return return_array;
}