#include "html_validator.h"
#include <iostream>
#include <fstream>

HTMLValidator::HTMLValidator() : content(std::make_shared<std::string>("")) {}

bool HTMLValidator::loadFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << path << std::endl;
        return false;
    }

    std::string line;
    *content = "";
    while (std::getline(file, line)) {
        *content += line;
    }

    file.close();
    return true;
}

void HTMLValidator::validate() {
    int openTags = 0;
    for (char c : *content) {
        if (c == '<') {
            openTags++;
        }
        else if (c == '>') {
            if (openTags == 0) {
                std::cout << "Invalid HTML file: Extra closing tag encountered." << std::endl;
                return;
            }
            openTags--;
        }
    }

    if (openTags > 0) {
        std::cout << "Invalid HTML file: Not all tags are closed." << std::endl;
    }
    else {
        std::cout << "Valid HTML file." << std::endl;
    }
}