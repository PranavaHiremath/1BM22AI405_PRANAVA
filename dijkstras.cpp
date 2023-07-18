#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node and its distance from the source
struct Node {
    int vertex;
    int distance;
};

// Dijkstra's algorithm implementation
void dijkstra(vector<vector<int>>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, INT_MAX);  // Initialize distances with infinity
    vector<bool> visited(numVertices, false);     // Mark all nodes as unvisited
    priority_queue<Node, vector<Node>, greater<Node>> pq;  // Min-heap priority queue

    distances[source] = 0;  // Distance from source to itself is 0
    pq.push({source, 0});   // Add source node to the priority queue

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] != 0) {  // If there is an edge between u and v
                int distanceThroughU = distances[u] + graph[u][v];
                if (distanceThroughU < distances[v]) {
                    distances[v] = distanceThroughU;
                    pq.push({v, distances[v]});
                }
            }
        }
    }

    // Print the shortest distances from the source to all nodes
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << "\t" << distances[i] << "\n";
    }
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);  // Find shortest paths starting from node 0

    return 0;
}
