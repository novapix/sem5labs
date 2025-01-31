def generate_playfair_matrix(key):
    # Create a matrix filled with empty strings
    matrix = [['' for _ in range(5)] for _ in range(5)]
    
    # Convert the key to uppercase and remove duplicates
    key = ''.join(dict.fromkeys(key.upper()))  # Remove duplicates while preserving order
    
    # Fill the matrix with the key
    alphabet = 'ABCDEFGHIKLMNOPQRSTUVWXYZ'  
    key_index = 0
    for i in range(5):
        for j in range(5):
            if key_index < len(key):
                matrix[i][j] = key[key_index]
                key_index += 1
            else:
                # Fill the remaining spaces with the alphabet (excluding 'J')
                for letter in alphabet:
                    if letter not in key:
                        matrix[i][j] = letter
                        alphabet = alphabet.replace(letter, '')  # Remove used letter
                        break
    return matrix

def prepare_input(text):
    # Remove spaces and non-alphabetic characters, convert to uppercase
    text = ''.join(filter(str.isalpha, text.upper()))
    # Replace 'J' with 'I'
    text = text.replace('J', 'I')
    
    # Insert 'X' between repeated letters and handle odd-length text
    i = 0
    while i < len(text) - 1:
        if text[i] == text[i + 1]:
            text = text[:i + 1] + 'X' + text[i + 1:]
        i += 2
    
    # If the text has an odd number of letters, add an 'X' at the end
    if len(text) % 2 != 0:
        text += 'X'
    
    return text

def find_position(matrix, char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j

def encrypt(text, key):
    matrix = generate_playfair_matrix(key)
    text = prepare_input(text)
    ciphertext = ''
    for i in range(0, len(text), 2):
        char1 = text[i]
        char2 = text[i + 1]
        row1, col1 = find_position(matrix, char1)
        row2, col2 = find_position(matrix, char2)
        
        # Case 1: Same row
        if row1 == row2:
            ciphertext += matrix[row1][(col1 + 1) % 5]
            ciphertext += matrix[row2][(col2 + 1) % 5]
        
        # Case 2: Same column
        elif col1 == col2:
            ciphertext += matrix[(row1 + 1) % 5][col1]
            ciphertext += matrix[(row2 + 1) % 5][col2]
        
        # Case 3: Rectangle
        else:
            ciphertext += matrix[row1][col2]  
            ciphertext += matrix[row2][col1]  
    
    return ciphertext

def decrypt(ciphertext, key):
    matrix = generate_playfair_matrix(key)
    plaintext = ''
    for i in range(0, len(ciphertext), 2):
        char1 = ciphertext[i]
        char2 = ciphertext[i + 1]
        row1, col1 = find_position(matrix, char1)
        row2, col2 = find_position(matrix, char2)
        
        # Case 1: Same row
        if row1 == row2:
            plaintext += matrix[row1][(col1 - 1) % 5]  
            plaintext += matrix[row2][(col2 - 1) % 5]  
        
        # Case 2: Same column
        elif col1 == col2:
            plaintext += matrix[(row1 - 1) % 5][col1]  
            plaintext += matrix[(row2 - 1) % 5][col2]  
        
        # Case 3: Rectangle
        else:
            plaintext += matrix[row1][col2]  
            plaintext += matrix[row2][col1] 

        i = 0 
        while i < len(plaintext) - 1:
            if plaintext[i] == plaintext[i+1] and plaintext[i+1] == 'X':
                plaintext = plaintext[:i+1] + plaintext[i+2:]
            else:
                i += 1
        
        if plaintext[-1] == 'X':
            plaintext = plaintext[:-1]

    return plaintext

# Example usage:
key = str(input("Enter the key: "))
text = str(input("Enter the plain text: "))

encrypted_text = encrypt(text, key)
print("Encrypted Text:", encrypted_text)

decrypted_text = decrypt(encrypted_text, key)
print("Decrypted Text:", decrypted_text)