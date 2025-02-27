#include <climits>
#include <iostream>
#include <queue>
#include <vector>

// EXPERIMENTAL XD

using namespace std;

const int V = 7;

void primMST(const vector<vector<int>>& graph) {
  vector<int> parent(V);
  vector<int> key(V, INT_MAX);
  vector<bool> mstSet(V, false);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  key[0] = 0;
  parent[0] = -1;

  pq.push({0, 0});  // (key, vertex)

  while (!pq.empty()) {
    int u = pq.top().second;  // Get the vertex with the smallest key value
    pq.pop();

    // If the vertex is already included in MST skip
    if (mstSet[u]) continue;

    mstSet[u] = true;  // Mark the vertex as included in MST

    cout << "Selected Vertex: " << u;

    int minWeight = INT_MAX;
    int minAdjVertex = -1;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < minWeight) {
        minWeight = graph[u][v];
        minAdjVertex = v;
      }
    }

    if (minAdjVertex != -1) {
      cout << " with adjacent vertex: " << minAdjVertex << " (Edge " << u << "-"
           << minAdjVertex << ") with weight " << minWeight << endl;
    }

    for (int v = 0; v < V; v++) {
      if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
        key[v] = graph[u][v];
        parent[v] = u;
        pq.push({key[v], v});  // Push the updated vertex with its new key
      }
    }
  }

  int totalWeight = 0;
  for (int i = 1; i < V; i++) {
    totalWeight += graph[i][parent[i]];
  }
  cout << "\nCost of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
  vector<vector<int>> graph = {
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
