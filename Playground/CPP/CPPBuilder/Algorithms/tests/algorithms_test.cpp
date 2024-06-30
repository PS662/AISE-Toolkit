#include "algorithms.hpp"
#include "graph.hpp"
#include <gtest/gtest.h>
#include <list>

TEST(AlgorithmsTest, dummyFunction)
{
    Graph<int> graph;
    // Setting up a simple graph
    graph.addNode({1});    // Node 0 is connected to Node 1
    graph.addNode({2});    // Node 1 is connected to Node 2
    graph.addNode({0, 3}); // Node 2 is connected to Node 0 and Node 3
    graph.addNode({3});    // Node 3 has a self-loop

    Algorithms<int> algo;
    std::cout << "Starting dummy algo test output:" << std::endl;
    algo.dummyAlgoProcess(graph, graph);
}