#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Document.h"
#include <fstream>
#include <iostream>

using namespace std;

Document::Document()
{
	index = lines.begin();
}

void Document::jumpToLine(int line)
{
	if (line > lines.size())
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

	vector<string>::iterator it = lines.begin();
	if (getIndex() != lines.size())
	{
		it = index;
		it++;
		(*index) += (*it);
		lines.erase(it);
	}
}
void Document::deleteLine()
{
	vector<string>::iterator it = lines.begin();
	it = index;
	if (getIndex() == getVectorLen())
		index--;
	// else index;
	lines.erase(it);
}

int Document::getIndex()
{
	cout << "getIndex" << endl;
	vector<string>::iterator it = lines.begin();
	int count = 1;
	while (it != index)
	{
		count++;
		it++;
	}
	cout << "getIndexend" << endl;

	return count;
}

void Document::addLineAfter(string str) {
	if (index != lines.end())
		index++;
	index = lines.insert(index, str);
}
void Document::addLineBefore(string str) {
	index = lines.insert(index, str);
}
void Document::addLineReplace(string str) {
	//lines.erase(index);
	*index = str;
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
			// cout << "index != lines.end(): " << (index != lines.end()) << endl;
			// if (index != lines.end())
			// {
			//     cout<<"tototototototot"<<endl;
			if (c == "+" && index != lines.end())
			{
				index++;
			}
			else
			{
				c = "+";
			}
			index = lines.insert(index, str);
		}
		// else
		// {
		//     index = lines.insert(lines.end(), str);
		// }
		// }
	}
}
// void Document::addLinesFromFile(vector<string> file)
// {
//     string str = "";
//     bool keepWrite = true;
//     while (keepWrite)
//     {
//         getline(cin, str);
//         if (str == ".")
//         {
//             keepWrite = false;
//         }
//         else
//         {
//             // cout << "index != lines.end(): " << (index != lines.end()) << endl;
//             // if (index != lines.end())
//             // {
//             //     cout<<"tototototototot"<<endl;
//             if (c == "+" && index != lines.end())
//             {
//                 index++;
//             }
//             else
//             {
//                 c = "+";
//             }
//             index = lines.insert(index, str);
//         }
//         // else
//         // {
//         //     index = lines.insert(lines.end(), str);
//         // }
//         // }
//     }
// }
void Document::replaceLines()
{
	lines.erase(index);
	addLines("-");
}
void Document::search(string text)
{
	vector<string>::iterator it = index;

	for (int i = getIndex() + 1; i < lines.size(); i++)
	{
		it++;
		string line = lines[i];
		if (lines[i].find(text) != string::npos)
		{
			index = it;
			return;
		}
		// return lines[i].find(text);
	}
	it = lines.begin();
	for (int i = 1; i <= getIndex(); i++)
	{
		string line = lines[i];
		if (lines[i].find(text) != string::npos)
		{
			index = it;
			return;
		}
		it++;
		// return lines[i].find(text);
	}
}
void Document::replaceText(string oldText, string newText)
{
	string str = (*index);
	int pos = str.find_first_of(oldText);
	str.replace(pos, oldText.length(), newText);
	(*index) = str;
};
void Document::saveFile(string fileName)
{
	//    char data[100];

	// open a file in write mode.
	ofstream outfile;
	outfile.open(fileName);
	vector<string>::iterator it = lines.begin();

	for (int i = 0; i < lines.size(); i++)
	{
		string data = lines[i];
		outfile << data << endl;
	}

	// close the opened file.
	outfile.close();
};
void Document::quit() {};
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