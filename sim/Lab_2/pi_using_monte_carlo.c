#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED time(NULL)

int main() {
  int i, count, n;
  double x, y, z, pi;
  srand(SEED);
  printf("Enter the value of n:");
  scanf("%d", &n);
  count = 0;
  for (i = 0; i < n; ++i) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = (x * x) + (y * y);
    if (z <= 1) count++;
  }
  pi = (double)count / n * 4;
  printf("Approximation of PI = %g\n", pi);
  return 0;
}