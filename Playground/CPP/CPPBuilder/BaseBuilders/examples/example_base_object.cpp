#include <iostream>
#include "base_object.hpp"

class ExampleDerived : public BaseObject<ExampleDerived> {
public:
    void greet() const {
        std::cout << "Hello from ExampleDerived!" << std::endl;
    }
};

int main() {
    auto instance = ExampleDerived::GetInstance();
    instance->greet();
    return 0;
}
