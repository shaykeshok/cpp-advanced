#pragma once

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Document
{
private:
    std::vector<string> lines;
    std::vector<string>::iterator index; //point on the current index
public:
    Document();
    int getIndex();                                   //v
    void addLines(string c);                            //
    void replaceLines();                              //
    int getVectorLen();                               //v
    void jumpToLine(int lineNum);                     //v
    void mergeLines();                                //v
    void deleteLine();                                //v
    int search(string text);                          //
    void replaceText(string oldText, string newText); //
    void saveFile();                                  //
    void quit();                                      //
    void printFile();
    void printIndex(){cout<<getIndex()<<endl;}
};
