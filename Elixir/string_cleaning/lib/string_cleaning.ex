defmodule StringCleaning do
  def remove_numbers(s) do
    Regex.replace(~r/[0-9]/, s, "")
  end
end
