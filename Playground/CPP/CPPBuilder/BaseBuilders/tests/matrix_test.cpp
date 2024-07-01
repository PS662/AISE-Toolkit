#include "matrix.hpp"
#include <gtest/gtest.h>

class MatrixTest : public ::testing::Test {
protected:
    Matrix<std::vector<int>> matrix;

    void SetUp() override {
        // Pre-populate the matrix with some data
        matrix.addData({1, 2, 3});
        matrix.addData({4, 5, 6});
        matrix.addData({7, 8, 9});
    }
};

TEST_F(MatrixTest, AddData) {
    matrix.addData({10, 11, 12});
    EXPECT_EQ(12, matrix.size());  // 4 rows * 3 columns
}

TEST_F(MatrixTest, SearchElementFound) {
    EXPECT_TRUE(matrix.search({1, 2, 3}));  // Row was added in SetUp
}

TEST_F(MatrixTest, SearchElementNotFound) {
    EXPECT_FALSE(matrix.search({5, 6, 7}));  // Row was never added
}

TEST_F(MatrixTest, CheckSize) {
    EXPECT_EQ(9, matrix.size());  // 3 rows * 3 columns
}

TEST_F(MatrixTest, DummyFunction) {
    Matrix<std::vector<int>> otherMatrix;
    otherMatrix.addData({10, 11, 12});
    // As dummyFunction does not alter the matrix, we simply invoke it to ensure it can be called without errors
    matrix.dummyFunction(otherMatrix);
    EXPECT_EQ(9, matrix.size());  // Ensure size remains unchanged
    EXPECT_EQ(3, otherMatrix.size());  // otherMatrix should have 1 row * 3 columns
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
