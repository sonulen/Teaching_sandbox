/*
 * test_template.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: sonulen
 */

#include "test_template.h"
#include <iostream>

template class TClass<int>;
template class TClass<float>;

template <class Type>
void TClass<Type>::roar() {
	std::cout << "ROAR! Value: " << this->value << std::endl;
}

template <class Type>
Type TClass<Type>::get_value() {
	return this->value;
}

template <class Type>
TClass<Type> TClass<Type>::get_obj() {
	return *this;
}
