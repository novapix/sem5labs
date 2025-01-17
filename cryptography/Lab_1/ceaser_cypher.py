def caeser_cypher(text: str, shift: int) -> str:
    result = ""
    for char in text:
        if char.isalpha():
            if char.isupper():
                result += chr((ord(char) - 65 + shift) % 26 + 65)
            else:
                result += chr((ord(char) - 97 + shift) % 26 + 97)
        else:
            result += str((int(char) + shift) % 10)

    return result


plaintext = input("Enter plain text: ")
shift = int(input("Enter Shift: "))
encrpyted_text = caeser_cypher(plaintext, shift)
print(f"Encryped text : {encrpyted_text}\n")

decrypted_text = caeser_cypher(encrpyted_text, -shift)
print(f"decrypted text : {decrypted_text}\n")
