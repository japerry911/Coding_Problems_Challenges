"""
For this kata we will be using the DVD Rental database.

Your are working for a company that wants to reward its top 10 customers with a free gift. You have been asked to generate a simple report that returns the top 10 customers by total amount spent. Total number of payments has also been requested.

The query should output the following columns:

customer_id [int4]
email [varchar]
payments_count [int]
total_amount [float]
and has the following requirements:

only returns the 10 top customers, ordered by total amount spent
"""

-- Selecting basic columns from customer table, and then aggregates of
-- payment table and joining into the payment table
SELECT customer.customer_id, customer.email, COUNT(payment.payment_id) AS payments_count, CAST(SUM(payment.amount) AS FLOAT) AS total_amount
FROM customer
JOIN payment
  ON customer.customer_id = payment.customer_id
GROUP BY customer.customer_id, customer.email
ORDER BY SUM(payment.amount) DESC
LIMIT 10