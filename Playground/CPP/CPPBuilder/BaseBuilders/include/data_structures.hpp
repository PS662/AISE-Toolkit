#pragma once
#include "base_object.hpp"

template <typename T>
class DataStructures : virtual public BaseObject<DataStructures<T>> {
public:
    virtual void addData(T data) = 0;
    virtual bool search(const T& value) const = 0;
    virtual size_t size() const = 0;
    virtual void dummyFunction(const DataStructures<T>& other) = 0;
    virtual ~DataStructures() {}
};