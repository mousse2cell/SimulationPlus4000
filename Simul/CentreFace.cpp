/*
 * CentreFace.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "CentreFace.h"

CentreFace::CentreFace() {
	// TODO Auto-generated constructor stub

}
CentreFace::CentreFace(int i, CVector c, Face *fa):Point(i,c),face(fa)
{
}
CentreFace::~CentreFace() {
	// TODO Auto-generated destructor stub
}

Face* CentreFace::getFace() const
{
    return face;
}



void CentreFace::setFace(Face* face)
{
    this->face = face;
}

void CentreFace::print(int level) const
{
	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"CentreFace ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"Coord : "<<coord.getX()<<"; "<<coord.getY()<<"; "<<coord.getZ()<<std::endl;
}





