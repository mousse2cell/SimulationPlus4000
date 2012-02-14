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
    void addPoint(Point* p);
    void removePoint(Point* p);
    void addTriangle(Triangle * ta);
	void removeTriangle(Triangle * ta);
private:
	std::vector<Point*> points;
	std::vector<Triangle*> triangles;
};

#endif /* SEGMENT_H_ */
