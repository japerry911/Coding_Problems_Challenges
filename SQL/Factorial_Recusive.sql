/*
WITH RECURSIVE factorial(n, fact)             -- Declare Recurisve Query with n and fact as outputs
AS (                                            
  SELECT                                      -- Initial Query that sets everything up
    0 AS n,                                   -- 0 as n = starting index
    1::NUMERIC(22,6) AS fact                  -- Configure 1 as the starting factorial and set as numeric type (0! == 1)
  UNION ALL                                   -- UNION ALL subqueries to the final result
  SELECT
    n + 1 AS n,                               -- Increment index n by one each run through
    (fact * (n + 1))::NUMERIC(22,6) AS fact   -- Calculate factorial of n utilizing the previous calculated factorial
  FROM
    factorial                                 -- Continue the Recursion
  WHERE n < 16                                -- Stop the Recursion when index n is greater than 16
)

SELECT                                        -- Call the factorial recursive function
  n,
  fact
FROM
  factorial
*/