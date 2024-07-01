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

TEST(AlgorithmsTest, GEMMFunction)
{
    Matrix<std::vector<int>> A;
    Matrix<std::vector<int>> B;
    Matrix<std::vector<int>> C;

    A.addData({1, 2, 3});
    A.addData({4, 5, 6});
    B.addData({7, 8});
    B.addData({9, 10});
    B.addData({11, 12});

    Algorithms<int> algo;
    algo.GEMM(A, B, C);

    EXPECT_EQ(C.size(), 4); // 2 rows * 2 columns
    EXPECT_EQ(C.search({58, 64}), true); // Check if one of the results is correct
    EXPECT_EQ(C.search({139, 154}), true); // Check if another result is correct
}