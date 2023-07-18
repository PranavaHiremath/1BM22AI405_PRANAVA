#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

// Function to add an edge to the graph
void addEdge(Graph& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Prim's algorithm implementation
int primMST(const Graph& graph, int startVertex) {
    int numVertices = graph.size();

    // Priority queue to store vertices with their key values
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(numVertices, INT_MAX); // Key values used to pick minimum weight edge
    vector<bool> inMST(numVertices, false); // To represent whether a vertex is included in MST

    int totalWeight = 0; // Total weight of MST

    // Insert startVertex into the priority queue and initialize its key value as 0
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with the minimum key value
        pq.pop();

        inMST[u] = true; // Include the vertex in MST

        // Iterate over all adjacent vertices of u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and weight of (u,v) is smaller than current key value of v
            if (!inMST[v] && weight < key[v]) {
                // Update key value and insert v into the priority queue
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Calculate the total weight of MST
    for (int i = 0; i < numVertices; ++i) {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    int startVertex = 0; // Choose any vertex as the starting vertex

    int minimumWeight = primMST(graph, startVertex);

    cout << "Minimum weight of the MST: " << minimumWeight << endl;

    return 0;
}
