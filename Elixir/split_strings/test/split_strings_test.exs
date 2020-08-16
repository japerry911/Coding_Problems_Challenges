defmodule SplitStringsTest do
  use ExUnit.Case
  doctest SplitStrings

  test "sample tests - 1" do
    assert SplitStrings.solution("abcdef") == ["ab", "cd", "ef"]
  end

  test "sample tests - 2" do
    assert SplitStrings.solution("abcdefg") == ["ab", "cd", "ef", "g_"]
  end

  test "sample tests - 3" do
    assert SplitStrings.solution("") == []
  end
end
