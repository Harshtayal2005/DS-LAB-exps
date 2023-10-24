#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& graph, int vertex, vector<bool>& visited) {
    cout << vertex << " ";
    visited[vertex] = true;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
    }
}

void DFSTraversal(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    DFS(graph, start, visited);
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0}, {1}, {1}};
    cout << "DFS Traversal starting from vertex 0: ";
    DFSTraversal(graph, 0);
    cout << endl;
    return 0;
}