defmodule LoveVsFriendship do
  def words_to_marks(s) do
    s
    |> String.graphemes()
    |> Enum.map(&process_character/1)
    |> Enum.sum()
  end

  def process_character(<<v::utf8>>) do
    v - 96
  end
end
