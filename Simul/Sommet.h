/*
 * Sommet.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef SOMMET_H_
#define SOMMET_H_

#include "Point.h"
#include "Arete.h"
#include "Face.h"


class Sommet: public Point {
public:
	Sommet();
	Sommet(int i,CVector c, std::vector<Face*> fa);
	Sommet(int i,CVector c, std::vector<Face*> fa, std::vector<Arete*> ar);
	virtual ~Sommet();
    std::vector<Arete*> getAretes() const;
    std::vector<Face*> getFaces() const;
    void setAretes(std::vector<Arete*> aretes);
    void setFaces(std::vector<Face*> faces);
    void addArete(Arete * ar);
    void addFace(Face* fa);
    void removeArete(Arete* ar);
    void removeFace(Face* fa);
private:
    std::vector<Face*> faces;
    std::vector<Arete*> aretes;
};

#endif /* SOMMET_H_ */
