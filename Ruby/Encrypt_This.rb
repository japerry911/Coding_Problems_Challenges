# Split up the text by spaces into an array of word(s) and then encrypt each word and map back
# into an array and return at array joined with spaces at the end (encrypted sentence)
def encrypt_this(text)
  text_split = text.split(" ")
  text_split.map {|word| encrypt_word(word)}.join(" ")  
end

# Encrypt the word into the encrypted word and then return it
def encrypt_word(word)
  if word.length == 1
    return word[0].ord.to_s
  end

  return_word = word[0].ord.to_s.concat(word[-1])
  counter = 2

  while counter < word.length - 1 do 
    return_word += word[counter]
    counter += 1
  end
  
  if word.length > 2
    return_word += word[1]  
  end
  
  return return_word
end