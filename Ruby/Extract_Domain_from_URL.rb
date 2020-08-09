"""
Write a function that when given a URL as a string, parses out just the domain name and returns it as a string.
"""

def domain_name(url)
  if url.index("https://")
    modified_url = url.gsub("https://", "")
  elsif url.index("http://")
    modified_url = url.gsub("http://", "")
  else
    modified_url = url
  end
  
  if url.index("www.")
    modified_url = modified_url.gsub("www.", "")
  end
  
  modified_url.split(".")[0]
end