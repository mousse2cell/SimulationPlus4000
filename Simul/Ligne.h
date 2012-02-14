/*
 * Ligne.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef LIGNE_H_
#define LIGNE_H_

#include <vector>

class Ligne {
public:
	Ligne();
	Ligne(int i);
	virtual ~Ligne();
    int getID() const;
    void setID(int id);
protected:
	int ID;
};

#endif /* LIGNE_H_ */
