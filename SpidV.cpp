/*
 * SpidV.cpp
 *
 *  Created on: 9 févr. 2012
 *      Author: mobilette
 */

#include "SpidV.h"


std::string SpidV::CENTROIDS_FILE = "centroids.txt";

SpidV::SpidV() {
	setSphereRadius(200.0f);
	setCellRadius(20.0f);
	setNombreCellules(20);
	setDt(0.1);
	setMaxTime(150);
	setReduceFactor(1);
	DEBUG=false;
}

SpidV::SpidV(int n, float spR, float cellR, float dt, float maxT, float reduceFactor)
{
	setSphereRadius(spR);
	setCellRadius(cellR);
	setNombreCellules(n);
	setDt(dt);
	setMaxTime(maxT);
	setReduceFactor(reduceFactor);
	DEBUG=false;
}

SpidV::~SpidV() {

}


std::vector<CVector> SpidV::getInitialsCentroids()
{
	std::vector<CVector> returnVector;
	Sphere customSphere;
	CVector c;
	customSphere.setCentroid(c);
	customSphere.setRadius(sphereRadius);
	srand((unsigned)time(0));
	std::vector<Force> listForces;
	customSphere.generateRandomCells(nombreCellules,cellRadius);
	std::vector<Cell*> cells=customSphere.getCells();
	if(DEBUG){
		for(unsigned int j=0;j<cells.size();j++){
			(cells[j]->getCoord().print());
		}
	}
	customSphere.updateForces();
	for(float i=0;i<=maxTime;i+=dt){
		customSphere.reduce(reduceFactor*(dt));
	}
	cells=customSphere.getCells();
	for(unsigned int j=0;j<cells.size();j++){
		returnVector.push_back(cells[j]->getCoord());
	}
	if(DEBUG){
		std::cout<<"Final sphere radius : "<<customSphere.getRadius()<<std::endl;
		for(unsigned int j=0;j<cells.size();j++){
			(cells[j]->getCoord().print());
		}
	}
	customSphere.exportToFile(CENTROIDS_FILE);
	return returnVector;
}

float SpidV::getCellRadius() const
{
    return cellRadius;
}

float SpidV::getDt() const
{
    return dt;
}

float SpidV::getMaxTime() const
{
    return maxTime;
}

int SpidV::getNombreCellules() const
{
    return nombreCellules;
}

float SpidV::getReduceFactor() const
{
    return reduceFactor;
}

float SpidV::getSphereRadius() const
{
    return sphereRadius;
}

void SpidV::setCellRadius(float cellRadius)
{
    this->cellRadius = cellRadius;
}

void SpidV::setDt(float dt)
{
    this->dt = dt;
}

void SpidV::setMaxTime(float maxTime)
{
    this->maxTime = maxTime;
}

void SpidV::setNombreCellules(int nombreCellules)
{
    this->nombreCellules = nombreCellules;
}

void SpidV::setReduceFactor(float reduceFactor)
{
    this->reduceFactor = reduceFactor;
}

// le rayon de la sphere apres reduction
void SpidV::setSphereRadius(float sphereRadius)
{
    this->sphereRadius = sphereRadius;
}


// le rayon de la sphere apres reduction
void SpidV::setFinalSphereRadius(float sphereRadius)
{
    this->sphereRadius = sphereRadius*3;
    this->dt = 0.1f;
    this->reduceFactor = 1.0f;
    this->maxTime = sphereRadius*2;
}

bool SpidV::isDebug() const
{
    return DEBUG;
}



void SpidV::setDebug(bool debug)
{
    DEBUG = debug;
}



