#include "algorithms.hpp"
#include "graph.hpp"
#include <gtest/gtest.h>
#include <list>

TEST(AlgorithmsTest, dummyFunction)
{
    Graph<int> graph;

    Algorithms<int> algo;
    std::cout << "Starting dummy algo test output:" << std::endl;
    algo.dummyAlgoProcess(graph, graph);
}