#include <iostream>
using namespace std;

void fibonacciTailRec(int n, int a = 0, int b = 1) {
  if (n < 0) return;
  cout << a << " ";
  fibonacciTailRec(n - 1, b, a + b);
}

int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;

  cout << "Fibonacci series up to " << n << " terms: ";
  fibonacciTailRec(n);

  cout << endl;
  return 0;
}
