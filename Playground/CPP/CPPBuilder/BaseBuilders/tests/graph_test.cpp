#include "graph.hpp"
#include <gtest/gtest.h>
#include <thread>
#include <vector>

class GraphTest : public ::testing::Test {
protected:
    std::shared_ptr<Graph<int>> graph;

    void SetUp() override {
        // Get the singleton instance of Graph
        graph = std::static_pointer_cast<Graph<int>>(Graph<int>::GetInstance());
        // Clear the graph for clean test conditions
        // Assuming clear method is available or managed by addData to overwrite/reset if needed
        // Pre-populate the graph with some data
        graph->addData(1);
        graph->addData(2);
        graph->addData(3);
    }
};

TEST_F(GraphTest, SingletonInstance) {
    auto instance1 = std::static_pointer_cast<Graph<int>>(Graph<int>::GetInstance());
    auto instance2 = std::static_pointer_cast<Graph<int>>(Graph<int>::GetInstance());
    EXPECT_EQ(instance1.get(), instance2.get());

    auto newInstance = std::static_pointer_cast<Graph<int>>(Graph<int>::GetInstance(true));
    EXPECT_NE(instance1.get(), newInstance.get());

    // Test searching across instances
    newInstance->addData(4);
    EXPECT_TRUE(newInstance->search(4));
    EXPECT_FALSE(instance1->search(4)); // Should not find 4 in the original singleton instance
}

TEST_F(GraphTest, AddData) {
    graph->addData(4);
    EXPECT_EQ(4, graph->size());  // Expecting 4 elements after adding one more
}

TEST_F(GraphTest, SearchElementFound) {
    EXPECT_TRUE(graph->search(1));  // Element 1 was added in SetUp
}

TEST_F(GraphTest, SearchElementNotFound) {
    EXPECT_FALSE(graph->search(5));  // Element 5 was never added
}

TEST_F(GraphTest, CheckSize) {
    EXPECT_EQ(3, graph->size());  // 3 elements were added in SetUp
}

TEST_F(GraphTest, DummyFunction) {
    auto otherGraph = std::static_pointer_cast<Graph<int>>(Graph<int>::GetInstance(true));
    otherGraph->addData(5);
    // As dummyFunction does not alter the graph, we simply invoke it to ensure it can be called without errors
    graph->dummyFunction(*otherGraph);
    EXPECT_EQ(3, graph->size());  // Ensure size remains unchanged
    EXPECT_EQ(1, otherGraph->size());  // otherGraph should have 1 element
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
