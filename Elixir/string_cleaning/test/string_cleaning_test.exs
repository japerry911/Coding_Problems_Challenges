defmodule StringCleaningTest do
  use ExUnit.Case
  doctest StringCleaning

  test "greets the world" do
    assert StringCleaning.hello() == :world
  end
end
