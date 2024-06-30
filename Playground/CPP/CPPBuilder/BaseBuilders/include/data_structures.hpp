#pragma once
#include "base_object.hpp"

template <typename T>
class DataStructures : virtual public BaseObject<DataStructures<T>>
{
public:
    virtual void addData(T data) {}
    virtual bool search(const T &value) const { return false; }
    virtual size_t size() const { return -1; }
    virtual void dummyFunction(const DataStructures<T> &other) {}
    virtual ~DataStructures() {}
};