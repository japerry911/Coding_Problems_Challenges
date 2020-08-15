defmodule IpValidationTest do
  use ExUnit.Case
  doctest IpValidation

  test "sample tests - 1" do
    assert IpValidation.is_valid_ip("127.1.1.0") == true
  end
end
