#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_C 0
#define S_C 2
#define I_C 1
#define D_C 1

typedef struct {
  int cost, op;
} Cell;

Cell minOp(Cell a, Cell b, Cell c) {
  return (a.cost <= b.cost && a.cost <= c.cost) ? a
         : (b.cost <= c.cost)                   ? b
                                                : c;
}

void printMatrix(Cell **dp, int m, int n, char *s1, char *s2) {
  printf("\nDP Matrix (costs):\n   ");
  for (int j = 0; j < n; j++) printf("%2c ", s2[j]);
  printf("\n  ");
  for (int j = 0; j <= n; j++) printf("%2d ", dp[0][j].cost);
  for (int i = 1; i <= m; i++) {
    printf("\n%c ", s1[i - 1]);
    for (int j = 0; j <= n; j++) printf("%2d ", dp[i][j].cost);
  }
  printf("\n");
}

void editDistanceTrace(char *s1, char *s2) {
  int m = strlen(s1), n = strlen(s2);
  Cell **dp = (Cell **)malloc((m + 1) * sizeof(Cell *));
  for (int i = 0; i <= m; i++) dp[i] = (Cell *)malloc((n + 1) * sizeof(Cell));

  for (int i = 0; i <= m; i++) dp[i][0] = (Cell){i * D_C, 3};
  for (int j = 0; j <= n; j++) dp[0][j] = (Cell){j * I_C, 2};
  dp[0][0].op = 0;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = (s1[i - 1] == s2[j - 1])
                     ? (Cell){dp[i - 1][j - 1].cost + M_C, 0}
                     : minOp((Cell){dp[i - 1][j - 1].cost + S_C, 1},
                             (Cell){dp[i][j - 1].cost + I_C, 2},
                             (Cell){dp[i - 1][j].cost + D_C, 3});

  printMatrix(dp, m, n, s1, s2);

  printf("\nEdit Sequence (in reverse):\n");
  for (int i = m, j = n; i > 0 || j > 0;)
    if (dp[i][j].op == 0)
      printf("Match '%c' at position %d, cost: %d\n", s1[--i], i + 1, M_C), j--;
    else if (dp[i][j].op == 1)
      printf("Substitute '%c' with '%c' at position %d, cost: %d\n", s1[--i],
             s2[--j], i + 1, S_C);
    else if (dp[i][j].op == 2)
      printf("Insert '%c' at position %d, cost: %d\n", s2[--j], j + 1, I_C);
    else if (dp[i][j].op == 3)
      printf("Delete '%c' at position %d, cost: %d\n", s1[--i], i + 1, D_C);

  printf("\nTotal cost: %d\n", dp[m][n].cost);

  for (int i = 0; i <= m; i++) free(dp[i]);
  free(dp);
}

int main() {
  char s1[] = "spake", s2[] = "park";
  printf("Transforming '%s' to '%s':\n", s1, s2);
  editDistanceTrace(s1, s2);
  return 0;
}