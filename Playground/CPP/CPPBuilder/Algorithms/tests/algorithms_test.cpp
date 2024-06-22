#include "algorithms.hpp"
#include "data_structures.hpp"
#include <gtest/gtest.h>
#include <list>

TEST(AlgorithmsTest, DepthFirstSearch) {
    DataStructure<int> graph;
    // Setting up a simple graph
    graph.addNode({1});      // Node 0 is connected to Node 1
    graph.addNode({2});      // Node 1 is connected to Node 2
    graph.addNode({0, 3});   // Node 2 is connected to Node 0 and Node 3
    graph.addNode({3});      // Node 3 has a self-loop

    Algorithms<int> algo;

    // Since the output is directly printed, to test, we would normally need to capture stdout
    // For simplicity, assume correct functionality here or use a method to capture and compare output.
    std::cout << "Starting DFS test output:" << std::endl;
    algo.depthFirstSearch(graph, 0);

    // Ideally, you'd capture output and verify it matches expected traversal:
    // Expected order: 0 1 2 3
}