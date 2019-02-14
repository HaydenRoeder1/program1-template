#include <stdlib>
#include <iostream>
#include "planet.h"

class Vector{
	private:
	int vSize;
	int index;
	Planet* planets[];

	public:
	~Vector();
	void insert(int,Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
}
