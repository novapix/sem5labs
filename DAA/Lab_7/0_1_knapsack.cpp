#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
  string name;
  int weight;
  int val;
};

typedef vector<Item> ItemList;
typedef vector<vector<int>> Mat2D;

void printDPTable(const Mat2D& dp) {
  for (int i = 0; i < dp.size(); ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      printf("%4d", dp[i][j]);
    }
    printf("\n");
  }
}

int knapsack(int W, ItemList& items, int n, Mat2D& dp) {
  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      } else if (items[i - 1].weight <= w) {
        dp[i][w] = max(items[i - 1].val + dp[i - 1][w - items[i - 1].weight],
                       dp[i - 1][w]);
        // printf(
        //     "Decision at dp[%d][%d]: Take item %s (weight %d, value %d), new
        //     " "value: %d\n", i, w, items[i - 1].name.c_str(), items[i -
        //     1].weight, items[i - 1].val, dp[i][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
        // printf(
        //     "Decision at dp[%d][%d]: Don't take item %s, value remains:
        //     %d\n", i, w, items[i - 1].name.c_str(), dp[i][w]);
      }
    }
    if (i > 0) {
      printf("\nDP Table after item %s is processed:\n",
             items[i - 1].name.c_str());
      printDPTable(dp);
    }
  }
  return dp[n][W];
}

void findSelectedItems(int n, int W, const Mat2D& dp, const ItemList& items) {
  int w = W;
  cout << endl << "Selected items: ";
  for (int i = n; i > 0; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      printf("%s ", items[i - 1].name.c_str());
      w -= items[i - 1].weight;
    }
  }
  cout << endl;
}

int main() {
  int W = 5;
  ItemList items = {{"A", 2, 3}, {"B", 3, 4}, {"C", 4, 5}, {"D", 5, 6}};
  int n = items.size();

  Mat2D dp(n + 1, vector<int>(W + 1, 0));

  cout << "Solving the 0/1 Knapsack problem" << endl;
  int max_value = knapsack(W, items, n, dp);

  printf("\nMaximum value in knapsack = %d\n", max_value);

  findSelectedItems(n, W, dp, items);

  return 0;
}
