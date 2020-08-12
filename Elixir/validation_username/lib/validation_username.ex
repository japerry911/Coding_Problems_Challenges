defmodule ValidationUsername do
  def valid?(username) do
    if String.contains?(username, "\n") do
      false
    else
      Regex.match?(~r/^[a-z0-9_]{4,16}$/, username)
    end
  end
end
