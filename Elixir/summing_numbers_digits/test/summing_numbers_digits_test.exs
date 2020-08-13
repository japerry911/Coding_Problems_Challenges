defmodule SummingNumbersDigitsTest do
  use ExUnit.Case
  doctest SummingNumbersDigits

  test "sample test - 1" do
    assert SummingNumbersDigits.sum_digits(10) === 1
  end

  test "sample test - 2" do
    assert SummingNumbersDigits.sum_digits(99) === 18
  end

  test "sample test - 3" do
    assert SummingNumbersDigits.sum_digits(-32) === 5
  end
end
