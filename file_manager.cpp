#include "file_manager.h"
#include <iostream>
#include <algorithm>

FileManager::FileManager() : content(std::make_shared<std::string>("")) {}

bool FileManager::loadFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << path << std::endl;
        return false;
    }

    std::string line;
    *content = "";
    while (std::getline(file, line)) {
        *content += line + "\n";
    }

    filepath = path;
    file.close();
    return true;
}

void FileManager::displayMenu() {
    std::cout << "File Management Menu:\n"
        << "1. Search for a string\n"
        << "2. Replace a string\n"
        << "3. Display file content\n"
        << "4. Reverse file content\n"
        << "5. Exit\n";
}

void FileManager::searchAndDisplay(const std::string& searchStr) {
    size_t found = content->find(searchStr);
    if (found != std::string::npos) {
        std::cout << "String found at position " << found << std::endl;
    }
    else {
        std::cout << "String not found." << std::endl;
    }
}

void FileManager::replaceString(const std::string& oldStr, const std::string& newStr) {
    size_t pos = content->find(oldStr);
    while (pos != std::string::npos) {
        content->replace(pos, oldStr.length(), newStr);
        pos = content->find(oldStr, pos + newStr.length());
    }
}

void FileManager::reverseContent() {
    std::reverse(content->begin(), content->end());
}

const std::shared_ptr<std::string>& FileManager::getContent() const {
    return content;
}