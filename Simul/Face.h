/*
 * Face.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef FACE_H_
#define FACE_H_

#include "protoClass.h"
#include "CentreFace.h"
#include "Sommet.h"
#include "Cellule.h"
#include <vector>


class Face {
public:
	Face();
	Face(int id);
	Face(int id, std::vector<Cellule*> cells);
	Face(int id, std::vector<Cellule*> cells, CentreFace* cent);
	Face(int id, std::vector<Cellule*> cells, CentreFace* cent, std::vector<Sommet*> s);
	Face(int id, std::vector<Cellule*> cells, CentreFace* cent, std::vector<Sommet*> s, std::vector<Triangle*> t);
	virtual ~Face();
	int getID() const;
	void setID(const int id);
	std::vector<Cellule*> getCellules() const;
    CentreFace* getCentreFace() const;
    std::vector<Sommet*> getSommets() const;
    void setCellules(std::vector<Cellule*> cells);
    void setCentreFace(CentreFace* centre);
    void setSommets(std::vector<Sommet*> sommets);
    void addSommet(Sommet* sommet);
    void addCellule(Cellule* cell);
    void addTriangle(Triangle* tri);
    void removeTriangle(int id);
    void removeCellule(int id);
    void removeSommet(int id);
    void changeCellule(Cellule* from, Cellule* to);
    void buildTriangle();
    void evalCentreFace();
    std::vector<Triangle*> getTriangles() const;
    void setTriangles(std::vector<Triangle*> triangles);
    void print(int level) const;
private:
	int ID;
	std::vector<Cellule*> cellules;//cellules voisines
	CentreFace* centreFace;
	std::vector<Sommet*> sommets;
	std::vector<Triangle *> triangles;

};

#endif /* FACE_H_ */
