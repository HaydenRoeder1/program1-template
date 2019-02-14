#include "Vector.h"
//
Vector::Vector(int s){
	s = vSize;
	
	// You must create your internal array on the heap (using new). 
}

Vector::~Vector(){
	delete ;
}

void Vector::insert(int index, Planet*p){
	for(int i = 0, j = 0; i < size; i++){
		if(i == index){
			newArr[i] = p;		
		}
		else{
			newArr[i] = planets[j];
			j++;		
		}
	}
}

Planet* Vector::read(int index){
	if(index > this->size){
		return NULL;
	}
	else{
		planetPointer = &this->index;
		return indexAddress;
	}
}

bool Vector::remove(int index){
	delete this->index;
	size--;
}

unsigned Vector::size(){
	return this->size;
 }
