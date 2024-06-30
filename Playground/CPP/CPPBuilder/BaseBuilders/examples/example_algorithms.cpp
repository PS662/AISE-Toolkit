#include "algorithms.hpp"
#include "graph.hpp"
#include <iostream>
#include <list>

int main()
{
    Graph<int> graph;
    // Simulating a graph: adjacency list representation
    // Graph structure:
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0, 3
    // 3 -> 3 (self-loop)

    Algorithms<int> algo;
    algo.dummyAlgoProcess(graph, graph);

    return 0;
}
