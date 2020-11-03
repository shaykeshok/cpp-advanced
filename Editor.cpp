#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Editor.h"
#include <stdio.h>

using namespace std;

void Editor::loop()
{
    cout<<"start"<<endl;
    Document doc;
    string reader = "";
    bool keepRun = true;
    while (keepRun)
    {
        getline(cin, reader);
        switch (reader[0])
        {
        //add line/s after this line
        case 'a':
        {
            doc.addLines("+");
            break;
        }
        //add line/s before this line
        case 'i':
        {
            doc.addLines("-");
            break;
        }
        //repalce this line in another line/s
        case 'c':
        {
            doc.replaceLines();
            break;
        }
        //delete this line
        case 'd':
        {
            doc.deleteLine();
            break;
        }
        //Look forward from the next line (after the current one) that contains the text string.
        //If not found, go to line 1 and continue searching forward to (inclusive) to the current line.
        //The first row found in the search becomes the current row.
        case '/':
        { //    '/text/'
            doc.search(reader.substr(1, reader.length() - 1));
            break;
        }
        //replace in this line the first time 'old' appear and replace it with 'new'
        case 's':
        { //    's/old/new/'
            vector<string> splitText = split(reader, false);
            string oldText = splitText[1];
            string newText = splitText[2];
            doc.replaceText(oldText, newText);
            break;
        }
        //merge this line with the next line
        case 'j':
        {
            doc.mergeLines();
            break;
        }
        //write this strings to file
        case 'w':
        { //w file
            doc.saveFile();
            break;
        }
        //quit editor
        case 'q':
        {
            keepRun = false;
            break;
        }
       
        //jump from this line +2 lines
        case '+':
        { //+2
            doc.jumpToLine(doc.getIndex() + std::stoi(reader.substr(1)));
            break;
        }
        //jump from this line -2 lines
        case '-':
        { //-2
            doc.jumpToLine(doc.getIndex() - std::stoi(reader.substr(1)));
            break;
        }
        //jump to the last line
        case '$':
        {
            doc.jumpToLine(doc.getVectorLen());
            break;
        }
        case 'p':
        {
            doc.printFile();
            break;
        }
         case 'g':
        {
            doc.printIndex();
            break;
        }
        default:
        {
            cout<<"default"<<endl;
            if (isdigit(reader[0]))
            {
                doc.jumpToLine(std::stoi(reader));
            }
            else
            {
                //problem
            }
        }
        }
    }
}

vector<string> Editor::split(string text, bool caseSen)
{
    string delimiter = "/";
    vector<string> data;

    size_t pos = 0;
    string token;
    if (caseSen)
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        token = text.substr(0, pos);
        data.push_back(token);
        text.erase(0, pos + delimiter.length());
    }
    data.push_back(text);
    return data;
}
