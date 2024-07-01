#pragma once

#include "algorithms.hpp"
#include "data_structures.hpp"

template <typename T>
class Matrix : public DataStructures<T>
{
public:
    Matrix();
    virtual ~Matrix();

    void addData(T data) override;    // Assume T is a row of the matrix
    bool search(const T& value) const override;
    size_t size() const override;
    void dummyFunction(const DataStructures<T>& other) override;
};