#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Dijkstra {
 private:
  int V;
  vector<vector<int>> graph;
  vector<char> vertexLabels;

 public:
  Dijkstra(int vertices) {
    V = vertices;
    graph.resize(V, vector<int>(V, 0));
    vertexLabels.resize(V);
    for (int i = 0; i < V; i++) {
      vertexLabels[i] = 'A' + i;
    }
  }

  void addEdge(int u, int v, int weight) { graph[u][v] = weight; }

  int minDistance(vector<int> &dist, vector<bool> &visited) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
      if (!visited[v] && dist[v] <= min) {
        min = dist[v];
        min_index = v;
      }
    }

    return min_index;
  }

  void printPath(vector<int> &parent, int j) {
    if (parent[j] == -1) return;

    printPath(parent, parent[j]);
    cout << " -> " << vertexLabels[j];
  }

  void printSolution(vector<int> &dist, vector<int> &parent, int src) {
    cout << "Shortest Paths from Source Vertex " << vertexLabels[src] << ":"
         << endl;
    for (int i = 0; i < V; i++) {
      if (i != src) {
        printf("Path to vertex %c (Distance: %d): %c", vertexLabels[i], dist[i],
               vertexLabels[src]);
        printPath(parent, i);
        cout << endl;
      }
    }
  }

  void dijkstraSP(int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    dist[src] = 0;

    cout << "Dijkstra's Algorithm Execution:" << endl;
    cout << "Starting Vertex: " << vertexLabels[src] << endl;

    for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, visited);

      if (u == -1) continue;

      visited[u] = true;
      cout << "Visiting vertex: " << vertexLabels[u] << endl;

      for (int v = 0; v < V; v++) {
        if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX &&
            dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
          parent[v] = u;
          printf("Updating distance to vertex %c: %d -> %d\n", vertexLabels[v],
                 dist[u], dist[v]);
        }
      }
    }

    printSolution(dist, parent, src);
  }

  void printGraph() {
    cout << "Graph Representation (Directed):" << endl;
    cout << "  ";
    for (int i = 0; i < V; i++) {
      cout << vertexLabels[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
      cout << vertexLabels[i] << " ";
      for (int j = 0; j < V; j++) {
        printf("%d ", graph[i][j]);
      }
      cout << endl;
    }
  }
};

int main() {
  int n = 7;
  Dijkstra graph(n);

  vector<vector<int>> adjMatrix = {
      {0, 2, 0, 6, 0, 1, 0},  // A -> B (2), A -> D (6), A -> F (1)
      {0, 0, 3, 0, 0, 0, 5},  // B -> C (3), B -> G (5)
      {0, 0, 0, 0, 7, 0, 4},  // C -> E (7), C -> G (4)
      {0, 0, 0, 0, 9, 3, 0},  // D -> E (9), D -> F (3)
      {0, 0, 0, 0, 0, 6, 2},  // E -> F (6), E -> G (2)
      {0, 0, 0, 0, 0, 0, 8},  // F -> G (8)
      {3, 0, 0, 0, 0, 6, 0}   // G -> A (3), G -> F (6)
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (adjMatrix[i][j] != 0) {
        graph.addEdge(i, j, adjMatrix[i][j]);
      }
    }
  }

  graph.dijkstraSP(6);

  return 0;
}
