#pragma once

#include "base_object.hpp"
#include <vector>
#include <string>

class AlgorithmsImpl;

class Algorithms : public BaseObject<Algorithms> {
    friend class AlgorithmsImpl;
public:
    Algorithms();
    ~Algorithms();

    std::vector<std::string> depthFirstSearch_Variant1(std::vector<std::string>& array);
    std::vector<std::string> depthFirstSearch_Variant2(std::vector<std::string>& array);
    Algorithms& addChild(std::string name);
};