#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string text, int shift) {
  string result;
  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      char shifted = (c - base + shift) % 26 + base;
      result += shifted;
    } else {
      result += to_string((c - '0') % 10);
    }
  }

  return result;
}

int main() {
  string text;
  int shift;

  cout << "Enter the text to encrypt: ";
  getline(std::cin, text);
  cout << "Enter the shift value: ";
  cin >> shift;

  string encryptedText = caesarCipher(text, shift);
  cout << "Encrypted text: " << encryptedText << endl;
  string decrytpedText = caesarCipher(encryptedText, -shift);
  cout << "Decrypted Text: " << decrytpedText << endl;

  return 0;
}