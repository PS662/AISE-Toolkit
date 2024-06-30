#pragma once
#include "base_object.hpp"

template <typename T>
class DataStructures : virtual public BaseObject<DataStructures<T>>
{
public:
    virtual void addData(T data) = 0;
    virtual void dummyFunction(const DataStructures<T>& other) = 0;
    virtual ~DataStructures() {}
};
