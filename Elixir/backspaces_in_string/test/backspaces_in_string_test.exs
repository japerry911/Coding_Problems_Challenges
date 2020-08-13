defmodule BackspacesInStringTest do
  use ExUnit.Case
  doctest BackspacesInString

  test "sample tests - 1" do
    assert BackspacesInString.clean_string("abc#d##c") == "ac"
  end

  test "sample tests - 2" do
    assert BackspacesInString.clean_string("abc####d##c#") == ""
  end

  test "sample tests - 3" do
    assert BackspacesInString.clean_string("#######") == ""
  end

  test "sample tests - 4" do
    assert BackspacesInString.clean_string("") == ""
  end
end
