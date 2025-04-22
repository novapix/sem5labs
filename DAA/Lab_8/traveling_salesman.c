#include <stdio.h>
#include <stdlib.h>

#define N 4
#define INF 99999

int cost[N][N] = {{0, 10, 15, 20}, {5, 0, 9, 10}, {6, 13, 0, 12}, {8, 8, 9, 0}};
int dp[1 << N][N], J[1 << N][N];

void printSet(int S) {
  printf("{");
  for (int i = 1, first = 1; i < N; i++)
    if (S & (1 << i)) printf("%s%d", first ? "" : ",", i + 1), first = 0;
  printf("}");
}

void tsp() {
  int S, i, j, k, allVisited = (1 << N) - 1;

  for (S = 0; S < (1 << N); S++)
    for (i = 0; i < N; i++) dp[S][i] = INF;

  printf("Travelling Salesman Problem\n\nBase cases:\n");
  for (i = 1; i < N; i++) {
    dp[1 << i][i] = cost[i][0];
    printf("cost(%d, {}, 1) = C_{1,%d} = %d\n", i + 1, i + 1, cost[i][0]);
  }

  printf("\nComputing costs for |S| = 1:\n");
  for (i = 1; i < N; i++)
    for (j = 1; j < N; j++)
      if (i != j) {
        S = (1 << i) | (1 << j);
        dp[S][i] = cost[i][j] + dp[1 << j][j];
        J[S][i] = j;
        printf(
            "cost(%d, {%d}, 1) = C_{%d,%d} + cost(%d, {}, 1) = %d + %d = %d\n",
            i + 1, j + 1, i + 1, j + 1, j + 1, cost[i][j], dp[1 << j][j],
            dp[S][i]);
      }

  printf("\nComputing costs for |S| = 2:\n");
  for (i = 1; i < N; i++)
    for (j = 1; j < N - 1; j++)
      for (k = j + 1; k < N; k++)
        if (i != j && i != k) {
          S = (1 << i) | (1 << j) | (1 << k);
          int S_minus_i = S & ~(1 << i),
              via =
                  cost[i][j] + dp[S_minus_i][j] < cost[i][k] + dp[S_minus_i][k]
                      ? j
                      : k;
          dp[S][i] = cost[i][via] + dp[S_minus_i][via];
          J[S][i] = via;
          printf(
              "cost(%d, {%d,%d}, 1) = C_{%d,%d} + cost(%d, {%d}, 1) = %d + %d "
              "= "
              "%d\n",
              i + 1, j + 1, k + 1, i + 1, via + 1, via + 1,
              (via == j ? k : j) + 1, cost[i][via], dp[S_minus_i][via],
              dp[S][i]);
        }

  S = allVisited & ~(1 << 0);
  printf("\nComputing costs for |S| = 3:\ncost(1, ");
  printSet(S);
  printf(", 1) = min {");
  int minCost = INF, last = -1;
  for (i = 1; i < N; i++) {
    int costTotal = cost[0][i] + dp[S][i];
    printf("%sC_{1,%d} + cost(%d, ", i == 1 ? "" : ", ", i + 1, i + 1);
    printSet(S & ~(1 << i));
    printf(", 1)");
    if (costTotal < minCost) minCost = costTotal, last = i;
  }
  printf("}\n= min {");
  for (i = 1; i < N; i++)
    printf("%s%d + %d", i == 1 ? "" : ", ", cost[0][i], dp[S][i]);
  printf("} = %d\n", minCost);

  printf("\nOptimal tour: 1");
  int path[N + 1] = {0}, idx = 1, curr = last;
  path[0] = 1;
  while (S) {
    path[idx++] = curr + 1;
    int next = J[S][curr];
    S &= ~(1 << curr);
    curr = next;
    if (!S) break;
  }
  path[idx++] = 1;
  for (i = 1; i < idx; i++) printf(" -> %d", path[i]);
  printf(" (length %d)\n", minCost);
}

int main() {
  tsp();
  return 0;
}