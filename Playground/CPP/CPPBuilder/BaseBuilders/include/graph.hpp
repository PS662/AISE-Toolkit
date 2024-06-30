#pragma once

#include "algorithms.hpp"
#include "data_structures.hpp"

template <typename T>
class Graph : public DataStructures<T>
{
public:
    Graph();
    virtual ~Graph();

    void addData(T data) override;
    bool search(const T& value) const override;
    size_t size() const override;
    void dummyFunction(const DataStructures<T>& other) override;
};