def caesar_cipher(text,shift):
  result=''
  for char in text:
    if char.isalpha():
      if char.isupper():
        result += chr((ord(char)-65+shift)%26+65)
      else:
        result += chr((ord(char)-97+shift)%26+97)
    else:
      result += chr((ord(char)-48+shift)%10+48)
  return result

plaintext = input("Enter plain text:")
shift = input("enter shift:")
shift = int(shift)
encrypted_text = caesar_cipher(plaintext, shift)
print("Encrypted text:", encrypted_text)

decrypted_text = caesar_cipher(encrypted_text, -shift)
print("Decrypted text:", decrypted_text)  