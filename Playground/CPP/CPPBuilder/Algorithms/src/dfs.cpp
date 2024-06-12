// dfs.cpp
#include "dfs.hpp"

DFS::DFS(string str) : name(str) {}

DFS::~DFS() {
    for (DFS* child : children) {
        delete child;
    }
}

vector<string> DFS::depthFirstSearch_Variant1(vector<string> *array) {
    if (children.empty())
        return {};

    array->push_back(name);

    for (DFS* child : children) {
        vector<DFS*> stack;
        stack.push_back(child);

        while (!stack.empty()) {
            DFS* node = stack.back();
            stack.pop_back();
            array->push_back(node->name);

            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push_back(*it);
            }
        }
    }
    return *array;
}

vector<string> DFS::depthFirstSearch_Variant2(vector<string> *array) {
    array->push_back(name);
    for (DFS* child : children) {
        child->depthFirstSearch_Variant2(array);
    }
    return *array;
}

DFS* DFS::addChild(string name) {
    DFS* child = new DFS(name);
    children.push_back(child);
    return this;
}
