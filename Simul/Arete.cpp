/*
 * Arete.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Arete.h"
#include "Sommet.h"
#include <iostream>
Arete::Arete() {
	// TODO Auto-generated constructor stub

}
Arete::Arete(int i, std::vector<Sommet*> so, std::vector<Triangle*> fa):Ligne(i),sommets(so),triangles(fa){

}
Arete::~Arete() {
	// TODO Auto-generated destructor stub
}

std::vector<Triangle*> Arete::getTriangles() const
{
    return triangles;
}

std::vector<Sommet*> Arete::getSommets() const
{
    return sommets;
}

void Arete::setTriangles(std::vector<Triangle*> t)
{
    this->triangles = t;
}

void Arete::setSommets(std::vector<Sommet*> sommets)
{
    this->sommets = sommets;
}

void Arete::addSommet(Sommet *so)
{
	if(sommets.size()>2){
		std::cout<<"Erreur : tentative d'insertion d'un 3ième sommet à une arête"<<std::endl;
		return;
	}
	sommets.push_back(so);
}



void Arete::addTriangle(Triangle *ta)
{
	triangles.push_back(ta);
}



void Arete::removeSommet(Sommet *so)
{
	std::vector<Sommet*>::iterator i;
	for(i=sommets.begin();i!=sommets.end();++i){
		Sommet* cs = *i;
		if(so->getID()==cs->getID()){
			sommets.erase(i);
			return;
		}
	}
}





void Arete::removeTriangle(Triangle *ta)
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

