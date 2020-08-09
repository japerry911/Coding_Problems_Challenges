/*
---Playing in Sandpiles---
Let's learn about a new type of number: the Sandpile.

What are Sandpiles?
A sandpile is a grid of piles of sand ranging from 0 to some max integer value. 
For simplicity's sake, we'll look at a 3x3 grid containing 0, 1, 2, or 3 grains of sand.

An example of this sort of sandpile might look like this:

1 3 0     . ∴ 
1 2 1  =  . : .
3 2 2     ∴ : :
This means that in row one, column one, there's 1 grain of sand, then 3 grains, then 0, etc.

Sandpile Math
I mentioned that Sandpiles are a form of number, and as numbers, they support a single operation: 
addition. To add two sandpiles, simply add the number of grains of sand within each cell with the 
matching cell in the second value:

1 3 0   2 0 2   (1+2) (3+0) (0+2)   3 3 2
1 2 1 + 2 1 0 = (1+2) (2+1) (1+0) = 3 3 1
3 2 2   0 0 1   (3+0) (2+0) (2+1)   3 2 3
Toppling Piles
You probably already have wondered, what happens if the number of grains goes above our max value of 
3? The answer is, that pile topples over. If the pile is in the middle, it dumps one grain of sand to 
each neighbor, keeping whatever is left over. If it's on the edge, it loses one grain to each direct 
neighbor and also loses one grain for any edges that are on the side, which just disappear. This means 
that, no matter what, the over-sized cell loses 4 grains of sand, while any neighboring cells gain 1 grain 
of sand.

This repeats until we've reached a state or equilibrium, like so:

                           *            *
1 3 0   3 0 2   4 3 2    * 0 5 2      2 1 3      2 1 3
1 2 1 + 2 3 0 = 3 5 1 =>   5 1 2 => * 1 3 2 =>   2 3 2 =>
3 2 2   0 0 1   3 2 3      3 3 3      4 3 3    * 0 4 3
                                                 *

                                                   *
                2 1 3    2 2 3      2 2 4      2 3 0 *
             => 2 4 2 => 3 0 4   => 3 1 0 * => 3 1 1
                1 0 4    1 2 0 *    1 2 1      1 2 1
                  *          *
So the final sum looks like this.

1 3 0   3 0 2   2 3 0
1 2 1 + 2 3 0 = 3 1 1
3 2 2   0 0 1   1 2 1
That's a lot of work, and fairly error-prone. (Trust me!)

The Challenge
We want to create a class, Sandpile, that simulates the 3x3, max 3 sandpile. This class should have the 
following properties:

The constructor optionally takes a string, which is 3 groups of 3 integers (0-9), separated by a newline. 
If any of the values of the integers are over 3, then immediately topple each pile until the Sandpile is 
at rest. If no argument is provided, initialize the piles with all zeros.
There should be a toString method, which prints the sandpile the same way as the constructor. This will 
be used to validate your results.
There should be an add method, which takes another Sandpile as an argument. This method returns a new Sandpile, 
with the sum of the previous Sandpiles.
Sandpiles are immutable after creation
To let you focus on the fun part of this challenge, you don't have to worry about validation:
The input to the contructor will either be nothing or a string that matches /[0-9]{3}\n[0-9]{3}\n[0-9]{3}/
The add function will only ever receive another Sandpile instance.
Thinking Ahead
While working on this, think about what might be involved in a more generic Sandpile class, which could 
have a grid of any dimension, or allow for different numbers of grains before toppling over.

If you like this Kata, I'll look at an extended version tackling the dynamic sandpile.
*/

class Sandpile {
  constructor(piles) {
    if (!piles) {
      this.piles = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
      ];
      return this;
    }

    const pilesArray = [];
    let over3Bool = false;

    for (const pileRow of piles.split("\n")) {
      const pileArray = [];
      for (const pile of pileRow.split("")) {
        if (parseInt(pile) > 3) {
          over3Bool = true;
        }
        pileArray.push(parseInt(pile));
      }
      pilesArray.push(pileArray);
    }

    if (!over3Bool) {
      this.piles = pilesArray;
    } else {
      this.piles = this.toppler(pilesArray);
    }

    return this;
  }

  toppler(piles) {
    for (let r = 0; r < piles.length; ++r) {
      for (let c = 0; c < piles[r].length; ++c) {
        if (piles[r][c] > 3) {
          piles[r][c] -= 4;

          if (c < piles[r].length - 1) {
            ++piles[r][c + 1];
          }

          if (c > 0) {
            ++piles[r][c - 1];
          }

          if (r < piles.length - 1) {
            ++piles[r + 1][c];
          }

          if (r > 0) {
            ++piles[r - 1][c];
          }

          r = -1;
          break;
        }
      }
    }

    return piles;
  }

  add(sandpilesInstance) {
    const sandpiles = sandpilesInstance.piles;

    const newSandpilesArray = new Array(sandpiles.length)
      .fill(0)
      .map((_) => new Array(sandpiles.length).fill(0));
    let over3Bool = false;

    for (let r = 0; r < sandpiles.length; ++r) {
      for (let c = 0; c < sandpiles[r].length; ++c) {
        const insertValue = sandpiles[r][c] + this.piles[r][c];

        if (insertValue > 3) {
          over3Bool = true;
        }

        newSandpilesArray[r][c] = insertValue;
      }
    }

    let toppledNewSandpiles = newSandpilesArray;
    if (over3Bool) {
      toppledNewSandpiles = this.toppler(newSandpilesArray);
    }

    let parameterString = "";

    for (let i = 0; i < toppledNewSandpiles.length; ++i) {
      for (let pile of toppledNewSandpiles[i]) {
        parameterString += pile;
      }

      if (i < toppledNewSandpiles.length - 1) {
        parameterString += "\n";
      }
    }

    return new Sandpile(parameterString);
  }

  toString() {
    let returnString = "";

    for (let i = 0; i < this.piles.length; ++i) {
      for (let pile of this.piles[i]) {
        returnString += pile;
      }

      if (i < this.piles.length - 1) {
        returnString += "\n";
      }
    }

    return returnString;
  }
}

module.exports = Sandpile;
