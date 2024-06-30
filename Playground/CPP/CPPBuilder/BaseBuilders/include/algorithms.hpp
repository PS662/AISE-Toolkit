#pragma once

#include "base_object.hpp"
#include "data_structures.hpp"

template <typename T>
class Algorithms : virtual public BaseObject<Algorithms<T>>
{
public:
    Algorithms();
    virtual ~Algorithms();

    virtual void dummyAlgoProcess(DataStructures<T>& ds1, DataStructures<T>& ds2);
};
