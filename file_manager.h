#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <memory>

class FileManager {
private:
    std::string filepath;
    std::shared_ptr<std::string> content;

public:
    FileManager();

    bool loadFile(const std::string& path);
    void displayMenu();
    void searchAndDisplay(const std::string& searchStr);
    void replaceString(const std::string& oldStr, const std::string& newStr);
    void reverseContent();
    const std::shared_ptr<std::string>& getContent() const;
};

#endif // FILE_MANAGER_H