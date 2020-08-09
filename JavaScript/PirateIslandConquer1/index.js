/*
---Pirate Island Conquer Part 1---
This kata is part of a series. Check this out when you're done:

Pirate Island Conquer Part 2

Pirate Island Conquer Part 3


Description
You are a captain on a pirate ship. You are looking to conquer islands, so that you can do lots 
of piratey stuff on those islands. Let's take a look at your pirate map of the area:


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

'p' = pirate (that's our home island). There will always be one home island, always in the top
left corner of the sea.
'u' = unoccupied island
'm' = island occupied by marines
'~' = ocean waves
The map size will always be 8 x 8. Each of 'p', 'u', 'm' and '~' can occur in any space of the map.
Coordinates are given as [x,y] (examples from the above map: 'p' at [0, 0], 'u' at [3, 2], 'm' at [4, 4]).


Input
A see map, formatted as an array of arrays of strings.

Output
Return an array containing all the best candidates (ordered by lowest x coordinate, then lowest y), 
or an empty array if no island to conquer.


Rules (highest priority first)
Conquer an unoccupied island.
If there are no unoccupied islands, conquer one of the marines' islands.
Conquer the island closest to any of our home islands (the p items / distances are computed as 
Manhattan distances).

Distance
Pirates can only move vertically and horizontally, not diagonally. Moving one index in the array 
is one unit of distance.

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
*/

function conquerIsland(map) {
  const mapItems = {};

  for (let r = 0; r < map.length; ++r) {
    for (let c = 0; c < map[r].length; ++c) {
      if (map[r][c] !== "~" && map[r][c] !== "p") {
        if (mapItems[map[r][c]] === undefined) {
          mapItems[map[r][c]] = [];
        }

        mapItems[map[r][c]].push([r, c]);
      }
    }
  }

  const islands = Object.keys(mapItems).sort().reverse();
  let minDistance = null;
  let uIsland = false;

  for (let island of islands) {
    if (island === "u") {
      uIsland = true;
    }
    for (let location of mapItems[island]) {
      if (uIsland && island === "m") {
        return minDistance;
      }

      if (!minDistance) {
        minDistance = [location];
      } else if (
        location[0] + location[1] <
        minDistance[0][0] + minDistance[0][1]
      ) {
        minDistance = [location];
      } else if (
        location[0] + location[1] ===
        minDistance[0][0] + minDistance[0][1]
      ) {
        if (minDistance[0][0] > location[0]) {
          minDistance.unshift(location);
        } else {
          minDistance.push(location);
        }
      }
    }
  }

  return !minDistance ? [] : minDistance;
}

module.exports = conquerIsland;
