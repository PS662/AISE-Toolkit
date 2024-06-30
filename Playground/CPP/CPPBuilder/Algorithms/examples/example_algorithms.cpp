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

    graph.addNode({1});    // Node 0 is connected to Node 1
    graph.addNode({2});    // Node 1 is connected to Node 2
    graph.addNode({0, 3}); // Node 2 is connected to Node 0 and Node 3
    graph.addNode({3});    // Node 3 has a self-loop

    Algorithms<int> algo;
    algo.dummyAlgoProcess(graph, graph);

    return 0;
}
