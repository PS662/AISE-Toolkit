#include "algorithms.hpp"
#include <memory>
#include <vector>
#include <list>
#include <iostream>

class AlgorithmsImpl : public BaseObjectImpl {
public:
    void depthFirstSearch(const Graph<int>& graph, size_t startNode, std::vector<bool>& visited) {
        // Simple DFS implementation
        visited[startNode] = true;
        std::cout << startNode << " ";  // Output the node

        for (int adj : graph.getEdges(startNode)) {
            if (!visited[adj]) {
                depthFirstSearch(graph, adj, visited);
            }
        }
    }
};

template <typename T>
Algorithms<T>::Algorithms() {
    this->m_pImpl = std::make_shared<AlgorithmsImpl>();  // Correct instantiation
}

template <typename T>
Algorithms<T>::~Algorithms() {
}

template <typename T>
void Algorithms<T>::depthFirstSearch(const Graph<T>& graph, size_t startNode) {
    std::vector<bool> visited(graph.size(), false);  // Tracking visited nodes
    std::dynamic_pointer_cast<AlgorithmsImpl>(this->m_pImpl)->depthFirstSearch(graph, startNode, visited);
}

// Explicit instantiation for common types used
template class Algorithms<int>;
