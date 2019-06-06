//
// Created by Volodymyr ZOMBER
//

#include "Squad.hpp"
#include <iostream>

/*_____________________Coplien’s form________________________*/

Squad::Squad() : _count(0), _marinList(NULL) {}

Squad::~Squad() {

	t_marineList *tmp;

	while (this->_marinList) {
		tmp = this->_marinList->next;
		delete this->_marinList->marine;
		delete this->_marinList;
		this->_marinList = tmp;
	}
}

Squad::Squad(Squad const &src) {
	if (this != &src)
	{
		this->_count = src.getCount();

		t_marineList *org;
		t_marineList *fresh;

		org = src._marinList;
		fresh = new t_marineList;
		fresh->marine = org->marine;
		this->_marinList = fresh;
		fresh->next = NULL;
		fresh = fresh->next;
		org = org->next;

		while (org)
		{
			fresh = new t_marineList;
			fresh->marine = org->marine;
			fresh->next = NULL;
			fresh = fresh->next;
			org = org->next;
		}
	}
}

Squad& Squad::operator=(Squad const &src) {

	this->_count = src.getCount();

	t_marineList *org;
	t_marineList *fresh;

	org = src._marinList;
	fresh = this->_marinList;

	while (org)
	{
		fresh->marine = org->marine;
		fresh = fresh->next;
		org = org->next;
	}
	return *this;
}


/*___________________________________________________________*/

int Squad::getCount() const {
	return this->_count;
}

ISpaceMarine* Squad::getUnit(int n) const {
	int i = -1;
	t_marineList *tmp = this->_marinList;

	if (n < 0 && !tmp)
		return (NULL);

	while (++i < n && tmp)
		tmp = tmp->next;

	return (tmp->marine);
}

int Squad::push(ISpaceMarine *src) {

	int i = -1;

	t_marineList *tmp = this->_marinList;
	while (tmp && tmp->next && ++i)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next = new t_marineList;
		tmp->next->marine = src;
		tmp->next->next = NULL;
	}
	else
	{
		this->_marinList = new t_marineList;
		this->_marinList->marine = src;
		this->_marinList->next = NULL;
	}
	this->_count++;
	return (i);
}