/*
 * SpidV.h
 *
 *  Created on: 9 févr. 2012
 *      Author: mobilette
 */

#ifndef SPIDV_H_
#define SPIDV_H_

#include "SpidV/protoClass.h"
#include "SpidV/Sphere.h"

class SpidV {
public:
	SpidV();
	SpidV(int n,float spR, float cellR, float dt, float maxT, float reduceFactor);
	virtual ~SpidV();
	std::vector<CVector> getInitialsCentroids();
    float getCellRadius() const;
    float getDt() const;
    float getMaxTime() const;
    int getNombreCellules() const;
    float getReduceFactor() const;
    float getSphereRadius() const;
    void setCellRadius(float cellRadius);
    void setDt(float dt);
    void setMaxTime(float maxTime);
    void setNombreCellules(int nombreCellules);
    void setReduceFactor(float reduceFactor);
    void setSphereRadius(float sphereRadius);
    void setFinalSphereRadius(float sphereRadius);
    bool isDebug() const;
    void setDebug(bool debug);
    static std::string CENTROIDS_FILE;
private:
	// Propriétés issues de SpidV
	int nombreCellules;
	float sphereRadius; // rayon de la boite
	float cellRadius; // rayon de la cellule
	float dt;
	float maxTime;
	float reduceFactor;
	bool DEBUG;
};

#endif /* SPIDV_H_ */
