defmodule CamelCaseConverterTest do
  use ExUnit.Case
  doctest CamelCaseConverter

  test "sample tests - 1" do
    assert CamelCaseConverter.to_camel_case("the-stealth-warrior") == "theStealthWarrior"
  end

  test "sample tests - 2" do
    assert CamelCaseConverter.to_camel_case("The_Stealth_Warrior") == "TheStealthWarrior"
  end
end
