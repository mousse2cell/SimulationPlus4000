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
    void removeCellule(Cellule* cell);
    void removeSommet(Sommet* sommet);
    void changeCellule(Cellule* from, Cellule* to);
    CVector getCentroid() const;
    void setCentroid(CVector centroid);
    void buildTriangle();
    void evalCentroid();
private:
	int ID;
	std::vector<Cellule*> cellules;//cellules voisines
	CentreFace* centreFace;
	std::vector<Sommet*> sommets;
	CVector centroid;

};

#endif /* FACE_H_ */
