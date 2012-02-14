/*
 * Arete.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef ARETE_H_
#define ARETE_H_

#include "Ligne.h"
#include "Triangle.h"
#include "protoClass.h"

class Arete: public Ligne {
public:
	Arete();
	Arete(int i, std::vector<Sommet*> so, std::vector<Triangle*> fa);
	virtual ~Arete();
    std::vector<Triangle*> getTriangles() const;
    std::vector<Sommet*> getSommets() const;
    void setTriangles(std::vector<Triangle*> triangles);
    void setSommets(std::vector<Sommet*> sommets);
    void addTriangle(Triangle * fa);
    void addSommet(Sommet* so);
    void removeTriangle(Triangle * fa);
    void removeSommet(Sommet* so);
private:
	std::vector<Sommet*> sommets;
	std::vector<Triangle*> triangles;
};

#endif /* ARETE_H_ */
