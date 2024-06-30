#pragma once

#include <list>
#include <vector>

#include "algorithms.hpp"
#include "data_structures.hpp"

template <typename T>
class Graph : public DataStructures<T>
{
public:
    Graph();
    virtual ~Graph();

    void addNode(const std::list<T>& edges);
    const std::list<T>& getEdges(size_t nodeIndex) const;
    size_t size() const;

    void addData(T data) override {
        // Implementation for adding data to the graph
    }

    void dummyFunction(const DataStructures<T>& other) override {
        // Implementation to process two DataStructures
        // Example operation
    }
};