#include <iostream>
#include "file_manager.h"

int main() {
    FileManager fileManager;
    std::string filepath;

    std::cout << "Enter the file path: ";
    std::cin >> filepath;

    if (fileManager.loadFile(filepath)) {
        std::cout << "File loaded successfully!" << std::endl;

        int choice;
        std::string searchString, replaceString;

        do {
            fileManager.displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                std::cout << "Enter the string to search: ";
                std::cin >> searchString;
                fileManager.searchAndDisplay(searchString);
                break;
            case 2:
                std::cout << "Enter the string to replace: ";
                std::cin >> searchString;
                std::cout << "Enter the new string: ";
                std::cin >> replaceString;
                fileManager.replaceString(searchString, replaceString);
                break;
            case 3:
                std::cout << *fileManager.getContent() << std::endl;
                break;
            case 4:
                fileManager.reverseContent();
                std::cout << "Content reversed successfully." << std::endl;
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 5);
    }
    else {
        std::cerr << "Failed to load the file." << std::endl;
    }

    return 0;
}