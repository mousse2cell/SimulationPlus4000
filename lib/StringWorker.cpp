/*
 * StringWorker.cpp
 *
 *  Created on: 9 févr. 2012
 *      Author: mobilette
 */

#include "StringWorker.h"
#include <iostream>

void StringWorker::Split(std::string word, std::vector<std::string> & pieces, const char * splitChar)
{
	std::string::const_iterator it = word.begin(), end = word.end();
	std::string temp;
//	unsigned int counter = 0;
	while (it != end)
	{
		if (*it != *splitChar)
			temp += *it;
		else
		{
			pieces.push_back(temp);
			temp = "";
		}
		it++;
	}
	pieces.push_back(temp);
}
StringWorker::StringWorker() {
	// TODO Auto-generated constructor stub

}

StringWorker::~StringWorker() {
	// TODO Auto-generated destructor stub
}

