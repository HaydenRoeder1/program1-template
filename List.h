#ifndef LIST_HEADER_HR
#define LIST_HEADER_HR
#include "Planet.h"
class Node{
public:
	Planet * p;
	Node * next;
	Node * prev;
	Node(Planet *);
};
class List{
private:
	Node * head, * tail, * current;
	unsigned int size;
public:
	List();
	~List();
	void insert(int index, Planet * p);
	Planet* read(int index);
	bool remove(int index);
	unsigned int getSize(){return size;}
	
};

#endif
