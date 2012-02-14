/*
 * Cellule.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Cellule.h"
#include <set>

Cellule::Cellule() {

}

Cellule::Cellule(int id):ID(id) {

}

Cellule::~Cellule() {
	// TODO Auto-generated destructor stub
}

void Cellule::addFace(Face* f){
	faces.push_back(f);
}
void Cellule::removeFace(Face* f){
	std::vector<Face*>::iterator i;
	for(i=faces.begin();i!=faces.end();++i){
		Face* cf = *i;
		if(f->getID()==cf->getID()){
			faces.erase(i);
			return;
		}
	}
}
std::vector<Face*> Cellule::getFaces() const{
	return faces;
}
void Cellule::setFaces(std::vector<Face*> fs){
	faces.clear();
	faces=fs;
}
int Cellule::getID() const{
	return ID;
}
void Cellule::setID(const int i){
	this->ID=i;
}

CVector Cellule::getCentroid() const
{
    return centroid;
}

void Cellule::setCentroid(CVector centroid)
{
    this->centroid = centroid;
}

std::vector<Sommet*> Cellule::getSommets() const
{
	std::vector<Sommet*> listSommets;
	std::set<Sommet *> set;
	for(unsigned int i=0; i<faces.size();i ++){
		for(unsigned int j=0; j<faces[i]->getSommets().size();i++){
			set.insert(faces[i]->getSommets()[j]);
		}
	}
	std::copy(set.begin(), set.end(), std::back_inserter(listSommets));
	return listSommets;
}

void Cellule::print(int level) const
{
	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"Cellule ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"Centroid : "<<centroid.getX()<<"; "<<centroid.getY()<<"; "<<centroid.getZ()<<std::endl;
	std::cout<<tab<<"Faces : "<<std::endl;
	for(unsigned int i=0;i<faces.size();i++){
		faces[i]->print(level+1);
	}
}






