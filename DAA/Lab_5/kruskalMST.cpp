#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int src, dest, weight;
};

class Kruskal {
 private:
  int V;
  vector<vector<int>> graph;
  vector<Edge> edges;

 public:
  Kruskal(int vertices) {
    V = vertices;
    graph.resize(V, vector<int>(V, 0));
  }

  void addEdge(int u, int v, int weight) {
    if (weight != 0) {
      graph[u][v] = weight;
      graph[v][u] = weight;
      edges.push_back({u, v, weight});
    }
  }

  int find(vector<int> &parent, int i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent, parent[i]);
  }

  void Union(vector<int> &parent, vector<int> &rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }

  void customSwap(Edge &a, Edge &b) {
    Edge temp = a;
    a = b;
    b = temp;
  }

  void bubbleSort() {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (edges[j].weight > edges[j + 1].weight) {
          customSwap(edges[j], edges[j + 1]);
        }
      }
    }
  }

  void printGraph(const vector<Edge> &result) {
    int totalWeight = 0;
    int s = static_cast<int>(result.size());
    cout << "Minimum Spanning Tree Edges:" << endl;
    // for (auto &edge : result) {
    //   printf("Edge %d-%d with weight %d\n", edge.src, edge.dest,
    //   edge.weight); totalWeight += edge.weight;
    // }
    for (int i = 0; i < s; ++i) {
      printf("Edge %d-%d with weight %d\n", result[i].src, result[i].dest,
             result[i].weight);
      totalWeight += result[i].weight;
    }

    cout << "Cost of the Minimum Spanning Tree: " << totalWeight << endl;
  }

  void kruskalMST() {
    bubbleSort();

    vector<int> parent(V, -1);
    vector<int> rank(V, 0);
    vector<Edge> result;

    cout << "Traversing Edges:" << endl;
    for (auto &edge : edges) {
      cout << "Checking Edge: " << edge.src << "-" << edge.dest
           << " with weight " << edge.weight << endl;
      int x = find(parent, edge.src);
      int y = find(parent, edge.dest);

      if (x != y) {
        result.push_back(edge);
        // cout << "Selected Edge: " << edge.src << "-" << edge.dest
        //      << " with weight " << edge.weight << endl;
        printf("Selecting Edge: %d - %d with weight %d\n", edge.src, edge.dest,
               edge.weight);
        Union(parent, rank, x, y);
      } else {
        cout << "Edge: " << edge.src << "-" << edge.dest
             << " forms a cycle and is discarded." << endl;
      }
    }
    printGraph(result);
  }
};

int main() {
  Kruskal graph(7);

  vector<vector<int>> adjMatrix = {
      {0, 2, 0, 6, 0, 1, 0},  // v0
      {2, 0, 3, 8, 0, 0, 5},  // v1
      {0, 3, 0, 0, 7, 0, 4},  // v2
      {6, 8, 0, 0, 9, 3, 0},  // v3
      {0, 0, 7, 9, 0, 6, 2},  // v4
      {1, 0, 0, 3, 6, 0, 8},  // v5
      {0, 5, 4, 0, 2, 8, 0}   // v6
  };

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (adjMatrix[i][j] != 0 && i < j) {
        graph.addEdge(i, j, adjMatrix[i][j]);
      }
    }
  }

  graph.kruskalMST();

  return 0;
}
