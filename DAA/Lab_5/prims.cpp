#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

const int V = 7;

int minKey(const vector<int> &key, const vector<bool> &mstSet) {
  int min = INT_MAX;
  int min_index;

  for (int v = 0; v < V; v++) {
    if (!mstSet[v] && key[v] < min) {
      min = key[v];
      min_index = v;
    }
  }

  return min_index;
}

void primMST(const Graph &graph) {
  vector<int> parent(V);
  vector<int> key(V, INT_MAX);
  vector<bool> mstSet(V, false);

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int u = minKey(key, mstSet);
    mstSet[u] = true;

    cout << "Selected Vertex: " << u << " with adjacent vertices: ";

    for (int v = 0; v < V; v++) {
      if (graph[u][v] != INT_MAX && !mstSet[v]) {
        cout << v << " ";
      }
    }
    cout << endl;

    int minAdjVertex = -1;
    int minWeight = INT_MAX;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < minWeight) {
        minWeight = graph[u][v];
        minAdjVertex = v;
      }
    }

    if (minAdjVertex != -1) {
      printf("Selecting adjacent vertex: %d (Edge %d-%d) with weight %d\n",
             minAdjVertex, u, minAdjVertex, minWeight);
    }

    for (int v = 0; v < V; v++) {
      if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }
  int totalWeight = 0;

  for (int i = 1; i < V; i++) {
    totalWeight += graph[i][parent[i]];
  }
  cout << "Cost of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
  Graph graph = {
      {INT_MAX, 2, INT_MAX, 6, INT_MAX, 1, INT_MAX},  // Vertex 0
      {2, INT_MAX, 3, 8, INT_MAX, INT_MAX, 5},        // Vertex 1
      {INT_MAX, 3, INT_MAX, INT_MAX, 7, INT_MAX, 4},  // Vertex 2
      {6, 8, INT_MAX, INT_MAX, 9, 3, INT_MAX},        // Vertex 3
      {INT_MAX, INT_MAX, 7, 9, INT_MAX, 6, 2},        // Vertex 4
      {1, INT_MAX, INT_MAX, 3, 6, INT_MAX, 8},        // Vertex 5
      {INT_MAX, 5, 4, INT_MAX, 2, 8, INT_MAX}         // Vertex 6
  };

  primMST(graph);

  return 0;
}
