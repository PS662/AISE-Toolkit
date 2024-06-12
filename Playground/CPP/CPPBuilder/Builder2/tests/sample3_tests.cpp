#include <sstream>
#include <iostream>

#include <gtest/gtest.h>

#include "sample3.hpp"

TEST(SampleTest, FunctionalityTest) {
    Sample3 sample;

    // Redirect std::cout
    std::stringstream buffer;
    std::streambuf *prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    sample.display_message();

    // Restore original buffer before assertion
    std::cout.rdbuf(prevcoutbuf);

    // Check the output
    EXPECT_EQ(buffer.str(), "Hello from Sample class3!\n"); // Adjust as necessary, include '\n' if your message ends with std::endl
}