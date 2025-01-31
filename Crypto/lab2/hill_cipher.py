import numpy as np

# Function to calculate the modular inverse of a matrix
def matrix_mod_inv(matrix, modulus):
    det = int(round(np.linalg.det(matrix)))  
    det_inv = pow(det, -1, modulus)  
    adjugate = np.round(det * np.linalg.inv(matrix)).astype(int)
    matrix_modulus_inv = (det_inv * adjugate) % modulus
    return matrix_modulus_inv

# Function to encrypt plaintext using the Hill cipher
def hill_cipher_encrypt(plaintext, key):
    n = len(key)
    plaintext = [ord(char) - ord('A') for char in plaintext.upper() if char.isalpha()]
    if len(plaintext) % n != 0:
        plaintext.extend([0] * (n - len(plaintext) % n))
    plaintext_matrix = np.array(plaintext).reshape(-1, n)
    ciphertext_matrix = np.dot(plaintext_matrix, key) % 26
    ciphertext = ''.join([chr(char + ord('A')) for row in ciphertext_matrix for char in row])
    return ciphertext

# Function to check the determinant of the given input matix
def validate_matrix(matrix):
    det = int(round(np.linalg.det(matrix)))
    if np.gcd(det,26)!=1:
        return False,det
    return True,det

# Function to decrypt ciphertext using the Hill cipher
def hill_cipher_decrypt(ciphertext, key):
    n = len(key)
    key_inv = matrix_mod_inv(key, 26)
    ciphertext = [ord(char) - ord('A') for char in ciphertext.upper() if char.isalpha()]
    ciphertext_matrix = np.array(ciphertext).reshape(-1, n)
    plaintext_matrix = np.dot(ciphertext_matrix, key_inv) % 26
    plaintext = ''.join([chr(char + ord('A')) for row in plaintext_matrix for char in row])
    return plaintext

# Define the key matrix
key_size = int(input("Enter the size of the matrix  "))
key = []
for i in range(key_size):
    row = list(map(int, input(f"Enter row {i + 1}: ").split()))
    key.append(row)
key = np.array(key)

is_invertible,determinant = validate_matrix(key)
if not is_invertible:
  print(f"Error: The matrix is not invertible modulo 26. Determinant = {determinant}")
  exit()
else:
    print("The matrix is invertible.")

plaintext = input("Enter plain text:")

ciphertext = hill_cipher_encrypt(plaintext, key)
print("Ciphertext:", ciphertext)

decrypted_text = hill_cipher_decrypt(ciphertext, key)
print("Decrypted Text:", decrypted_text)
