/*
Task
Write a function nico/nico() that accepts two parameters:

key/$key - string consists of unique letters and digits
message/$message - string to encode
and encodes the message using the key.

First create a numeric key basing on a provided key by assigning each letter position in which it is located after setting the letters from key in an alphabetical order.

For example, for the key crazy we will get 23154 because of acryz (sorted letters from the key).
Let's encode secretinformation using our crazy key.

2 3 1 5 4
---------
s e c r e
t i n f o
r m a t i
o n
After using the key:

1 2 3 4 5
---------
c s e e r
n t i o f
a r m i t
  o n   
Notes
The message is never shorter than the key.

Examples
nico("crazy", "secretinformation") => "cseerntiofarmit on  "
nico("abc", "abcd") => "abcd  "
nico("ba", "1234567890") => "2143658709" 
nico("key", "key") => "eky" 
Check the test cases for more samples.
*/

function nico (key, message) {
    const sortedKey = key.split('').sort();
    const rows = Math.ceil(message.length / key.length);
    const originalObject = {};
    const originalOrder = [];
    const encryptedArray = [];
    let encryptedMessage = '';

    for (let char of key) {
      originalOrder.push((sortedKey.indexOf(char) + 1).toString());
      originalObject[sortedKey.indexOf(char) + 1] = [];
    }

    let iterator = 0;
    for (let char of message) {
      originalObject[originalOrder[iterator]].push(char);

      iterator++;

      if (iterator >= originalOrder.length) iterator = 0;
    }

    for (let char in originalObject) {
      encryptedArray.push(originalObject[char]);
    }

    for (let i = 0; i < rows; i++) {
      for (let array of encryptedArray) {
        if (array[i] === undefined) {
          encryptedMessage += ' ';
        } else {
          encryptedMessage += array[i];
        }
      }
    }

    return encryptedMessage;
}

module.exports = nico;