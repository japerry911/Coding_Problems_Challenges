"""
Write a SELECT query which will return all prime numbers smaller than 100 in ascending order.

Your query should return one column named prime.
"""

-- Generate numbers 1 100 in WITH query
-- Select from that temporary table and use a set of rules to determine if it's prime or not
WITH nums AS (
  SELECT * FROM generate_series(1, 100)
  )
  SELECT generate_series AS prime
  FROM nums
  WHERE (generate_series % 2 = 1 AND generate_series % 3 > 0 AND generate_series % 5 > 0 AND 
        generate_series % 7 > 0 AND generate_series % 9 > 0 AND generate_series > 1) 
        OR (generate_series IN (2, 3, 5, 7))