/*
 * Triangle.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Triangle.h"
#include "Arete.h"
#include "CentreFace.h"
#include "Sommet.h"
#include "Segment.h"
#include "Ligne.h"


Triangle::Triangle() {
	// TODO Auto-generated constructor stub

}
Triangle::Triangle(int id):ID(id){

}
Triangle::Triangle(int id, CentreFace *cent, std::vector<Sommet*> som, Arete *ar, std::vector<Segment*> seg):ID(id),centreFace(cent),sommets(som),arete(ar),segments(seg)
{
}

Triangle::Triangle(int id, std::vector<Segment*> seg):ID(id),segments(seg){

}
Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

int Triangle::getID() const
{
    return ID;
}

std::vector<Segment*> Triangle::getSegments() const
{
    return segments;
}

void Triangle::setID(int id)
{
    ID = id;
}

void Triangle::setSegments(std::vector<Segment*> lignes)
{
    this->segments = lignes;
}

CentreFace *Triangle::getCentreFace() const
{
    return centreFace;
}

std::vector<Sommet*> Triangle::getSommets() const
{
    return sommets;
}

void Triangle::setCentreFace(CentreFace *centreFace)
{
    this->centreFace = centreFace;
}

void Triangle::setSommets(std::vector<Sommet*> sommets)
{
    this->sommets = sommets;
}

void Triangle::addSegment(Segment *s)
{
	if(segments.size()>2){
		std::cout<<"Erreur : tentative d'insertion d'un 3ième segment à un triangle"<<std::endl;
		return;
	}
	segments.push_back(s);
}

void Triangle::removeSegment(Segment *s)
{
	std::vector<Segment*>::iterator i;
	for(i=segments.begin();i!=segments.end();++i){
		Segment* cs = *i;
		if(s->getID()==cs->getID()){
			segments.erase(i);
			return;
		}
	}
}


void Triangle::buildLignes()
{
	if(sommets.size()>1){
		if(Simulation::ARETES.find(to_string(sommets[0]->getID())+"--"+to_string(sommets[1]->getID()))!=Simulation::ARETES.end()){
			Arete ar;
			ar.setID(Simulation::ARETES.size()+1);
			ar.addSommet(sommets[0]);
			ar.addSommet(sommets[1]);
			Simulation::ARETES[to_string(sommets[0]->getID())+"--"+to_string(sommets[1]->getID())] = ar;
			this->arete = &Simulation::ARETES[to_string(sommets[0]->getID())+"--"+to_string(sommets[1]->getID())];
		}
		if(centreFace->getID()!=-1){
			for(int i=0;i<2;i++){
				if(Simulation::SEGMENTS.find(to_string(centreFace->getID())+"--"+to_string(sommets[i]->getID()))!=Simulation::SEGMENTS.end()){
					Segment s;
					s.setID(Simulation::SEGMENTS.size()+1);
					s.addPoint(centreFace);
					s.addPoint(sommets[i]);
					Simulation::SEGMENTS[to_string(centreFace->getID())+"--"+to_string(sommets[i]->getID())] = s;
					addSegment(&Simulation::SEGMENTS[to_string(centreFace->getID())+"--"+to_string(sommets[i]->getID())]);
				}
			}
		}
	}
}







