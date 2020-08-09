"""
The Fibonacci numbers are the numbers in the following integer sequence (Fn):

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

such as

F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array:

[F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
depending on the language if F(n) * F(n+1) = prod.

If you don't find two consecutive F(m) verifying F(m) * F(m+1) = prodyou will return

[F(m), F(m+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
F(m) being the smallest one such as F(m) * F(m+1) > prod.
"""

def productFib(prod)
  # Declaring first two fibonacci numbers
  fib_0 = 0
  fib_1 = 1
  
  # Infinite loop
  while true do
    # Calculate the current two fib numbers' sum
    temp_prod = fib_0 * fib_1
    
    # Check if the temp_prod value is == to prod or > prod
    # If == then it's true and the match
    # If > then it's false and there is no match
    if temp_prod == prod
      return [fib_0, fib_1, true]
    elsif temp_prod > prod
      return [fib_0, fib_1, false]
    end
    
    # Change up fib_0 and fib_1 to next respective fib numbers
    next_fib = fib_1 + fib_0
    fib_0 = fib_1
    fib_1 = next_fib
  end
end