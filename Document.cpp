#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Document.h"

using namespace std;

Document::Document()
{
    index = lines.begin();
}

void Document::jumpToLine(int line)
{
    if (line > lines.size() - 1)
    {
        return;
    }
    index = lines.begin();
    for (int i = 1; i != line; ++i)
    {
        ++index;
    }
}
int Document::getVectorLen()
{
    return lines.size();
}

void Document::mergeLines()
{

    // vector<string>::iterator it = lines.begin();
    if (getIndex() != lines.size())
    {
        (*index) += (*(++index));
        lines.erase(index);
    }
}
void Document::deleteLine()
{
    vector<string>::iterator it = lines.begin();
    it = index;
    index++;
    lines.erase(it);
}

int Document::getIndex()
{
    vector<string>::iterator it = lines.begin();
    int count = 1;
    while (it != index)
    {
        count++;
        it++;
    }
    return count;
}
void Document::addLines(string c)
{
    string str = "";
    bool keepWrite = true;
    while (keepWrite)
    {
        getline(cin, str);
        if (str == ".")
        {
            keepWrite = false;
        }
        else
        {
            if (index != lines.end())
            {
                if (c == "+")
                {
                    index++;
                }
                else{
                    c="+";
                }
                index = lines.insert(index, str);
            }
            else
            {
                index = lines.insert(lines.end(), str);
            }
        }
    }
}
void Document::replaceLines() {}
int Document::search(string text) { return 1; }
void Document::replaceText(string oldText, string newText){};
void Document::saveFile(){};
void Document::quit(){};
void Document::printFile()
{
    vector<string>::iterator it = lines.begin();

    cout << "lines.size=" << lines.size() << endl;
    for (int i = 1; i <= lines.size(); i++)
    {
        cout << i << (*it) << endl;
        ++it;
    }
}