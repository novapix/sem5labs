#include <iostream>
#include <cstdio>
using namespace std;

struct Step {
  int a, b, q, r, x, y;
};

int extendedGCD(int a, int b, int &x, int &y) {
  Step steps[100];
  int stepCount = 0;

  int x0 = 1, y0 = 0, x1 = 0, y1 = 1;

  while (a != 0) {
    int q = b / a;
    int r = b % a;

    int x2 = x0 - q * x1;
    int y2 = y0 - q * y1;

    steps[stepCount++] = {a, b, q, r, x1, y1};

    b = a, a = r;
    x0 = x1, y0 = y1;
    x1 = x2, y1 = y2;
  }

  x = x0, y = y0;

  printf("\nIteration Table:\n");
  printf("a\tb\tq\tr\tx\ty\n");

  for (int i = 0; i < stepCount; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", steps[i].a, steps[i].b, steps[i].q,
           steps[i].r, steps[i].x, steps[i].y);
  }

  return b;
}

int main() {
  int a, b, x, y;

  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);

  int gcd = extendedGCD(a, b, x, y);

  printf("GCD: %d\n", gcd);
  printf("Coefficients x and y: %d, %d\n", x, y);

  return 0;
}
