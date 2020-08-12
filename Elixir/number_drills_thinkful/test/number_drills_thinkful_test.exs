defmodule NumberDrillsThinkfulTest do
  use ExUnit.Case
  doctest NumberDrillsThinkful

  test "greets the world" do
    assert NumberDrillsThinkful.hello() == :world
  end
end
