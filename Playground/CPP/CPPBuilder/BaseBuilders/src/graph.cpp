#include "graph.hpp"

template<typename T>
class GraphImpl : public BaseObjectImpl {
public:
    using ContainerType = std::vector<std::list<T>>;
    ContainerType adjacencyList;

    void addNode(const std::list<T>& edges) {
        adjacencyList.push_back(edges);
    }

    const std::list<T>& getEdges(size_t nodeIndex) const {
        return adjacencyList.at(nodeIndex);
    }

    size_t size() const {
        return adjacencyList.size();
    }
};

template <typename T>
Graph<T>::Graph()
{
    this->m_pImpl = std::make_shared<GraphImpl<T>>();
}

template <typename T>
Graph<T>::~Graph()
{
}

template<typename T>
void Graph<T>::addNode(const std::list<T>& edges) {
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl) {
        impl->addNode(edges);
    }
}

template<typename T>
const std::list<T>& Graph<T>::getEdges(size_t nodeIndex) const {
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl) {
        return impl->getEdges(nodeIndex);
    }
    throw std::runtime_error("Invalid operation: Graph implementation not available.");
}

template<typename T>
size_t Graph<T>::size() const {
    auto impl = std::dynamic_pointer_cast<GraphImpl<T>>(this->m_pImpl);
    if (impl) {
        return impl->size();
    }
    return 0;
}

template class Graph<int>;  // Explicit instantiation
template class GraphImpl<int>;  // Ensure the implementation class is also instantiated.