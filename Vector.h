#include <cstdlib>
#include <iostream>
#include "Planet.h"

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
