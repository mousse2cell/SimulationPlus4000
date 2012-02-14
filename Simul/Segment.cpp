/*
 * Segment.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Segment.h"
#include "Triangle.h"
#include <iostream>
Segment::Segment() {
	// TODO Auto-generated constructor stub

}

Segment::~Segment() {
	// TODO Auto-generated destructor stub
}

std::vector<Triangle*> Segment::getTriangles() const
{
    return triangles;
}

std::vector<Point*> Segment::getPoints() const
{
    return points;
}

void Segment::setTriangles(std::vector<Triangle*> tr)
{
    this->triangles = tr;
}

void Segment::setPoints(std::vector<Point*> points)
{
    this->points = points;
}

void Segment::addPoint(Point *p)
{
	if(points.size()>2){
		std::cout<<"Erreur : tentative d'insertion d'un 3ième point à un segment"<<std::endl;
		return;
	}
	points.push_back(p);
}



void Segment::removePoint(Point *p)
{
	std::vector<Point*>::iterator i;
	for(i=points.begin();i!=points.end();++i){
		Point* cs = *i;
		if(p->getID()==cs->getID()){
			points.erase(i);
			return;
		}
	}
}
void Segment::addTriangle(Triangle *ta)
{
	triangles.push_back(ta);
}


void Segment::removeTriangle(Triangle *ta)
{
	std::vector<Triangle*>::iterator i;
	for(i=triangles.begin();i!=triangles.end();++i){
		Triangle* cs = *i;
		if(ta->getID()==cs->getID()){
			triangles.erase(i);
			return;
		}
	}
}



