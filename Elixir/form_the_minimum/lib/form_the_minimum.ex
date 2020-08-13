defmodule FormTheMinimum do
  def minValue(numbers) do
    numbers
    |> Enum.uniq()
    |> Enum.sort()
    |> Enum.join()
    |> String.to_integer()
  end
end
