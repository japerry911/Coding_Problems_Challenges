defmodule StrongestEvenNumber do
  def strongest_even(n, m) do
    calc_possible_strength(1, n, m, 1)
  end

  def calc_possible_strength(multiple, min, max, starting_value) do
    multiple = multiple * 2

    if multiple > max do
      calc_possible_strength(starting_value + 1, min, max, starting_value + 1)
    else
      if multiple < min do
        calc_possible_strength(multiple, min, max, starting_value)
      else
        if multiple * 2 < max do
          calc_possible_strength(multiple, min, max, starting_value)
        else
          multiple
        end
      end
    end
  end

  # def strongest_even(n, m) do
  #   {value, _strength} =
  #     n..m
  #     |> Enum.to_list()
  #     |> Enum.map(fn x -> {x, calc_strength(x)} end)
  #     |> Enum.max_by(fn {_value, strength} -> strength end)

  #   value
  # end

  # def calc_strength(number) do
  #   case number do
  #     n when rem(n, 2) > 0 -> 0
  #     n -> 1 + calc_strength(div(n, 2))
  #   end
  # end
end
