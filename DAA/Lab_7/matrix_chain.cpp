#include <limits.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printDPTable(const vector<vector<int>> &m, int n) {
  cout << "Current DP Table:\n";
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (i > j)
        cout << setw(7) << " - ";
      else
        cout << setw(7) << (m[i][j] == INT_MAX ? "INF" : to_string(m[i][j]));
    }
    cout << endl;
  }
  cout << "-------------------------------\n";
}

void printOptimalParenthesis(int i, int j, const vector<vector<int>> &bracket,
                             int &matrixCount) {
  if (i == j) {
    cout << "M" << matrixCount++;
    return;
  }

  cout << "(";
  printOptimalParenthesis(i, bracket[i][j], bracket, matrixCount);
  printOptimalParenthesis(bracket[i][j] + 1, j, bracket, matrixCount);
  cout << ")";
}

void matrixChainOrder(const vector<int> &p) {
  int n = p.size();
  vector<vector<int>> m(n, vector<int>(n, 0));
  vector<vector<int>> bracket(n, vector<int>(n, 0));

  for (int L = 2; L < n; L++) {
    for (int i = 1; i < n - L + 1; i++) {
      int j = i + L - 1;
      m[i][j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

        if (cost < m[i][j]) {
          m[i][j] = cost;
          bracket[i][j] = k;
        }
      }
    }

    cout << "After evaluating chain length " << L << ":\n";
    printDPTable(m, n);
  }

  cout << "Minimum number of multiplications required: " << m[1][n - 1] << endl;

  int matrixCount = 1;
  cout << "Optimal Parenthesization: ";
  printOptimalParenthesis(1, n - 1, bracket, matrixCount);
  cout << endl;
}

int main() {
  vector<int> p = {4, 10, 3, 12, 20, 7};  // dimensions

  matrixChainOrder(p);

  return 0;
}
