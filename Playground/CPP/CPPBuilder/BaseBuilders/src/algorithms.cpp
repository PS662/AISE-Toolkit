#include "algorithms.hpp"
#include <memory>
#include <vector>
#include <list>
#include <iostream>

#ifdef SYCL
#include <CL/sycl.hpp>
#endif
template<typename T>
class AlgorithmsImpl : public BaseObjectImpl
{
public:
    void dummyAlgoProcess(DataStructures<T>& ds1, DataStructures<T>& ds2)
    {
        std::cout << "Algo Impl dummy";
    }

    void GEMM(const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C)
    {
#ifdef SYCL
        auto implA = std::dynamic_pointer_cast<MatrixImpl<T>>(A.m_pImpl);
        auto implB = std::dynamic_pointer_cast<MatrixImpl<T>>(B.m_pImpl);
        auto implC = std::dynamic_pointer_cast<MatrixImpl<T>>(C.m_pImpl);

        if (!implA || !implB || !implC) {
            throw std::runtime_error("Invalid matrix implementations");
        }

        size_t M = implA->matrixData.size();
        size_t K = implA->cols;
        size_t N = implB->cols;

        if (K != implB->matrixData.size()) {
            throw std::runtime_error("Matrix dimensions are not compatible for GEMM");
        }

        implC->matrixData.resize(M, std::vector<T>(N, 0));
        implC->cols = N;

        sycl::queue q;

        {
            sycl::buffer<T, 2> aBuffer(implA->matrixData.data()->data(), sycl::range<2>(M, K));
            sycl::buffer<T, 2> bBuffer(implB->matrixData.data()->data(), sycl::range<2>(K, N));
            sycl::buffer<T, 2> cBuffer(implC->matrixData.data()->data(), sycl::range<2>(M, N));

            q.submit([&](sycl::handler& h) {
                auto a = aBuffer.template get_access<sycl::access::mode::read>(h);
                auto b = bBuffer.template get_access<sycl::access::mode::read>(h);
                auto c = cBuffer.template get_access<sycl::access::mode::write>(h);

                h.parallel_for(sycl::range<2>(M, N), [=](sycl::id<2> id) {
                    size_t row = id[0];
                    size_t col = id[1];
                    T sum = 0;
                    for (size_t k = 0; k < K; ++k) {
                        sum += a[row][k] * b[k][col];
                    }
                    c[row][col] = sum;
                });
            });
        }
        q.wait();
#endif
    }
};

template <typename T>
Algorithms<T>::Algorithms()
{
    this->m_pImpl = std::make_shared<AlgorithmsImpl<T>>(); // Correct instantiation with template
}

template <typename T>
Algorithms<T>::~Algorithms()
{
}

template <typename T>
void Algorithms<T>::dummyAlgoProcess(DataStructures<T>& ds1, DataStructures<T>& ds2) {
    std::cout << "Algo Interface dummy" << std::endl;
    auto impl = std::dynamic_pointer_cast<AlgorithmsImpl<T>>(this->m_pImpl);
    if (impl) {
        impl->dummyAlgoProcess(ds1, ds2);
    }
}

template <typename T>
void Algorithms<T>::GEMM(const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C) {
    auto impl = std::dynamic_pointer_cast<AlgorithmsImpl<T>>(this->m_pImpl);
    if (impl) {
        impl->GEMM(A, B, C);
    }
}

// Explicit instantiation for common types used
template class Algorithms<int>;
template class AlgorithmsImpl<int>; // Ensure the implementation class is also instantiated.
