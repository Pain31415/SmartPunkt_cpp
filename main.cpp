#include <iostream>
#include "smart_pointers.h"

int main() {
    // UniquePtr testing
    UniquePtr<int> uniquePtr(new int(5));
    std::cout << "Value through UniquePtr: " << *uniquePtr << std::endl;

    // SharedPtr testing
    SharedPtr<int> sharedPtr1(new int(10));
    SharedPtr<int> sharedPtr2 = sharedPtr1;
    std::cout << "Value through SharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "Value through SharedPtr2: " << *sharedPtr2 << std::endl;
    std::cout << "Use count for SharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "Use count for SharedPtr2: " << sharedPtr2.use_count() << std::endl;

    return 0;
}