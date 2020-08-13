defmodule SumOfCubes do
  def sum_cubes(n) do
    Enum.reduce(1..n, 0, fn x, acc -> acc + round(:math.pow(x, 3)) end)
  end
end
