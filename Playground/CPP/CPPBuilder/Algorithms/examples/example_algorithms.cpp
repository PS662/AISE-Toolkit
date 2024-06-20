// example_dfs.cpp
#include "dfs.hpp"
#include <iostream>

int main() {
    DFS root("root");
    root.addChild("child1")->addChild("grandchild1");
    root.addChild("child2");

    vector<string> traversal;
    root.depthFirstSearch_Variant2(&traversal);

    for (const string& name : traversal) {
        std::cout << name << std::endl;
    }

    return 0;
}
