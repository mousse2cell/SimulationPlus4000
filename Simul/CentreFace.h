/*
 * CentreFace.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef CENTREFACE_H_
#define CENTREFACE_H_

#include "Point.h"
#include "Face.h"

class CentreFace: public Point {
public:
	CentreFace();
	CentreFace(int i,CVector c, Face* fa);
	virtual ~CentreFace();
    Face* getFace() const;
    void setFace(Face* face);
private:
    Face* face;
};

#endif /* CENTREFACE_H_ */
