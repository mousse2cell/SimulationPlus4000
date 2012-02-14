/*
 * Point.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Point.h"
#include <iostream>
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

void Point::print(int level) const
{
	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"Point ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"Coord : "<<coord.getX()<<"; "<<coord.getY()<<"; "<<coord.getZ()<<std::endl;
}





