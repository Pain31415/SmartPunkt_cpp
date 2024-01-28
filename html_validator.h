#ifndef HTML_VALIDATOR_H
#define HTML_VALIDATOR_H

#include <string>
#include <memory>

class HTMLValidator {
private:
    std::string filepath;
    std::shared_ptr<std::string> content;

public:
    HTMLValidator();

    bool loadFile(const std::string& path);
    void validate();
};

#endif // HTML_VALIDATOR_H