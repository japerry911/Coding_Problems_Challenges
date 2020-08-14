defmodule WhatIsBetweenTest do
  use ExUnit.Case
  doctest WhatIsBetween

  test "greets the world" do
    assert WhatIsBetween.hello() == :world
  end
end
