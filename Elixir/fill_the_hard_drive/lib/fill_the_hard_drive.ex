defmodule FillTheHardDrive do
  def save(sizes, hd) do
    {result_list, _space_taken} =
      sizes
      |> Enum.map_reduce({0, false}, fn x, acc ->
        if elem(acc, 0) + x <= hd and elem(acc, 1) === false do
          new_acc_value = elem(acc, 0) + x
          acc = put_elem(acc, 0, new_acc_value)
          {x, acc}
        else
          acc = put_elem(acc, 1, true)
          {nil, acc}
        end
      end)

    result_list
    |> Enum.filter(fn x -> x != nil end)
    |> length()
  end
end
