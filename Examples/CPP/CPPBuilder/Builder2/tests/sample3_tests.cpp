#include <gtest/gtest.h>
#include "sample3.hpp"

TEST(SampleTest, FunctionalityTest) {
    Sample2 sample;
    // Add test expectations
    EXPECT_EQ(sample.display_message(), "Hello from Sample class3!"); // Adjust as necessary
}
