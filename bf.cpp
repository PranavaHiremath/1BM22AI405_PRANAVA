#include <iostream>
#include <queue>
#include <vector>

void BFS(const std::vector<std::vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    std::vector<bool> visited(numNodes, false);
    std::queue<int> queue;

    visited[startNode] = true;
    queue.push(startNode);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        std::cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;

    // Create a graph as an adjacency list
    std::vector<std::vector<int>> graph(numNodes);

    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    std::cout << "Enter the edges (source and destination):" << std::endl;
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        std::cin >> src >> dest;
        graph[src].push_back(dest);
    }

    int startNode;
    std::cout << "Enter the starting node: ";
    std::cin >> startNode;

    std::cout << "Nodes reachable from node " << startNode << " using BFS: ";
    BFS(graph, startNode);

    return 0;
}

