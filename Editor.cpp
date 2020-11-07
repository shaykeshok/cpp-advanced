#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Editor.h"
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

Editor::Editor(string file)
{
	bool keepRun = true;
	string reader;
	// Read from the text file
	ifstream MyReadFile(file);
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, reader))
	{
		if (reader != "")
			doc.lines.push_back(reader);

	}
	doc.index = doc.lines.end();
	// vector<string>::iterator itt = fileText.begin();

	// for (int ii = 1; ii <= fileText.size(); ii++)
	// {
	//     cout << ii << (*itt) << endl;
	//     ++itt;
	// }

	// Close the file
	MyReadFile.close();
}
enum placeToWrite {
	before=1,
	after=2,
	replace=3
};
void Editor::loop()
{
	int place = 0;
	bool keepRun = true;
	bool writeToVector = false;
	string reader = "";
	while (keepRun)
	{
		getline(cin, reader);
		keepRun = writeFile(reader);
		if (!writeToVector) {
			switch (reader[0])
			{

			//add line/s after this line
			case 'a': //v
			{
				//doc.addLines("+");
				place = placeToWrite::after;
				writeToVector = true;
				break;
			}
			//add line/s before this line
			case 'i': //v
			{
				//doc.addLines("-");
				place = placeToWrite::before;
				writeToVector = true;
				break;
			}

			//repalce this line in another line/s
			case 'c': //v
			{
				//doc.replaceLines();
				place = placeToWrite::replace;
				writeToVector = true;
				break;
			}
			//delete this line
			case 'd': //v
			{
				doc.deleteLine();
				break;
			}
			//Look forward from the next line (after the current one) that contains the text string.
			//If not found, go to line 1 and continue searching forward to (inclusive) to the current line.
			//The first row found in the search becomes the current row.
			case '/': //v
			{         //    '/text/'
				doc.search(reader.substr(1, reader.length() - 1));
				break;
			}
			//replace in this line the first time 'old' appear and replace it with 'new'
			case 's': //v
			{         //    's/old/new/'
				vector<string> splitText = split(reader, false);
				string oldText = splitText[1];
				string newText = splitText[2];
				doc.replaceText(oldText, newText);
				break;
			}
			//merge this line with the next line
			case 'j': //v
			{
				doc.mergeLines();
				break;
			}
			//write this strings to file
			case 'w':
			{ //w file
				doc.saveFile(reader.substr(2));
				break;
			}
			//quit editor
			case 'q': //v
			{
				keepRun = false;
				break;
			}

			//jump from this line +2 lines
			case '+':
			{ //+2
				cout << "reader.substr(1): " << reader.substr(1) << endl;
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
			case 'p': //v
			{
				doc.printFile();
				break;
			}
			case 'g': //v
			{
				doc.printIndex();
				break;
			}
			default: //v
			{
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
		else {
		if (reader[0] != '.')
			switch (place)
			{
			case 1:
				doc.addLineBefore(reader);
				place= placeToWrite::after;
				break;
			case 2:
				doc.addLineAfter(reader);
				break;
			case 3:
				doc.addLineReplace(reader);
				place = placeToWrite::after;
				break;
			}
		else
			writeToVector = false;
		}
	}
}

bool Editor::writeFile(string reader)
{
	bool ans = true;

	return ans;
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
