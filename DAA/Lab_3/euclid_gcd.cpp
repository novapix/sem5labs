#include <iostream>
using namespace std;

int gcd(int a, int b) {
  cout << "a =" + to_string(a) + " b = " + to_string(b) << endl;
  if (b == 0) return a;

  return gcd(b, a % b);
}

int main() {
  int a, b;
  cout << "Enter two numbers whose gcd you want to find: ";
  cin >> a >> b;
  cout << "The GCD of " + to_string(a) + " and " + to_string(b) + " = " +
              to_string(gcd(a, b))
       << endl;
  return 0;
}