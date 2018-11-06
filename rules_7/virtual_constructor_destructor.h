/*
 * virtual_constructor_destructor.h
 */

#ifndef MEYERS55_RULES_7_VIRTUAL_CONSTRUCTOR_DESTRUCTOR_H_
#define MEYERS55_RULES_7_VIRTUAL_CONSTRUCTOR_DESTRUCTOR_H_

#include "iostream"

class Parent {
public:
	Parent () {
		std::cout << "Constructor Parent" << std::endl;
	}

	// Если сделать не виртуальный то по указателю на родителя ток родительский деструктор будет вызываться
	virtual ~Parent () {
		std::cout << "Destructor Parent" << std::endl;
	}
};

class Son : public Parent {
public:
	Son () {
		std::cout << "Constructor Son" << std::endl;
	}

	virtual ~Son () {
		std::cout << "Destructor Son" << std::endl;
	}

};

class Daughter : public Parent {
public:
	Daughter () {
		std::cout << "Constructor Daughter" << std::endl;
	}

	virtual ~Daughter () {
		std::cout << "Destructor Daughter" << std::endl;
	}

};

#endif /* MEYERS55_RULES_7_VIRTUAL_CONSTRUCTOR_DESTRUCTOR_H_ */
