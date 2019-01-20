/*
 * destr_in_smart_ptr.h
 *
 *  Created on: Sep 8, 2018
 *      Author: sonulen
 */

#ifndef MEYERS55_RULES_15_DESTR_IN_SMART_PTR_H_
#define MEYERS55_RULES_15_DESTR_IN_SMART_PTR_H_

#include "iostream"
#include <memory>


class ink {
public:
	ink() {};

	void roar () {
		std::cout << "My num is = " << this->x << std::endl;
	}

	~ink() {
		std::cout << "Destructor ink" << std::endl;
	}

	int x = 2;
};

void del_ink (ink* const obj) {
	std::cout << "Del function" << std::endl;
	delete obj;
}

class Holder {
public:
	Holder (): obj2(new ink(), del_ink) {
		std::shared_ptr<ink> obj3(new ink());
		obj3->x = 4;
		obj3->roar();
	}
	ink obj;
	std::shared_ptr<ink> obj2;
};

inline void func_for_rules15 () {
	Holder obj;
	obj.obj.roar();
	obj.obj2->roar();
}

#endif /* MEYERS55_RULES_15_DESTR_IN_SMART_PTR_H_ */
