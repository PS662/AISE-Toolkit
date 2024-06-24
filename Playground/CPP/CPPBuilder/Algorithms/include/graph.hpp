#pragma once

#include <vector>
#include <list>

template<typename T>
class Graph {
public:
    using ContainerType = std::vector<std::list<T>>;

private:
    ContainerType data;

public:
    // Adds a node with edges
    void addNode(const std::list<T>& edges) {
        data.push_back(edges);
    }

    const ContainerType& getContainer() const {
        return data;
    }

    // Access specific node's edges
    const std::list<T>& getEdges(size_t nodeIndex) const {
        return data.at(nodeIndex);
    }

    size_t size() const {
        return data.size();
    }
};
