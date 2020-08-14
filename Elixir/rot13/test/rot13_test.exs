defmodule Rot13Test do
  use ExUnit.Case
  doctest Rot13

  test "sample tests - 1" do
    assert Rot13.rot13("test") == "grfg"
  end

  test "sample tests - 2" do
    assert Rot13.rot13("Test") == "Grfg"
  end
end
