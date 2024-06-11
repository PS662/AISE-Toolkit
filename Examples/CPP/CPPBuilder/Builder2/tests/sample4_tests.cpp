#include <gtest/gtest.h>
#include "sample1.hpp"

TEST(SampleTest, FunctionalityTest) {
    Sample sample;
    // Add test expectations
    EXPECT_EQ(sample.display_message(), "Hello from sample1 class4!"); // Adjust as necessary
}
