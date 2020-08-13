defmodule MultiplesOf3And5Test do
  use ExUnit.Case
  doctest MultiplesOf3And5

  test "sample tests - 1" do
    assert MultiplesOf3And5.solution(10) == 23
  end
end
