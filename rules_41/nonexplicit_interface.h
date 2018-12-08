/*
 * explicit_interface.h
 *
 *  Created on: Dec 8, 2018
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_
#define SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_

#include <iostream>

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

#endif /* SB_MEYERS55_RULES_41_NONEXPLICIT_INTERFACE_H_ */
