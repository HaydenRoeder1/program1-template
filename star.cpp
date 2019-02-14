
#include <cstdlib>
#include <cstdio>
#include "planet.h"
#include "star.h"

/*Star*/
Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;
	this->next_id = 0;
}
Star::~Star(){
	for(int i = 0; i < current_planets; i++){
		delete planets[i];
	}
	free(planets);
}
long int Star::addPlanet(){
	this->current_planets++;
	Planet * newPlanets[] = new Planet[this->current_planets];
	for(int i = 0; i < this->current_planets - 1; i++){
		newPlanets[i] = this->planets[i];
	}
	this->next_id++;
	Planet * planetToAdd = new Planet(rand() % 3000);
	newPlanets[current_planets - 1] = planetToAdd;
	delete this->planets;
	this->planets = newPlanets;
	return planetToAdd->getID();
}
bool Star::removePlanet(int id){
	for(int i = 0; i < this->current_planets; i++){
		if((*(this->planets[i])).getID() == id){
			Planet * newArr[this->current_planets - 1];
			for(int x = 0; x < current_planets - 1; x++){
				if(x == i){
					delete this->planets[x];
					continue;
				}
				newArr[x] = this->planets[x];
			}
			delete this->planets;
			this->planets = newArr;
			this->current_planets--;
			return true;		
		}
	}
	return false;
}
Planet * Star::getPlanet(int id){
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getID() == id){
			return this->planets[i];		
		}
	}
	return NULL;
}
Planet Star::getFurthest(){
	int furthestIndex = 0;
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getDistance() > this->planets[furthestIndex]->getDistance()){
			furthestIndex = i;
		}
	}
	return *(this->planets[furthestIndex]);
}
void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i]->orbit();
	}
}
void Star::printStarInfo(){
	printf("The star currently has %d planets.\n", this->current_planets);
	printf("Planets:\n");
	for(int i = 0; i < this->current_planets; i++){
		printf("\t Planet %c%d is %d million miles away at position %d around the star.\n",
			this->planets[i]->getType(),
			this->planets[i]->getID(),
			this->planets[i]->getDistance(),
			this->planets[i]->getPos());
	}
}




