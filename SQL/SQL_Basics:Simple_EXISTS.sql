"""
For this challenge you need to create a SELECT statement, this SELECT statement will use an EXISTS to check whether a department has had a sale with a price over 98.00 dollars.

departments table schema
id
name
sales table schema
id
department_id (department foreign key)
name
price
card_name
card_number
transaction_date
resultant table schema
id
name
NOTE: Your solution should use pure SQL. Ruby is used within the test cases to do the actual testing. Do not: alias tables as this can cause a failure.
"""

-- Basic use of EXISTS, select the department name and id from departments and
-- then do a WHERE EXISTS + subquery on sales to get the sales that only have a price over 98
SELECT departments.id, departments.name
FROM departments
WHERE EXISTS
  (SELECT price, department_id FROM sales WHERE price > 98 and department_id = departments.id)
ORDER BY departments.id ASC
LIMIT 5