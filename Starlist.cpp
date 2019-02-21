#include <cstdlib>
#include <cstdio>
#include "Starlist.h"
Starlist::Starlist(){
	planets = new List();
}
Starlist::~Starlist(){
	delete planets;
}
long Starlist::addPlanet(){
	Planet * planetToAdd = new Planet(rand() % 3000);
	planets->insert(planets->getSize(), planetToAdd);
	return (long)planetToAdd;
}
bool Starlist::removePlanet(int id){
	for(unsigned int i = 0; i < planets->getSize(); i++){
		if(planets->read(i)->getID() == id){
			planets->remove(i);
			return true;
		}
	}
	return false;
}
Planet* Starlist::getPlanet(int id){
	for(unsigned int i = 0; i < planets->getSize(); i++){
		if(planets->read(i)->getID() == id){
			return planets->read(i);
		}
	}
	return NULL;
}
void Starlist::orbit(){
	for(unsigned int i = 0; i < planets->getSize(); i++){
		planets->read(i)->orbit();
	}
}
void Starlist::printStarInfo(){	
	printf("The star currently has %d planets.\n", planets->getSize());
	printf("Planets:\n");
	for(unsigned int i = 0; i < planets->getSize(); i++){
		printf("\t Planet %c%lu is %d million miles away at position %d around the star.\n",
			planets->read(i)->getType(),
			planets->read(i)->getID(),
			planets->read(i)->getDistance(),
			planets->read(i)->getPos());
	}
}
unsigned int Starlist::getCurrentNumPlanets(){
	return planets->getSize();
}
