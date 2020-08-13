defmodule FillTheHardDriveTest do
  use ExUnit.Case
  doctest FillTheHardDrive

  test "sample test - 1" do
    assert FillTheHardDrive.save([4, 4, 4, 3, 3], 12) === 3
  end

  test "sample test - 2" do
    assert FillTheHardDrive.save([4, 4, 4, 3, 3], 11) === 2
  end

  test "sample test - 3" do
    assert FillTheHardDrive.save([4, 8, 15, 16, 23, 42], 108) === 6
  end

  test "sample test - 4" do
    assert FillTheHardDrive.save([11, 13, 15, 17, 19], 8) === 0
  end

  test "sample test - 5" do
    assert FillTheHardDrive.save([1, 2, 3, 4], 250) === 4
  end
end
