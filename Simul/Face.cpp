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

Face::Face(int id, std::vector<Cellule*> cells, CentreFace *cent, std::vector<Sommet*> s, std::vector<Triangle*> t):ID(id),cellules(cells),centreFace(cent),sommets(s), triangles(t)
{
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
void Face::addTriangle(Triangle *tri)
{
	triangles.push_back(tri);
}

void Face::removeTriangle(int id)
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
void Face::removeCellule(int id)
{
	std::vector<Cellule*>::iterator i;
	for(i=cellules.begin();i!=cellules.end();++i){
		Cellule* cs = *i;
		if(id==cs->getID()){
			cellules.erase(i);
			return;
		}
	}
}

void Face::removeSommet(int id){
	std::vector<Sommet*>::iterator i;
	for(i=sommets.begin();i!=sommets.end();++i){
		Sommet* cs = *i;
		if(id==cs->getID()){
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
	removeCellule(from->getID());
	addCellule(to);
}



// pas fini, construit les triangles une fois que le centroid de la face est calculé
void Face::buildTriangle()
{
	for(unsigned int i = 0; i<sommets.size()-1;i++){
		Triangle t;
		t.setCentreFace(centreFace);
		t.addSommet(sommets[i]);
		t.addSommet(sommets[i+1]);
		t.buildLignes();
		t.setID(Simulation::TRIANGLES.size()+1);
		//std::cout<<"aaa "<<t.getSegments()[0]->getID()<<std::endl;
		Simulation::TRIANGLES.push_back(t);
		this->addTriangle(&Simulation::TRIANGLES[Simulation::TRIANGLES.size()-1]);
	}
	Triangle t;
	t.setID(Simulation::TRIANGLES.size()+1);
	t.setCentreFace(centreFace);
	t.addSommet(sommets[sommets.size()-1]);
	t.addSommet(sommets[0]);
	t.buildLignes();
	Simulation::TRIANGLES.push_back(t);
	this->addTriangle(&Simulation::TRIANGLES[Simulation::TRIANGLES.size()-1]);
}


// moyenne des sommets
void Face::evalCentreFace()
{
	CVector v;
	for(unsigned int i=0;i<sommets.size();i++){
		v = v + sommets[i]->getCoord();
	}
	CentreFace cf;
	cf.setID(Simulation::CENTREFACE.size()+1);
	cf.setCoord(v);
	cf.setFace(this);
	Simulation::CENTREFACE.push_back(cf);
	centreFace = &Simulation::CENTREFACE[Simulation::CENTREFACE.size()-1];
}

std::vector<Triangle*> Face::getTriangles() const
{
    return triangles;
}



void Face::setTriangles(std::vector<Triangle*> triangles)
{
    this->triangles = triangles;
}

void Face::print(int level) const
{
	std::string tab = "";
	for(int i=0;i<level;i++){
		tab+="\t";
	}
	std::cout<<tab<<"Face ID : "<<this->ID<<std::endl;
	std::cout<<tab<<"CentreFace : "<<std::endl;
	centreFace->print(level+1);
	std::cout<<tab<<"Triangles : "<<std::endl;
	for(unsigned int i=0;i<triangles.size();i++){
		triangles[i]->print(level+1);
	}
}















