#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Document.h"

class Editor
{
public:
    std::vector<string> fileText;
    Document doc;

    Editor() = default;
    Editor(string file);
    void loop(); //wait for input from the user and active the suitable method in Document
    vector<string> split(string text, bool caseSen);
    bool writeFile(string reader);
};
