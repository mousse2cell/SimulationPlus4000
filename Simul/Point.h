/*
 * Point.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef POINT_H_
#define POINT_H_

#include "../genericClass/CVector.h"

class Point {
public:
	Point();
	Point(int i);
	Point(int i, CVector c);
	virtual ~Point();
    CVector getCoord() const;
    int getID() const;
    void setCoord(CVector coord);
    void setID(int id);
protected:
	int ID;
	CVector coord;
};

#endif /* POINT_H_ */
