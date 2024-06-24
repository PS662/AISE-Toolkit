#pragma once
#include "base_object.hpp"

template<typename T, typename Derived>
class DataStructures : public BaseObject {
public:
    virtual void dummyFunction() const = 0;
    virtual ~DataStructures() {}

    void addData(T data) {
        static_cast<Derived*>(this)->addDataImpl(data);
    }
};
