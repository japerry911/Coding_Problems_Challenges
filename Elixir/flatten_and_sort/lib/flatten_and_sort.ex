defmodule FlattenAndSort do
  def solution(list) do
    list
    |> List.flatten()
    |> Enum.sort()
  end
end
