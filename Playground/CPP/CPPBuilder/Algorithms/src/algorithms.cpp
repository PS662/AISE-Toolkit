// algorithms.cpp
#include "algorithms.hpp"

Algorithms::Algorithms(string str) : name(str) {}

Algorithms::~Algorithms() {
    for (Algorithms* child : children) {
        delete child;
    }
}

vector<string> Algorithms::depthFirstSearch_Variant1(vector<string>* array) {
    if (children.empty())
        return {};

    array->push_back(name);

    for (Algorithms* child : children) {
        vector<Algorithms*> stack;
        stack.push_back(child);

        while (!stack.empty()) {
            Algorithms* node = stack.back();
            stack.pop_back();
            array->push_back(node->name);

            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push_back(*it);
            }
        }
    }
    return *array;
}

vector<string> Algorithms::depthFirstSearch_Variant2(vector<string>* array) {
    array->push_back(name);
    for (Algorithms* child : children) {
        child->depthFirstSearch_Variant2(array);
    }
    return *array;
}

Algorithms* Algorithms::addChild(string name) {
    Algorithms* child = new Algorithms(name);
    children.push_back(child);
    return this;
}
