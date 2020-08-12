defmodule PriceOfMangoes do
  def mango(quantity, price) do
    # free_mangos = div(quantity, 3)
    # mangoes_to_pay_for = quantity - free_mangos
    # mangoes_to_pay_for * price

    quantity
    |> div(3)
    |> subtract_free_mangoes(quantity)
    |> calculate_final_cost(price)
  end

  def subtract_free_mangoes(free_mangoes, quantity) do
    quantity - free_mangoes
  end

  def calculate_final_cost(quantity, price) do
    quantity * price
  end
end
