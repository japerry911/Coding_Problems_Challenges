defmodule CamelCaseConverter do
  def to_camel_case(str) do
    if String.contains?(str, "-") do
      String.split(str, "-")
      |> Enum.with_index()
      |> Enum.map(fn {x, i} ->
        if i === 0 do
          x
        else
          String.capitalize(x)
        end
      end)
      |> Enum.join("")
    else
      String.split(str, "_")
      |> Enum.with_index()
      |> Enum.map(fn {x, i} ->
        if i === 0 do
          x
        else
          String.capitalize(x)
        end
      end)
      |> Enum.join("")
    end
  end
end
