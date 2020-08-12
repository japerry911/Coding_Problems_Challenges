defmodule NumberDrillsThinkful do
  def is_divisible(wall_length, pixel_size) do
    rem(wall_length, pixel_size) === 0
  end
end
