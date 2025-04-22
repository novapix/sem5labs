#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long powerMod(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;
  while (exp > 0) {
    printf("Exponent: %lld, Base: %lld, Result: %lld\n", exp, base, result);
    if (exp % 2 == 1) {
      result = (result * base) % mod;
      printf("  -> Multiplied: %lld\n", result);
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

bool millerRabinTest(long long d, long long n) {
  long long a = 2 + rand() % (n - 4);
  printf("Random base (a): %lld\n", a);
  long long x = powerMod(a, d, n);
  printf("Initial x: %lld\n", x);
  if (x == 1 || x == n - 1) return true;
  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;
    printf("  Squared x: %lld, d doubled: %lld\n", x, d);
    if (x == 1) return false;
    if (x == n - 1) return true;
  }
  return false;
}

bool isPrime(long long n, int iterations) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;
  long long d = n - 1;
  printf("Value of d: %lld\n", d);
  while (d % 2 == 0) d /= 2;
  for (int i = 0; i < iterations; i++) {
    printf("Iteration %d:\n", i + 1);
    if (!millerRabinTest(d, n)) return false;
  }
  return true;
}

int main() {
  long long num;
  int k = 2;
  printf("Enter a number to check for primality: ");
  scanf("%lld", &num);
  if (isPrime(num, k))
    printf("%lld is probably prime.\n", num);
  else
    printf("%lld is composite.\n", num);
  return 0;
}