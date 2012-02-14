/*
 * Cellule.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */


#ifndef CELLULE_H_
#define CELLULE_H_

#include <vector>
#include <set>
#include <iostream>
#include "Face.h"


class Cellule {
public:
	Cellule();
	Cellule(int id);
	virtual ~Cellule();
	void addFace(Face* f);
	void removeFace(Face* f);
	std::vector<Face*> getFaces() const;
	void setFaces(std::vector<Face*> fs);
	int getID() const;
	void setID(const int i);
    CVector getCentroid() const;
    void setCentroid(CVector centroid);
    std::vector<Sommet * > getSommets() const;
private:
	int ID;
	CVector centroid;
	std::vector<Face*> faces;
};

#endif /* CELLULE_H_ */
