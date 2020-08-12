defmodule TransportationOnVacation do
  def rental_car_cost(d) do
    cost = d * 40

    if d >= 7 do
      cost = cost - 50
      cost
    else
      if d >= 3 do
        cost = cost - 20
        cost
      else
        cost
      end
    end
  end
end
