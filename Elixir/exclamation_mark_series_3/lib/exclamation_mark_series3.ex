defmodule ExclamationMarkSeries3 do
  def remove(s) do
    Regex.replace(~r/([^!]*)[!]*([^!]*\w+)/, s, "\\1\\2")
  end
end
