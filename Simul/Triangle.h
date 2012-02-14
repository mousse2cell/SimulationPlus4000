/*
 * Triangle.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <vector>
#include "protoClass.h"
#include "../Simulation.h"
//REVOIR LES CONSTRUCTEURS

class Triangle {
public:
	Triangle();
	Triangle(int id);
	Triangle(int id, CentreFace* cent, std::vector<Sommet * > som, Arete* ar, std::vector<Segment *> seg);
	Triangle(int id, std::vector<Segment*> seg);
	virtual ~Triangle();
    int getID() const;
    std::vector<Segment*> getSegments() const;
    void setID(int id);
    void setSegments(std::vector<Segment*> lignes); //STOCKER TENSEUR (SIGMA 3D)
    void addSegment(Segment* s);
    void removeSegment(Segment* s);
    CentreFace *getCentreFace() const;
    std::vector<Sommet*> getSommets() const;
    void setCentreFace(CentreFace *centreFace);
    void setSommets(std::vector<Sommet*> sommets);
    void buildLignes();
private:
    int ID;
    CentreFace * centreFace;
    std::vector<Sommet *> sommets;
    Arete* arete;
    std::vector<Segment*> segments;
};

#endif /* TRIANGLE_H_ */
