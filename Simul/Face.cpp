/*
 * Face.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Face.h"
#include <iostream>
Face::Face() {
	// TODO Auto-generated constructor stub

}
Face::Face(int id):ID(id){

}
Face::Face(int id, std::vector<Cellule*> cells):ID(id),cellules(cells){

}
Face::Face(int id, std::vector<Cellule*> cells, CentreFace* cent):ID(id),cellules(cells),centreFace(cent){

}
Face::Face(int id, std::vector<Cellule*> cells, CentreFace* cent, std::vector<Sommet*> s):ID(id),cellules(cells),centreFace(cent),sommets(s){

}
Face::~Face() {
	// TODO Auto-generated destructor stub
}

std::vector<Cellule*> Face::getCellules() const
{
    return cellules;
}

CentreFace* Face::getCentreFace() const
{
    return centreFace;
}

std::vector<Sommet*> Face::getSommets() const
{
    return sommets;
}

void Face::setCellules(std::vector<Cellule*> cellules)
{
    this->cellules = cellules;
}

void Face::setCentreFace(CentreFace* centre)
{
    this->centreFace = centre;
}

void Face::setSommets(std::vector<Sommet*> sommets)
{
    this->sommets = sommets;
}

void Face::addSommet(Sommet* sommet){
	sommets.push_back(sommet);
}
void Face::addCellule(Cellule *cell)
{
	if(cellules.size()>2){
		std::cout<<"Erreur : tentative d'insertion d'une 3ième cellule à une face"<<std::endl;
		return;
	}
	cellules.push_back(cell);
}

void Face::removeCellule(Cellule *cell)
{
	std::vector<Cellule*>::iterator i;
	for(i=cellules.begin();i!=cellules.end();++i){
		Cellule* cs = *i;
		if(cell->getID()==cs->getID()){
			cellules.erase(i);
			return;
		}
	}
}

void Face::removeSommet(Sommet* sommet){
	std::vector<Sommet*>::iterator i;
	for(i=sommets.begin();i!=sommets.end();++i){
		Sommet* cs = *i;
		if(sommet->getID()==cs->getID()){
			sommets.erase(i);
			return;
		}
	}
}

int Face::getID() const
{
    return ID;
}

void Face::setID(int id)
{
    ID = id;
}

void Face::changeCellule(Cellule *from, Cellule *to)
{
	removeCellule(from);
	addCellule(to);
}

CVector Face::getCentroid() const
{
    return centroid;
}

void Face::setCentroid(CVector centroid)
{
    this->centroid = centroid;
}


// pas fini, construit les triangles une fois que le centroid de la face est calculé
void Face::buildTriangle()
{
	for(unsigned int i = 0; i<sommets.size();i++){
		Triangle t;
		t.buildLignes();
	}
}


// moyenne des sommets
void Face::evalCentroid()
{
	CVector v;
	for(unsigned int i=0;i<sommets.size();i++){
		v = v + sommets[i]->getCoord();
	}
	centroid = v;
}











