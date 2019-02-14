#include "list.h"
Node::Node(Planet * p){
	this->p = p;
	this->next = NULL;
	this->prev = NULL;

}
List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}
List::~List(){//fix this
	while(head != NULL){
		current = head->next;
		delete head;
		head = current;
	}
}
void List::insert(int index, Planet * p){
	this->size++;
	Node * nodeToAdd = new Node(p);
	if(index > this->size || index < 0){
		tail->next = nodeToAdd;
		nodeToAdd->prev = tail;
		tail = nodeToAdd;
		return;
	}
	if(index == 0){
		head->prev = nodeToAdd;
		nodeToAdd->next = head;
		head = nodeToAdd;
		return;
	}
	current = head;
	Node * last = head;
	int i = 0;
	while(current != NULL && i < index){
		last = current;
		current = current->next;
		i++;
	}
	last->next = nodeToAdd;
	nodetoAdd->next = current;
}
Planet* read(int index){
	if(index > size || index < 0){
		return NULL;
	}
	current = head;
	int i = 0;
	while(i < index){
		current = current->next;
		i++;
	}
	return current->p;
}
bool remove(int index){
	if(index > size || index < 0){
		return false;
	}
	size--;
	Node * temp = head;
	if(index == 0){
		head = head->next;
		head->prev = NULL;
		delete temp;
		return true;
	}
	current = head;
	int i = 0;
	while(i < index){
		temp = current;
		current = current->next;
		i++;
	}
	temp->next = current->next;
	current->next->prev = temp;
	delete current;
	return true;
}
