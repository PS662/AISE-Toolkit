#include "graph.hpp"
#include <iostream>

int main() {
    Graph<int> graph;

    // Adding data to the graph
    graph.addData(1);
    graph.addData(2);
    graph.addData(3);

    // Displaying the size of the graph
    std::cout << "Current size of graph: " << graph.size() << std::endl;

    // Searching for an element
    int searchElement = 2;
    bool found = graph.search(searchElement);
    std::cout << "Element " << searchElement << (found ? " is found" : " is not found") << " in the graph." << std::endl;

    // Example of using dummyFunction
    Graph<int> otherGraph;
    otherGraph.addData(4);
    graph.dummyFunction(otherGraph);

    return 0;
}
