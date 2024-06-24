#pragma once

#include "base_object.hpp"
#include "graph.hpp"

class AlgorithmsImpl;

template <typename T>
class Algorithms : public BaseObject<Algorithms<T>>
{
public:
    Algorithms();
    virtual ~Algorithms();

    void depthFirstSearch(const Graph<T> &graph, size_t startNode);
};
