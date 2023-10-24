#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0}, {1}, {1}};
    cout << "BFS Traversal starting from vertex 0: ";
    BFS(graph, 0);
    cout << endl;
    return 0;
}
