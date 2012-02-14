/*
 * Segment.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "Ligne.h"
#include "Point.h"
#include "protoClass.h"

class Segment: public Ligne {
public:
	Segment();
	virtual ~Segment();
    std::vector<Triangle*> getTriangles() const;
    std::vector<Point*> getPoints() const;
    void setTriangles(std::vector<Triangle *> tr);
    void setPoints(std::vector<Point*> points);
    void addTriangle(Triangle * ta);
	void removeTriangle(int id);
	void print(int level) const;
    CentreFace *getCentreFace() const;
    Sommet *getSommet() const;
    void setCentreFace(CentreFace *centreFace);
    void setSommet(Sommet *sommet);
private:
	Sommet * sommet;
	CentreFace * centreFace;
	std::vector<Triangle*> triangles;
};

#endif /* SEGMENT_H_ */
