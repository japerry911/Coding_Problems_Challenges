defmodule LongestAlphaSubstringTest do
  use ExUnit.Case
  doctest LongestAlphaSubstring

  test "sample tests - 1" do
    assert LongestAlphaSubstring.longest("asd") == "as"
  end

  test "sample tests - 2" do
    assert LongestAlphaSubstring.longest("asdfaaaabbbbcttavvfffffdf") == "aaaabbbbctt"
  end

  test "sample tests - 3" do
    assert LongestAlphaSubstring.longest("asdfbyfgiklag") == "fgikl"
  end
end
