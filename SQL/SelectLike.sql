/*
You will need to create SELECT statement in conjunction with LIKE.

Please list people which have first_name with at least 6 character long

names table schema
id
first_name
last_name
results table schema
first_name
last_name
*/

SELECT names.first_name, names.last_name
FROM names
WHERE names.first_name LIKE '______%';