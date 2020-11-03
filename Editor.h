#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Document.h"

class Editor
{
public:
    void loop(); //wait for input from the user and active the suitable method in Document
    vector<string> split(string text, bool caseSen);
};
