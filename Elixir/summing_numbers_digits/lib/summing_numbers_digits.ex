defmodule SummingNumbersDigits do
  def sum_digits(number) do
    case number do
      0 -> 0
      x when x > 0 -> rem(number, 10) + sum_digits(div(number, 10))
      x when x < 0 -> -rem(number, 10) + sum_digits(div(-number, 10))
    end
  end
end
