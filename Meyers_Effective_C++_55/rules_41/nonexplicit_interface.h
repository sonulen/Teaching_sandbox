/*
 * explicit_interface.h
 *
 *  Created on: Dec 8, 2018
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_
#define SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_

#include <iostream>

namespace Meyers_Effective_C_55 {

class Widget {
public:
	Widget() {};
	~Widget () {};

	virtual void normalize () {
		std::cout << "normalize" << std::endl;
	}

	int size = 2;
};

// Функция требующая неявного интерфейса
template <class T>
void doProccessing (T& obj) {
	if (obj.size > 0) {
		obj.normalize();
	}
}

inline void func_for_rules41 () {
	Widget obj;
	doProccessing(obj);
	// Не будет компилироваться т.к. нет необходимого интерфейса
	//int x;
	//doProccessing(x);
}
}
#endif /* SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_ */
