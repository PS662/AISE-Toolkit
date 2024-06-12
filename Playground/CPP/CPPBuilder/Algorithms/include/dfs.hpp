/**
 * @file dfs.hpp
 * @brief Depth-First Search class definition
 *
 * Defines a class for performing depth-first search on a tree structure.
 */
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;


/**
 * @class DFS
 * @brief Implements depth-first search algorithms.
 *
 * This class allows the creation of a tree and performing depth-first search in various ways.
 */
class DFS {
public:
    string name;
    vector<DFS*> children;

    explicit DFS(string str);

    // Variants of depthFirstSearch
    vector<string> depthFirstSearch_Variant1(vector<string> *array);
    vector<string> depthFirstSearch_Variant2(vector<string> *array);

    DFS* addChild(string name);

    // Destructor
    ~DFS();
};