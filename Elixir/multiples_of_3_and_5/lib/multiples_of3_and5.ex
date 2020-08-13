defmodule MultiplesOf3And5 do
  def solution(number) do
    1..(number - 1)
    |> Enum.to_list()
    |> Enum.reduce(0, fn x, acc ->
      if rem(x, 5) == 0 or rem(x, 3) == 0 do
        acc + x
      else
        acc
      end
    end)
  end
end
