/*
 * Sommet.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Sommet.h"

Sommet::Sommet():Point(-1) {
	// TODO Auto-generated constructor stub

}
Sommet::Sommet(int i, CVector c, std::vector<Face*> fa):Point(i,c),faces(fa)
{
}

Sommet::Sommet(int i, CVector c, std::vector<Face*> fa, std::vector<Arete*> ar):Point(i,c),faces(fa),aretes(ar)
{
}
Sommet::~Sommet() {
	// TODO Auto-generated destructor stub
}

std::vector<Arete*> Sommet::getAretes() const
{
    return aretes;
}

std::vector<Face*> Sommet::getFaces() const
{
    return faces;
}

void Sommet::setAretes(std::vector<Arete*> aretes)
{
    this->aretes = aretes;
}

void Sommet::setFaces(std::vector<Face*> faces)
{
    this->faces = faces;
}

void Sommet::addArete(Arete *ar)
{
	aretes.push_back(ar);
}



void Sommet::addFace(Face *fa)
{
	faces.push_back(fa);
}



void Sommet::removeArete(int id)
{
	std::vector<Arete*>::iterator i;
	for(i=aretes.begin();i!=aretes.end();++i){
		Arete* cs = *i;
		if(id==cs->getID()){
			aretes.erase(i);
			return;
		}
	}
}





void Sommet::removeFace(int id)
{
	std::vector<Face*>::iterator i;
	for(i=faces.begin();i!=faces.end();++i){
		Face* cs = *i;
		if(id==cs->getID()){
			faces.erase(i);
			return;
		}
	}
}

void Sommet::print(int level) const
{

	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"Sommet ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"Coord : "<<coord.getX()<<"; "<<coord.getY()<<"; "<<coord.getZ()<<std::endl;

}







