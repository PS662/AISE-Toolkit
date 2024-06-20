// algorithms_test.cpp
#include "algorithms.hpp"
#include <gtest/gtest.h>

TEST(AlgorithmsTest, DepthFirstSearchVariant1) {
    Algorithms root("root");
    root.addChild("child1")->addChild("grandchild1");
    root.addChild("child2");

    vector<string> traversal;
    root.depthFirstSearch_Variant1(&traversal);

    vector<string> expected = {"root", "child1", "grandchild1", "child2"};
    EXPECT_EQ(traversal, expected);
}

TEST(AlgorithmsTest, DepthFirstSearchVariant2) {
    Algorithms root("root");
    root.addChild("child1")->addChild("grandchild1");
    root.addChild("child2");

    vector<string> traversal;
    root.depthFirstSearch_Variant2(&traversal);

    vector<string> expected = {"root", "child1", "grandchild1", "child2"};
    EXPECT_EQ(traversal, expected);
}
