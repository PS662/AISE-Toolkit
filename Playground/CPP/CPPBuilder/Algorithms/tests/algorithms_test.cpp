#include "algorithms.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(AlgorithmsTest, DepthFirstSearch) {
    Algorithms root;
    root.addChild("child1").addChild("grandchild1");
    root.addChild("child2");

    std::vector<std::string> traversal;
    root.depthFirstSearch_Variant1(traversal);

    std::vector<std::string> expected = {"", "child1", "grandchild1", "child2"};
    EXPECT_EQ(traversal, expected);
}
