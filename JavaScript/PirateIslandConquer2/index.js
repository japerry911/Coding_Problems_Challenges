/*
---Pirate Island Conquer Part 2---
Description</font size>

This kata is part of a series! You may want to start with part 1:

Pirate Island Conquer Part 1


Quick instructions
If you haven't completed part 1, scroll down for the complete instructions. If you completed part 
1, part 2 is similar with the following changes:

The pirate home island is not only at [0, 0].
There is between 1 and 3 pirate home islands.

Complete Instructions

Description
You are a captain on a pirate ship. You are looking to conquer islands, so that you can do 
lots of piratey stuff on those islands. Let's take a look at your pirate map of the area:


Map
                      y
         0    1    2    3    4    5    6    7

  0    ['p', '~', '~', '~', '~', '~', '~', '~'],
  1    ['~', '~', '~', '~', '~', '~', '~', '~'],
  2    ['~', '~', '~', '~', '~', '~', '~', '~'],
  3    ['~', '~', 'u', '~', '~', '~', '~', '~'],
x 4    ['~', '~', '~', '~', 'm', '~', '~', '~'],
  5    ['~', '~', '~', '~', '~', '~', '~', '~'],
  6    ['~', '~', '~', '~', '~', '~', '~', '~'],
  7    ['~', '~', '~', '~', '~', '~', '~', '~']];
Where:

'p' = pirate (that's our home island). There will always be one home island, always in the 
top left corner of the sea.
'u' = unoccupied island
'm' = island occupied by marines
'~' = ocean waves
The map size will always be 8 x 8. Each of 'p', 'u', 'm' and '~' can occur in any space of the map.
Coordinates are given as [x,y] (examples from the above map: 'p' at [0, 0], 'u' at [3, 2], 'm' at [4, 4]).


Input
A see map, formatted as an array of arrays of strings.

Number of each label in one map:

'p': 1 to 3
'u': 0 to 5
'm': 0 to 5
Output
Return an array containing all the best candidates (ordered by lowest x coordinate, 
then lowest y), or an empty array if no island to conquer.


Rules (highest priority first)
Conquer an unoccupied island.
If there are no unoccupied islands, conquer one of the marines' islands.
Conquer the island(s) closest to any of our home islands (the p items / distances are computed as Manhattan distances).

Distance
Pirates can only move vertically and horizontally, not diagonally. Moving one index in the array is one unit of distance.

Example 1: The 'u' island is 2 units away:

    ['p', '~', 'u', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ...
Example 2: The 'u' island is 3 + 2 = 5 units away.

  |  ['p', '~', '~', '~', '~', '~', '~', '~'],
  |  ['~', '~', '~', '~', '~', '~', '~', '~'],
3 |  ['~', '~', '~', '~', '~', '~', '~', '~'],
  |  ['~', '~', 'u', '~', '~', '~', '~', '~'],
  |---------->
      2

Examples:
Example 1:

    map = [
    ['p', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', 'm', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', 'u', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~']];
solution = [[4, 4]]
There is a 'u' and an 'm'. Rules say we conquer a 'u' if possible, so...

Example 2:

    map = [
    ['p', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', 'm', '~', '~', '~', '~'],
    ['m', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', 'm', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', 'm', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~']];
solution = [[2,0]]

Example 3:

    map = [
    ['p', '~', '~', '~', '~', '~', '~', '~'],
    ['~', 'm', '~', 'm', '~', '~', '~', '~'],
    ['m', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', 'm', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', 'm', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~']];
There are no 'u' islands, so we'll take an 'm'. But wait! There are two the same distance away.

solution = [[1, 1], [2, 0]], not [[2, 0], [1, 1]] (lowest 'x' value first)

Example 4:

map = [
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', 'p', 'm', '~', '~', '~', '~'],
    ['m', '~', 'm', 'p', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', 'm', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~'],
    ['~', '~', '~', 'm', '~', '~', '~', '~'],
    ['~', '~', '~', '~', '~', '~', '~', '~']];
solution = [[1, 3], [2, 2]]
There are no 'u' islands, so we'll take the closest two 'm' islands.
*/

function conquerIsland(map) {
  const itemsMap = {};

  for (let i = 0; i < map.length; ++i) {
    for (let c = 0; c < map[i].length; ++c) {
      if (map[i][c] === "~") {
        continue;
      }

      if (itemsMap[map[i][c]] === undefined) {
        itemsMap[map[i][c]] = [];
      }

      itemsMap[map[i][c]].push([i, c]);
    }
  }

  let minDistance = null;
  const islands = Object.keys(itemsMap).sort().reverse();
  const yeHavens = itemsMap["p"];
  let uIslandBool = false;

  for (let island of islands) {
    if (island === "p") {
      continue;
    } else if (island === "u") {
      uIslandBool = true;
    }

    for (let location of itemsMap[island]) {
      if (uIslandBool && island === "m") {
        return minDistance;
      }

      if (!minDistance) {
        minDistance = [location];
      } else {
        let alreadyPushedBool = false;
        for (let yeHaven of yeHavens) {
          const distanceProposed =
            Math.abs(yeHaven[0] - location[0]) +
            Math.abs(yeHaven[1] - location[1]);

          let distanceCurrent = null;
          for (let dist of minDistance) {
            for (let yeHaven2 of yeHavens) {
              distanceCurrent =
                !distanceCurrent ||
                Math.abs(yeHaven2[0] - dist[0]) +
                  Math.abs(yeHaven2[1] - dist[1]) <
                  distanceCurrent
                  ? Math.abs(yeHaven2[0] - dist[0]) +
                    Math.abs(yeHaven2[1] - dist[1])
                  : distanceCurrent;
            }
          }

          if (location[0] === 6 && location[1] === 2) {
            console.log(location);
            console.log(minDistance);
            console.log(distanceProposed, " < ", distanceCurrent);
          }
          if (distanceProposed < distanceCurrent) {
            minDistance = [location];
            break;
          } else if (
            distanceProposed === distanceCurrent &&
            !alreadyPushedBool
          ) {
            minDistance.push(location);
            alreadyPushedBool = true;
          }
        }
      }
    }
  }

  return !minDistance ? [] : minDistance;
}

module.exports = conquerIsland;
