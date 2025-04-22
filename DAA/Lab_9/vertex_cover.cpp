#include <iostream>
#include <vector>
using namespace std;

class Graph {
 private:
  int V;
  vector<vector<int>> adjMatrix;

 public:
  Graph(int V, const vector<vector<int>>& edges) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
    for (size_t i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adjMatrix[u][v] = 1;
      adjMatrix[v][u] = 1;
    }
  }

  void vertexCover() {
    vector<bool> visited(V, false);
    vector<bool> inCover(V, false);

    cout << "Step-by-step decisions:\n";
    for (int u = 0; u < V; u++) {
      for (int v = u + 1; v < V; v++) {
        if (adjMatrix[u][v] == 1 && !visited[u] && !visited[v]) {
          cout << "Edge (" << u << ", " << v
               << ") is uncovered. Selecting vertex " << u
               << " to cover this edge.\n";
          visited[u] = true;
          inCover[u] = true;
          break;
        }
      }
    }

    cout << "\nFinal Vertex Cover: ";
    for (int v = 0; v < V; v++) {
      if (inCover[v]) {
        cout << v << " ";
      }
    }
    cout << endl;
  }
};

int main() {
  int V = 7;

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}, {5, 6}};

  Graph g(V, edges);

  g.vertexCover();

  return 0;
}
