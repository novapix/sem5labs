#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class FloydWarshall {
 private:
  int V;
  vector<vector<int>> dist;
  vector<char> vertexLabels;

 public:
  FloydWarshall(int vertices) {
    V = vertices;
    dist.resize(V, vector<int>(V, INT_MAX));
    vertexLabels.resize(V);
    for (int i = 0; i < V; i++) {
      vertexLabels[i] = 'A' + i;
      dist[i][i] = 0;
    }
  }

  void addEdge(int u, int v, int weight) { dist[u][v] = weight; }

  void floydWarshall() {
    for (int k = 0; k < V; k++) {
      cout << "Stage " << k + 1 << " (Considering " << vertexLabels[k]
           << " as intermediate):\n";
      for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
              dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
      printSolution();
    }
  }

  void printSolution() {
    printf("All-Pairs Shortest Paths:\n");

    printf("%4s", "");
    for (int i = 0; i < V; i++) {
      printf("%-4c", vertexLabels[i]);
    }
    printf("\n");

    for (int i = 0; i < V; i++) {
      printf("%-4c", vertexLabels[i]);
      for (int j = 0; j < V; j++) {
        if (dist[i][j] == INT_MAX)
          printf("%-4s", "INF");
        else
          printf("%-4d", dist[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
};

int main() {
  FloydWarshall graph(7);
  vector<vector<int>> adjMatrix = {
      {0, 2, INT_MAX, 6, INT_MAX, 1, INT_MAX},  // A
      {2, 0, 3, 8, INT_MAX, INT_MAX, 5},        // B
      {INT_MAX, 3, 0, INT_MAX, 7, INT_MAX, 4},  // C
      {6, 8, INT_MAX, 0, 9, 3, INT_MAX},        // D
      {INT_MAX, INT_MAX, 7, 9, 0, 6, 2},        // E
      {1, INT_MAX, INT_MAX, 3, 6, 0, 8},        // F
      {INT_MAX, 5, 4, INT_MAX, 2, 8, 0}         // G
  };

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (adjMatrix[i][j] != INT_MAX && i != j) {
        graph.addEdge(i, j, adjMatrix[i][j]);
      }
    }
  }

  graph.floydWarshall();
  // graph.printSolution();
  return 0;
}
