/*
 * Simulation.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Simulation.h"
#include <sstream>
#include <fstream>
#include <set>
#include "lib/StringWorker.h"

int Simulation::DEFAULT_CELLS_NUMBER = 40;
float Simulation::DEFAULT_BOX_RADIUS = 100.0f;
float Simulation::DEFAULT_CELL_RADIUS = 20.0f;
std::string Simulation::TEMP_FILE = "tmp.txt";
map<int,Cellule *> Simulation::CELLULES;
std::vector<Face*> Simulation::FACES;
std::vector<Triangle*> Simulation::TRIANGLES;
//std::vector<Arete> Simulation::ARETES;
map<std::string,Segment *> Simulation::SEGMENTS;
std::vector<Sommet*> Simulation::SOMMETS;
std::vector<CentreFace*> Simulation::CENTREFACE;
map<std::string,Arete* > Simulation::ARETES;

Simulation::Simulation() {
	setNombreCellules(DEFAULT_CELLS_NUMBER);
	setBoxRadius(DEFAULT_BOX_RADIUS);
	setCellRadius(DEFAULT_CELL_RADIUS);
}

Simulation::~Simulation() {

}

int Simulation::run()
{
	//getInitialsCentroids();
	int exitcode=system((to_string("qvoronoi o Fv < ")+SpidV::CENTROIDS_FILE+">"+Simulation::TEMP_FILE).c_str());//qhull v Qbb p Fv  <
	setupFromFile(SpidV::CENTROIDS_FILE,Simulation::TEMP_FILE);
	cleanStatic();
	return exitcode;
}

float Simulation::getBoxRadius() const
{
    return boxRadius;
}

float Simulation::getCellRadius() const
{
    return cellRadius;
}

int Simulation::getNombreCellules() const
{
    return nombreCellules;
}

void Simulation::setBoxRadius(float boxRadius)
{
    this->boxRadius = boxRadius;
}

void Simulation::setCellRadius(float cellRadius)
{
    this->cellRadius = cellRadius;
}

std::vector<CVector> Simulation::getInitialsCentroids() const
{
	SpidV spidv;
	spidv.setCellRadius(cellRadius);
	spidv.setNombreCellules(nombreCellules);
	spidv.setFinalSphereRadius(boxRadius);
	return spidv.getInitialsCentroids();
}

void Simulation::setNombreCellules(int nombreCellules)
{
    this->nombreCellules = nombreCellules;
}

void Simulation::setupFromFile(std::string centroid, std::string voronoi)
{
	int vertexNumber = -1;
	int faceNumber = -1;
	bool vertex = false;
	bool face = false;
	std::string line;
	int compteur = 0;
	int skip = 2;
	// Cellule correspondant en fait au bord
	Cellule* border = new Cellule(0);
	CELLULES[border->getID()] = border;
	std::vector<std::string> tmp;
	// On test déjà quelles cellules vont être gardés

	ifstream myfile1(voronoi.c_str());
	compteur = 0;
	skip = 1;
	tmp.clear();
	//std::istringstream* iss;
	std::set<int> goodCells;
	if (myfile1.is_open())
	{

		while ( myfile1.good() )
		{

			for(int s = 0; s<=skip;s++){
				getline (myfile1,line);
			}
			compteur++;
			if(compteur > nombreCellules) break;
			if(compteur == 1 && !vertex){
				tmp.clear();
				StringWorker::Split(line,tmp," ");
				std::istringstream iss(tmp[0]);
				// convertir en un int
				iss >> vertexNumber;
				compteur = 0;
				vertex = true;
				skip = vertexNumber;
			}else{
				if(vertex){
					skip = 0;
					tmp.clear();
					StringWorker::Split(line,tmp," ");
					bool garde = true;
					//std::cout<<line<<std::endl;
					for(unsigned int i=0; i<tmp.size();i++){
						int p;
						std::istringstream iss(tmp[i]);
						// convertir en un int
						iss >> p;
						//std::cout<<"pt : "<<p<<std::endl;
						if(p == 0){
							garde = false;
							break;
						}
					}
					if(garde){
						//std::cout<<"garde "<<compteur<<std::endl;
						goodCells.insert(compteur);
					}
				}
			}
		}
	}
	myfile1.close();

	// On parse d'abord les centroides !
	ifstream centfile(centroid.c_str());
	skip = 0;
	compteur = 0;
	if (centfile.is_open())
	{
		while ( centfile.good() )
		{
			for(int s = 0; s<=skip;s++){
				getline (centfile,line);
			}

			skip = 0;
			compteur++;
			if(goodCells.find(compteur) != goodCells.end()){
				tmp.clear();
				StringWorker::Split(line,tmp," ");
				std::istringstream issx(tmp[0]);
				float x;
				issx >> x;
				std::istringstream issy(tmp[1]);
				float y;
				issy >> y;
				std::istringstream issz(tmp[2]);
				float z;
				issz >> z;
				Cellule* c = new Cellule(compteur);
				CVector cent(x,y,z);
				c->setCentroid(cent);
				Simulation::CELLULES[c->getID()] = c;
				if(compteur == nombreCellules) break;
			}
		}
	}
	centfile.close();



	ifstream myfile(voronoi.c_str());
	compteur = 0;
	skip = 0;
	vertex = false;
	vertexNumber = -1;
	tmp.clear();
	//std::istringstream* iss;

	if (myfile.is_open())
	{

		while ( myfile.good() )
		{

			for(int s = 0; s<=skip;s++){
				getline (myfile,line);
			}
			compteur++;
			if(compteur == 2 && vertexNumber == -1){
				tmp.clear();
				StringWorker::Split(line,tmp," ");
				std::istringstream iss(tmp[0]);
				// convertir en un int
				iss >> vertexNumber;
				compteur = 0;
				vertex = true;
			}else{
				if(compteur == vertexNumber+1 && vertex && !face){
					compteur = 0;
					skip = nombreCellules-1;
					vertex = false;
					face = true;
				}else{
					if(vertex && compteur > 1){
						tmp.clear();
						StringWorker::Split(line,tmp," ");
						if(tmp.size() !=0){
							std::istringstream iss3(tmp[0]);
							float x;
							iss3 >> x;
							std::istringstream iss4(tmp[1]);
							float y;
							iss4 >> y;
							std::istringstream iss5(tmp[2]);
							float z;
							iss5 >> z;
							CVector cv(x,y,z);
							Sommet* som = new Sommet();
							som->setID(compteur);
							som->setCoord(cv);
							SOMMETS.push_back(som);
						}
					}else{
						if(face && compteur != faceNumber+1){
							if(faceNumber==-1){
								std::istringstream iss2(line);
								// convertir en un int
								iss2 >> faceNumber;
								compteur = 0;
								skip = 0;
							}else{
								tmp.clear();
								StringWorker::Split(line,tmp," ");
								Face* face = new Face();
								face->setID(compteur);
								unsigned int i=0;
								bool continu = true;
								std::vector<int> data;
								for(unsigned j=1; j<tmp.size();j++){
									std::istringstream iss7(tmp[j]);
									int t1;
									iss7 >> t1;
									data.push_back(t1);
									if(t1 == 0 && j>2){ continu = false;break;}

								}
								if(continu){
									for(i=2; i<data.size();i++){
										face->addSommet(SOMMETS[data[i]-1]);
										SOMMETS[data[i]-1]->addFace(face);
										//std::cout<<i<<"__"<<"__"<<compteur<<std::endl;
									}
									face->setID(FACES.size()+1);
									face->evalCentreFace();
									face->buildTriangle();
									//std::cout<<"rr"<<face.getTriangles()[5]->getSegments()[0]->getID()<<std::endl;
									/*std::cout<<i<<"__"<<"__"<<compteur<<std::endl;*/
									if(goodCells.find(data[0]+1)!=goodCells.end())
										face->addCellule(Simulation::CELLULES[data[0]+1]);
									else
										face->addCellule(border);
									if(goodCells.find(data[1]+1)!=goodCells.end())
										face->addCellule(Simulation::CELLULES[data[1]+1]);
									else
										face->addCellule(border);
									FACES.push_back(face);
									if(goodCells.find(data[0]+1)!=goodCells.end()){
										Simulation::CELLULES[data[0]+1]->addFace(FACES[FACES.size()-1]);
									}else{
										Simulation::CELLULES[0]->addFace(FACES[FACES.size()-1]);
									}
									if(goodCells.find(data[1]+1)!=goodCells.end()){
										Simulation::CELLULES[data[1]+1]->addFace(FACES[FACES.size()-1]);
									}else{
										Simulation::CELLULES[0]->addFace(FACES[FACES.size()-1]);
									}
									/*std::cout<<compteur<<"----------"<<face.getID()<<std::endl;*/
									//std::cout<<"eee "<<face.getTriangles()[0]->getSegments()[0]->getID()<<std::endl;
									//face.print(0);

								}
							}
						}
					}

				}

			}
		}
		myfile.close();
		std::map<int,Cellule *>::const_iterator
		mit (CELLULES.begin()),
		mend(CELLULES.end());
		for(;mit!=mend;++mit) mit->second->print(0);

	}
}

void Simulation::cleanStatic()
{
	for(unsigned int i=0; i<TRIANGLES.size();i++){
		delete(TRIANGLES[i]);
	}
	for(unsigned int i=0; i<FACES.size();i++){
		delete(FACES[i]);
	}
	for(unsigned int i=0; i<SOMMETS.size();i++){
		delete(SOMMETS[i]);
	}
	for(unsigned int i=0; i<CENTREFACE.size();i++){
		delete(CENTREFACE[i]);
	}
	std::map<std::string,Segment *>::const_iterator
	mits (SEGMENTS.begin()),
	mends(SEGMENTS.end());
	for(;mits!=mends;++mits) delete(mits->second);
	std::map<std::string,Arete *>::const_iterator
	mita (ARETES.begin()),
	menda(ARETES.end());
	for(;mita!=menda;++mita) delete(mita->second);
	std::map<int,Cellule *>::const_iterator
	mit (CELLULES.begin()),
	mend(CELLULES.end());
	for(;mit!=mend;++mit) delete(mit->second);
	CELLULES.clear();
	FACES.clear();
	TRIANGLES.clear();
	ARETES.clear();
	SEGMENTS.clear();
	CENTREFACE.clear();
	SOMMETS.clear();
}












