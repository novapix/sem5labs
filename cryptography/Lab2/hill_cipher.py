import numpy as np


def matrix_mod_inv(matrix, modulus):
    det = int(np.round(np.linalg.det(matrix)))
    det_inv = pow(det, -1, modulus)
    matrix_modulus_inv = det_inv * np.round(det * np.linalg.inv(matrix)) % modulus
    return matrix_modulus_inv


def hill_cipher_encrypt(plaintext, key):
    n = len(key)
    plaintext = [ord(char) - ord("A") for char in plaintext.upper()]
    if len(plaintext) % n != 0:
        plaintext.extend([15] * (n - len(plaintext) % n))
    plaintext_matrix = np.array(plaintext).reshape(-1, n)
    ciphertext_matrix = np.dot(plaintext_matrix, key) % 26
    ciphertext = "".join(
        [chr(char + ord("A")) for row in ciphertext_matrix for char in row]
    )
    return ciphertext


def hill_cipher_decrypt(ciphertext, key):
    n = len(key)
    key_inv = matrix_mod_inv(key, 26)
    ciphertext = [ord(char) - ord("A") for char in ciphertext.upper() if char.isalpha()]
    ciphertext_matrix = np.array(ciphertext).reshape(-1, n)
    plaintext_matrix = np.round(np.dot(ciphertext_matrix, key_inv)).astype(int) % 26
    plaintext = "".join(
        [chr(char + ord("A")) for row in plaintext_matrix for char in row]
    )
    return plaintext


def input_key_matrix():
    size = int(input("Enter the size of the key square matrix: "))

    key = []
    print(f"Enter the {size}x{size} key matrix values row by row:")

    for i in range(size):
        while True:
            row_input = input(
                f"Row {i + 1} (enter {size} numbers separated by spaces): "
            ).strip()
            try:
                row = list(map(int, row_input.split()))

                if len(row) != size:
                    print(
                        f"Error: Expected {size} numbers, but got {len(row)}. Try again."
                    )
                    continue

                key.append(row)
                break
            except ValueError:
                print("Invalid input.")

    return np.array(key)


# key = np.array([[17,17,5],[21,18,21],[2,2,19]])
# plaintext = "paymoremoney"
key = input_key_matrix()
plaintext = input("Enter Text to be encryped: ")

cipher_txt = hill_cipher_encrypt(plaintext, key)
print(f"Encryped text: {cipher_txt}")

plain_txt = hill_cipher_decrypt(cipher_txt, key)
print(f"Decyrpted text: {plain_txt}")
