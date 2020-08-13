defmodule MirrorObjectTest do
  use ExUnit.Case
  doctest MirrorObject

  test "sample tests - 1" do
    assert MirrorObject.mirror(%{abc?: nil, "1 arara 2": nil}) == %{
             abc?: "?cba",
             "1 arara 2": "2 arara 1"
           }
  end

  test "sample tests - 2" do
    assert MirrorObject.mirror(%{abc: nil, arara: nil}) == %{abc: "cba", arara: "arara"}
  end
end
