#include "algorithms.hpp"
#include <memory>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
class AlgorithmsImpl : public BaseObjectImpl
{
public:
    void dummyAlgoProcess(DataStructures<T>& ds1, DataStructures<T>& ds2)
    {
        std::cout << "Algo Impl dummy";
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

// Explicit instantiation for common types used
template class Algorithms<int>;
template class AlgorithmsImpl<int>; // Ensure the implementation class is also instantiated.
