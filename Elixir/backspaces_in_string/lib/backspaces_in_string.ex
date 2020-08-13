defmodule BackspacesInString do
  def clean_string(s) do
    s
    |> String.graphemes()
    |> Enum.reduce([], fn x, acc ->
      if x === "#" do
        if Enum.empty?(acc) do
          acc
        else
          acc
          |> Enum.reverse()
          |> tl()
          |> Enum.reverse()
        end
      else
        acc ++ [x]
      end
    end)
    |> Enum.join("")
  end
end
