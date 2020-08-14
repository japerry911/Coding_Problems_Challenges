defmodule LongestAlphaSubstring do
  def longest(s) do
    s
    |> String.split("")
    |> Enum.to_list()
    |> Enum.filter(fn x -> x != "" end)
    |> find_longest_alpha_string()
    |> Enum.join("")
  end

  def find_longest_alpha_string(
        master_list,
        current_list \\ [],
        current_longest \\ []
      ) do
    if Enum.empty?(master_list) do
      if length(current_list) > length(current_longest) do
        current_list
      else
        current_longest
      end
    else
      {first_value, updated_master} = List.pop_at(master_list, 0)

      if Enum.empty?(current_list) do
        find_longest_alpha_string(updated_master, [first_value], current_longest)
      else
        if first_value >= List.last(current_list) do
          find_longest_alpha_string(
            updated_master,
            current_list ++ [first_value],
            current_longest
          )
        else
          if length(current_list) > length(current_longest) do
            find_longest_alpha_string(updated_master, [first_value], current_list)
          else
            find_longest_alpha_string(updated_master, [first_value], current_longest)
          end
        end
      end
    end
  end
end
