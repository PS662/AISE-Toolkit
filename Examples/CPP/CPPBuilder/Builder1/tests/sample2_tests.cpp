#include <gtest/gtest.h>
#include "sample2.hpp"

TEST(SampleTest, FunctionalityTest) {
    Sample2 sample;
    // Add test expectations
    EXPECT_EQ(sample.display_message(), "Hello from Sample class2!"); // Adjust as necessary
}
