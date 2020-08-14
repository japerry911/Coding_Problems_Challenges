defmodule Rot13 do
  def rot13(string) do
    string
    |> String.split("")
    |> Enum.filter(fn x -> x != "" end)
    |> Enum.map(&encrypt_character/1)
    |> List.to_string()
  end

  def encrypt_character(char) do
    if(Regex.match?(~r/[A-Za-z]/, char)) do
      <<v::utf8>> = char

      if v <= 90 do
        if v + 13 > 90 do
          64 + v + 13 - 90
        else
          v + 13
        end
      else
        if v + 13 > 122 do
          96 + v + 13 - 122
        else
          v + 13
        end
      end
    else
      char
    end
  end
end
