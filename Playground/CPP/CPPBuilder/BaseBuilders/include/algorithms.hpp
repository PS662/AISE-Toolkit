#pragma once

#include "base_object.hpp"
#include "data_structures.hpp"
#include "matrix.hpp"

template <typename T>
class Algorithms : virtual public BaseObject<Algorithms<T>>
{
public:
    Algorithms();
    virtual ~Algorithms();

    virtual void dummyAlgoProcess(DataStructures<T>& ds1, DataStructures<T>& ds2);
    virtual void GEMM(const Matrix<std::vector<T>>& A, const Matrix<std::vector<T>>& B, Matrix<std::vector<T>>& C);
};
