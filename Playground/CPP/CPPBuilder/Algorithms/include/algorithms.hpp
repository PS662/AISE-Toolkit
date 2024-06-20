#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * @class Algorithms
 * @brief Implements various algorithms.
 *
 * This class allows the creation of a tree structure and performing different algorithms on it.
 */
class Algorithms {
public:
    string name;
    vector<Algorithms*> children;

    explicit Algorithms(string str);

    // Variants of depthFirstSearch
    vector<string> depthFirstSearch_Variant1(vector<string>* array);
    vector<string> depthFirstSearch_Variant2(vector<string>* array);

    Algorithms* addChild(string name);

    // Destructor
    ~Algorithms();
};
;