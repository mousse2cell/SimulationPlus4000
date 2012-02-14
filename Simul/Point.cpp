/*
 * Point.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Point.h"

Point::Point():ID(-1) {
	// TODO Auto-generated constructor stub

}
Point::Point(int i):ID(i){

}
Point::Point(int i, CVector c):ID(i),coord(c){

}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

CVector Point::getCoord() const
{
    return coord;
}

int Point::getID() const
{
    return ID;
}

void Point::setCoord(CVector coord)
{
    this->coord = coord;
}

void Point::setID(int id)
{
    ID = id;
}



