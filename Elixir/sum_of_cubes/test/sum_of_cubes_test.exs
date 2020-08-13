defmodule SumOfCubesTest do
  use ExUnit.Case
  doctest SumOfCubes

  test "sample test - 1" do
    assert SumOfCubes.sum_cubes(1) == 1
  end

  test "sample test - 2" do
    assert SumOfCubes.sum_cubes(10) == 3025
  end

  test "sample test - 3" do
    assert SumOfCubes.sum_cubes(123) == 58_155_876
  end

  test "sample test - 4" do
    assert SumOfCubes.sum_cubes(23470) == 75_862_888_533_874_225
  end
end
