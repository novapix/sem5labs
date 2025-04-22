#include <stdio.h>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int modInverse(int a, int m) {
  int m0 = m, x = 1, y = 0, t;
  while (a > 1) {
    int q = a / m;
    t = m, m = a % m, a = t;
    t = y, y = x - q * y, x = t;
  }
  return x < 0 ? x + m0 : x;
}

int areCoprime(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (gcd(arr[i], arr[j]) != 1) return 0;
  return 1;
}

void solveCRT(int a[], int n[], int size) {
  long long M = 1, x = 0, M_i[3];
  int M_i_inv[3];

  for (int i = 0; i < size; i++) M *= n[i];
  printf("M = %lld\n\n", M);

  if (!areCoprime(n, size)) {
    printf("Error: Moduli are not coprime!\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    M_i[i] = M / n[i];
    M_i_inv[i] = modInverse(M_i[i], n[i]);
  }

  printf("M1 = M/m1 = %lld, M2 = M/m2 = %lld, M3 = M/m3 = %lld\n", M_i[0],
         M_i[1], M_i[2]);

  printf("M1^-1 = %d M2^-1 = %d and M3^-1 = %d\n", M_i_inv[0], M_i_inv[1],
         M_i_inv[2]);

  for (int i = 0; i < size; i++) {
    x += (long long)a[i] * M_i[i] * M_i_inv[i];
  }
  x = x % M;

  printf("\nx = (a1*M1*M1^-1 + a2*M2*M2^-1 + a3*M3*M3^-1) mod M\n\n");
  printf("= (%d*%lld*%d + %d*%lld*%d + %d*%lld*%d) mod %lld = %lld\n", a[0],
         M_i[0], M_i_inv[0], a[1], M_i[1], M_i_inv[1], a[2], M_i[2], M_i_inv[2],
         M, x);
}

int main() {
  int a[] = {1, 4, 6}, n[] = {3, 5, 7}, size = 3;
  printf("Solving the system of congruences:\n");
  for (int i = 0; i < size; i++) {
    printf("x = %d (mod %d)\n", a[i], n[i]);
  }
  for (int i = 0; i < size; i++) printf("a%d = %d ", i + 1, a[i]);
  printf("\n");
  for (int i = 0; i < size; i++) printf("m%d = %d ", i + 1, n[i]);
  printf("\n");

  // printf("\na1 = %d, a2 = %d, a3 = %d\n", a[0], a[1], a[2]);
  // printf("m1 = %d, m2 = %d, m3 = %d\n\n", n[0], n[1], n[2]);

  solveCRT(a, n, size);
  return 0;
}