#include "algorithms.hpp"
#include <memory>
#include <vector>
#include <string>

class AlgorithmsImpl : public BaseObjectImpl {
public:
    std::string name;
    std::vector<std::shared_ptr<AlgorithmsImpl>> children;

    explicit AlgorithmsImpl(std::string str = "") : name(std::move(str)) {}

    void addChild(std::string name) {
        children.push_back(std::make_shared<AlgorithmsImpl>(name));
    }

    std::vector<std::string> depthFirstSearch_Variant1(std::vector<std::string>& array) {
        array.push_back(name); // pre-order
        for (const auto& child : children) {
            child->depthFirstSearch_Variant1(array);
        }
        return array;
    }

    std::vector<std::string> depthFirstSearch_Variant2(std::vector<std::string>& array) {
        for (const auto& child : children) {
            child->depthFirstSearch_Variant2(array);
        }
        array.push_back(name); // post-order
        return array;
    }
};

Algorithms::Algorithms() { m_pImpl = std::make_shared<AlgorithmsImpl>(""); }
Algorithms::~Algorithms() {}

std::vector<std::string> Algorithms::depthFirstSearch_Variant1(std::vector<std::string>& array) {
    return std::dynamic_pointer_cast<AlgorithmsImpl>(m_pImpl)->depthFirstSearch_Variant1(array);
}

std::vector<std::string> Algorithms::depthFirstSearch_Variant2(std::vector<std::string>& array) {
    return std::dynamic_pointer_cast<AlgorithmsImpl>(m_pImpl)->depthFirstSearch_Variant2(array);
}

Algorithms& Algorithms::addChild(std::string name) {
    std::dynamic_pointer_cast<AlgorithmsImpl>(m_pImpl)->addChild(name);
    return *this;
}
