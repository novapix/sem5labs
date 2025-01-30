#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int x) {
  int sum = 0;
  for (int i = 0; i < x; i++) {
    sum += rand() % 6 + 1;
  }
  return sum;
}

double calculateProbability(int x, int z, int trials) {
  int favorableOutcomes = 0;

  for (int i = 0; i < trials; i++) {
    int sum = rollDice(x);
    if (sum == z) {
      favorableOutcomes++;
    }
  }
  return (double)favorableOutcomes / trials;
}

int main() {
  srand(time(NULL));
  int x, z, trials;
  x = 3, z = 18, trials = 1;
  // printf("Enter the number of dice: ");
  // scanf("%d", &x);
  // printf("Enter the desired sum: ");
  // scanf("%d", &z);
  // printf("Enter the number of trials: ");
  // scanf("%d", &trials);

  double probability = calculateProbability(x, z, trials);
  printf("The probability of getting a sum of %d with %d dice is: %.6f\n", z, x,
         probability);

  return 0;
}
