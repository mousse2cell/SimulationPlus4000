/*
 * Ligne.cpp
 *
 *  Created on: 8 févr. 2012
 *      Author: mobilette
 */

#include "Ligne.h"

Ligne::Ligne() {
	// TODO Auto-generated constructor stub

}
Ligne::Ligne(int i):ID(i)
{
}
Ligne::~Ligne() {
	// TODO Auto-generated destructor stub
}

int Ligne::getID() const
{
    return ID;
}



void Ligne::setID(int id)
{
    ID = id;
}



