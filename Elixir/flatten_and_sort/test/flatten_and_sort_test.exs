defmodule FlattenAndSortTest do
  use ExUnit.Case
  doctest FlattenAndSort

  test "basic case - 1" do
    assert FlattenAndSort.solution([[]]) === []
  end

  test "basic case - 2" do
    assert FlattenAndSort.solution([[1], [2]]) === [1, 2]
  end

  test "basic case - 3" do
    assert FlattenAndSort.solution([[10, -10], [0]]) === [-10, 0, 10]
  end

  test "basic case - 4" do
    assert FlattenAndSort.solution([[], [1], [], [3, 2]]) === [1, 2, 3]
  end
end
