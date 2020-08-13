defmodule RgbToHexConversion do
  def rgb(r, g, b) do
    convert_to_hex(r) <> convert_to_hex(g) <> convert_to_hex(b)
  end

  def convert_to_hex(num) do
    case num do
      x when x >= 255 -> "FF"
      x when x <= 0 -> "00"
      x when x <= 15 -> "0" <> Integer.to_string(x, 16)
      x -> Integer.to_string(x, 16)
    end
  end
end
