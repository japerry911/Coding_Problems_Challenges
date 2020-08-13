defmodule FormTheMinimumTest do
  use ExUnit.Case
  doctest FormTheMinimum

  test "sample tests - 1" do
    assert FormTheMinimum.minValue([1, 3, 1]) === 13
  end

  test "sample tests - 2" do
    assert FormTheMinimum.minValue([4, 5, 4, 7]) === 457
  end

  test "sample tests - 3" do
    assert FormTheMinimum.minValue([4, 8, 1, 4]) === 148
  end

  test "sample tests - 4" do
    assert FormTheMinimum.minValue([5, 7, 9, 5, 7, 7]) === 579
  end

  test "sample tests - 5" do
    assert FormTheMinimum.minValue([6, 7, 8, 7, 6, 6]) === 678
  end
end
