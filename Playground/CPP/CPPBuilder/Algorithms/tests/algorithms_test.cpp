// dfs_tests.cpp
#include "dfs.hpp"
#include <gtest/gtest.h>

TEST(DFSTest, DepthFirstSearch) {
    DFS root("root");
    root.addChild("child1")->addChild("grandchild1");
    root.addChild("child2");

    vector<string> traversal;
    root.depthFirstSearch_Variant2(&traversal);

    vector<string> expected = {"root", "child1", "grandchild1", "child2"};
    EXPECT_EQ(traversal, expected);
}