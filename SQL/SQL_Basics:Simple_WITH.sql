"""
For this challenge you need to create a SELECT statement, this SELECT statement will use an IN to check whether a department has had a sale with a price over 90.00 dollars BUT the sql MUST use the WITH statement which will be used to select all columns from sales where the price is greater than 90.00, you must call this sub-query special_sales.

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
NOTE: Your solution should use pure SQL. Ruby is used within the test cases to do the actual testing.
"""

-- Create temporary table, special_sales, and then use query at bottom to use values from that temporary table
-- to create the final correct table
WITH special_sales(department_id, price) AS
    (SELECT department_id, SUM(price)
    FROM sales
    GROUP BY department_id
    HAVING SUM(price) > 90)
    SELECT departments.id, departments.name
    FROM departments, special_sales
    WHERE special_sales.price > 90 AND special_sales.department_id = departments.id