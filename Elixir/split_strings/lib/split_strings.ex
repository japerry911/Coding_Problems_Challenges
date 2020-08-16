defmodule SplitStrings do
  def solution(str) do
    str
    |> String.to_charlist()
    |> Enum.to_list()
    |> split_string
    |> Enum.map(fn x -> List.to_string(x) end)
  end

  def split_string(str) do
    if rem(length(str), 2) == 0 do
      Enum.chunk_every(str, 2)
    else
      str = str ++ '_'
      Enum.chunk_every(str, 2)
    end
  end
end
