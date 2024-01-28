#include <iostream>
#include "html_validator.h"

int main() {
    HTMLValidator validator;
    std::string filepath;

    std::cout << "Enter the HTML file path: ";
    std::cin >> filepath;

    if (validator.loadFile(filepath)) {
        validator.validate();
    }
    else {
        std::cerr << "Failed to load the HTML file." << std::endl;
    }

    return 0;
}