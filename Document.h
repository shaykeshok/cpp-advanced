#pragma once

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Document
{
private:
public:
	std::vector<string> lines;
	std::vector<string>::iterator index; //point on the current index
	Document();
	int getIndex();                                   //v
	void addLines(string c);                          //v
	void replaceLines();                              //
	int getVectorLen();                               //v
	void jumpToLine(int lineNum);                     //v
	void mergeLines();                                //v
	void deleteLine();                                //v
	void search(string text);                          //
	void replaceText(string oldText, string newText); //
	void saveFile(string fileName);                                  //
	void quit();                                      //v
	void printFile();
	void printIndex() { cout << getIndex() << endl; };
	void addLineAfter(string str);
	void addLineBefore(string str);
	void addLineReplace(string str);
	// void addLinesFromFile(vector<string> file);

};
