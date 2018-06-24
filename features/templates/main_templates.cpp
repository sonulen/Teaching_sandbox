/*
 * main_templates.cpp
 *
 *  Created on: May 1, 2018
 *      Author: sonulen
 */

#include "test_template.h"

void main_templates () {
	TClass<int> obj1(2);
	TClass<float> obj2(3.3);
	TClass<char> obj3('v');

	obj1.roar();
}


