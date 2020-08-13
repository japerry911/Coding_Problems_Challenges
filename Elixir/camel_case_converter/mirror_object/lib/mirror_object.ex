defmodule MirrorObject do
  def mirror(map) do
    map
    |> Map.to_list()
    |> Enum.map(fn {k, _v} ->
      {k, List.to_string(Enum.reverse(String.to_charlist(Atom.to_string(k))))}
    end)
    |> Map.new()
  end
end
