defmodule IsPalindrome do
  def is_palindrome(s) do
    s = String.downcase(s)
    s === String.reverse(s)
  end
end
