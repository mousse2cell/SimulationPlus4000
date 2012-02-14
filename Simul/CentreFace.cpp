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



