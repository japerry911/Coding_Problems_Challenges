defmodule ExclamationMarkSeries3Test do
  use ExUnit.Case
  doctest ExclamationMarkSeries3

  test "Sample test - 1" do
    assert ExclamationMarkSeries3.remove("Hi!!!") === "Hi!!!"
  end

  test "Sample test - 2" do
    assert ExclamationMarkSeries3.remove("Hi! Hi!") === "Hi Hi!"
  end
end
