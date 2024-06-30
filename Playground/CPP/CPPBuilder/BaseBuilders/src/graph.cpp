#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#include "graph.hpp"
template <typename T>
class GraphImpl : public BaseObjectImpl
{
public:
    friend class Graph<T>;
    GraphImpl() = default;
    virtual ~GraphImpl() = default;

protected:
    using ContainerType = std::vector<std::list<T>>;
    ContainerType adjacencyList;

    void addNode(const std::list<T> &edges)
    {
        adjacencyList.push_back(edges);
    }

    const std::list<T> &getEdges(size_t nodeIndex) const
    {
        return adjacencyList.at(nodeIndex);
    }

    size_t size() const
    {
        return adjacencyList.size();
    }

    bool search(const T &value) const
    {
        for (const auto &edges : adjacencyList)
        {
            if (std::find(edges.begin(), edges.end(), value) != edges.end())
            {
                return true;
            }
        }
        return false;
    }
    
    void dummyFunction(const DataStructures<T> &other)
    {
        std::cout << "Processing Graph with another data structure." << std::endl;
    }
};

// this-> needed because of template
template <typename T>
Graph<T>::Graph()
{
    this->m_pImpl = std::make_shared<GraphImpl<T>>();
}

template <typename T>
Graph<T>::~Graph()
{
}

template <typename T>
void Graph<T>::addData(T data)
{
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl)
    {
        std::list<T> singleElementList = {data};
        impl->addNode(singleElementList);
    }
}

template <typename T>
bool Graph<T>::search(const T &value) const
{
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl)
    {
        return impl->search(value);
    }
    return false;
}

template <typename T>
size_t Graph<T>::size() const
{
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl)
    {
        return impl->size();
    }
    return 0;
}

template <typename T>
void Graph<T>::dummyFunction(const DataStructures<T> &other)
{
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl)
    {
        impl->dummyFunction(other);
    }
}
template class Graph<int>;     // Explicit instantiation
template class GraphImpl<int>; // Ensure the implementation class is also instantiated.