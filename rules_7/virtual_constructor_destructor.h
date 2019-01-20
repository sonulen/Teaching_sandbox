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

inline void func_for_rules7 () {
	Parent obj1;
	Son obj2;
	Daughter obj3;
	Parent* obj_son = new Son();
	delete obj_son;
	(void) obj1; (void) obj2; (void) obj3;
	(void) obj_son;
}

#endif /* MEYERS55_RULES_7_VIRTUAL_CONSTRUCTOR_DESTRUCTOR_H_ */
