#include "algorithms.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Algorithms root;
    root.addChild("child1").addChild("grandchild1");
    root.addChild("child2");

    std::vector<std::string> traversal;
    root.depthFirstSearch_Variant1(traversal);

    for (const auto& name : traversal) {
        std::cout << name << std::endl;
    }

    return 0;
}
