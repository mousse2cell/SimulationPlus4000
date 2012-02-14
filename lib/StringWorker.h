/*
 * StringWorker.h
 *
 *  Created on: 9 févr. 2012
 *      Author: mobilette
 */

#ifndef STRINGWORKER_H_
#define STRINGWORKER_H_

#include <string>
#include <vector>
class StringWorker {
public:
	StringWorker();
	virtual ~StringWorker();
	static void Split(std::string word, std::vector<std::string> & pieces, const char * splitChar);
};

#endif /* STRINGWORKER_H_ */
