defmodule Count9sTest do
  use ExUnit.Case
  doctest Count9s

  test "sample tests - 1" do
    assert Count9s.number9(1) == 0
  end

  test "sample tests - 9" do
    assert Count9s.number9(9) == 1
  end

  test "sample tests - 100" do
    assert Count9s.number9(100) == 20
  end

  test "sample tests - 565754" do
    assert Count9s.number9(565_754) == 275_645
  end

  test "sample tests - 10000000000" do
    assert Count9s.number9(10_000_000_000) == 10_000_000_000
  end
end
