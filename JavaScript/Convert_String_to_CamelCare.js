/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).

Examples
toCamelCase("the-stealth-warrior") // returns "theStealthWarrior"

toCamelCase("The_Stealth_Warrior") // returns "TheStealthWarrior"
*/

function toCamelCase(str){
  // Initializing returnString variable and strArray split
  // For strArray convert all hyphens to underscores to ensure smooth split
  let returnString = [];
  const strArray = str.replace(/-/g, '_').split('_');
  
  // For loop through the strArray
  // Push onto returnString each appropiate capitalized element
  for (let i = 0; i < strArray.length; i++) {
    returnString.push((i === 0 ? strArray[i] : capitalize(strArray[i])));
  }
  
  // Return returnString joined with nothing
  return returnString.join('');
}

// Helper function that capitalizes the first letter of inputted string
function capitalize(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
}