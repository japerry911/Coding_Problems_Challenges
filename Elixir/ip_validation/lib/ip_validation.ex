defmodule IpValidation do
  def is_valid_ip(ip) do
    Regex.match?(~r/^((25[0-5]|(2[0-4]|1[0-9]|[1-9]|)[0-9])(\.(?!$)|$)){4}$/, ip)
  end
end
