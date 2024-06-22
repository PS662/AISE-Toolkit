#pragma once

#include "base_object.hpp"
#include "data_structures.hpp"

class AlgorithmsImpl;

template <typename T>
class Algorithms : public BaseObject<Algorithms<T>> {
public:
    Algorithms();
    virtual ~Algorithms();

    void depthFirstSearch(const DataStructure<T>& graph, size_t startNode);
};
