/*
 * Segment.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Segment.h"
#include "Triangle.h"
#include <iostream>
Segment::Segment():Ligne(-1) {
	// TODO Auto-generated constructor stub

}

Segment::~Segment() {
	// TODO Auto-generated destructor stub
}

std::vector<Triangle*> Segment::getTriangles() const
{
    return triangles;
}


void Segment::setTriangles(std::vector<Triangle*> tr)
{
    this->triangles = tr;
}

void Segment::addTriangle(Triangle *ta)
{
	triangles.push_back(ta);
}


void Segment::removeTriangle(int id)
{
	std::vector<Triangle*>::iterator i;
	for(i=triangles.begin();i!=triangles.end();++i){
		Triangle* cs = *i;
		if(id==cs->getID()){
			triangles.erase(i);
			return;
		}
	}
}

void Segment::print(int level) const
{
	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"Segment ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"Sommet : "<<std::endl;
	sommet->print(level+1);
	centreFace->print(level+1);
}

CentreFace *Segment::getCentreFace() const
{
    return centreFace;
}

Sommet *Segment::getSommet() const
{
    return sommet;
}

void Segment::setCentreFace(CentreFace *centreFace)
{
    this->centreFace = centreFace;
}

void Segment::setSommet(Sommet *sommet)
{
    this->sommet = sommet;
}







