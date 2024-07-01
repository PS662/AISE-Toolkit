#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#include "matrix.hpp"

template <typename T>
class MatrixImpl : public BaseObjectImpl
{
public:
    friend class Matrix<T>;
    MatrixImpl() = default;
    virtual ~MatrixImpl() = default;

protected:
    using ContainerType = std::vector<T>;
    ContainerType matrixData;
    size_t cols = 0;

    void addRow(const T& row)
    {
        if (!matrixData.empty() && row.size() != cols)
        {
            throw std::runtime_error("Row size does not match the existing matrix column size");
        }
        cols = row.size();
        matrixData.push_back(row);
    }

    const T& getRow(size_t rowIndex) const
    {
        return matrixData.at(rowIndex);
    }

    size_t size() const
    {
        return matrixData.size() * (cols ? cols : 1);
    }

    bool search(const T& value) const
    {
        return std::find(matrixData.begin(), matrixData.end(), value) != matrixData.end();
    }

    void dummyFunction(const DataStructures<T>& other)
    {
        std::cout << "Processing Matrix with another data structure." << std::endl;
    }
};

// this-> needed because of template
template <typename T>
Matrix<T>::Matrix()
{
    this->m_pImpl = std::make_shared<MatrixImpl<T>>();
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
void Matrix<T>::addData(T data)
{
    auto impl = std::dynamic_pointer_cast<MatrixImpl<T>>(this->m_pImpl);
    if (impl)
    {
        impl->addRow(data);
    }
}

template <typename T>
bool Matrix<T>::search(const T& value) const
{
    auto impl = std::dynamic_pointer_cast<MatrixImpl<T>>(this->m_pImpl);
    if (impl)
    {
        return impl->search(value);
    }
    return false;
}

template <typename T>
size_t Matrix<T>::size() const
{
    auto impl = std::dynamic_pointer_cast<MatrixImpl<T>>(this->m_pImpl);
    if (impl)
    {
        return impl->size();
    }
    return 0;
}

template <typename T>
void Matrix<T>::dummyFunction(const DataStructures<T>& other)
{
    auto impl = std::dynamic_pointer_cast<MatrixImpl<T>>(this->m_pImpl);
    if (impl)
    {
        impl->dummyFunction(other);
    }
}

template class Matrix<std::vector<int>>;     // Explicit instantiation
template class MatrixImpl<std::vector<int>>; // Ensure the implementation class is also instantiated.
