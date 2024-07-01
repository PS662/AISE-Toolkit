#include <iostream>
#include <list>
#include <vector>

#include "algorithms.hpp"
#include "graph.hpp"
#include "matrix.hpp"

int doGraph()
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

int doGEMM()
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

    std::cout << "Matrix C (Result of GEMM):" << std::endl;
    for (size_t i = 0; i < C.size(); i++) {
        auto impl = std::dynamic_pointer_cast<MatrixImpl<std::vector<int>>>(C.m_pImpl);
        for (auto elem : impl->getRow(i)) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int main()
{
    int ret = -1;

    ret = doGraph();
    ret = doGEMM();

    return ret;
}
