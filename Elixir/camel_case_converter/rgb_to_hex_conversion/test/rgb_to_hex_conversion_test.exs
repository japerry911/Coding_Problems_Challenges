defmodule RgbToHexConversionTest do
  use ExUnit.Case
  doctest RgbToHexConversion

  test "sample tests - 1" do
    assert RgbToHexConversion.rgb(255, 255, 300) == "FFFFFF"
  end

  test "sample tests - 2" do
    assert RgbToHexConversion.rgb(173, 255, 47) == "ADFF2F"
  end
end
