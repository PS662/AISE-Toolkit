#include "matrix.hpp"
#include <iostream>
#include <vector>

int main() {
    Matrix<std::vector<int>> matrix;

    // Adding data to the matrix
    matrix.addData({1, 2, 3});
    matrix.addData({4, 5, 6});
    matrix.addData({7, 8, 9});

    // Displaying the size of the matrix
    std::cout << "Current size of matrix: " << matrix.size() << std::endl;

    // Searching for a row
    std::vector<int> searchRow = {4, 5, 6};
    bool found = matrix.search(searchRow);
    std::cout << "Row {4, 5, 6}" << (found ? " is found" : " is not found") << " in the matrix." << std::endl;

    // Example of using dummyFunction
    Matrix<std::vector<int>> otherMatrix;
    otherMatrix.addData({10, 11, 12});
    matrix.dummyFunction(otherMatrix);

    return 0;
}
