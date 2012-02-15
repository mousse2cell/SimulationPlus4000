/*
 * Simulation.h
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <map>
#include "Simul/Cellule.h"
#include "Simul/Triangle.h"
#include "Simul/Segment.h"
#include "Simul/Sommet.h"
#include "SpidV.h"



class Simulation {
public:
	Simulation();
	virtual ~Simulation();
	int run();
    float getBoxRadius() const;
    float getCellRadius() const;
    int getNombreCellules() const;
    std::vector<CVector> getInitialsCentroids() const;
    void setBoxRadius(float boxRadius);
    void setCellRadius(float cellRadius);
    void setNombreCellules(int nombreCellules);
    void setupFromFile(std::string centroid, std::string voronoi);
	static map<int,Cellule *> CELLULES;
	static std::vector<Face*> FACES;
	static std::vector<Triangle*> TRIANGLES;
	static map<std::string, Arete*> ARETES; // clef = id_pt_1--id_pt_2
	static map<std::string, Segment*>  SEGMENTS; // clef = id_centre_face--id_sommet
	static std::vector<Sommet*> SOMMETS;
	static std::vector<CentreFace*> CENTREFACE;
	static void cleanStatic();
private:
	static int DEFAULT_CELLS_NUMBER;
	static float DEFAULT_BOX_RADIUS;
	static float DEFAULT_CELL_RADIUS;
	static std::string TEMP_FILE;
	int nombreCellules;
	float boxRadius;
	float cellRadius;
};

#endif /* SIMULATION_H_ */
