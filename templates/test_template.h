/*
 * test_template.h
 *
 *  Created on: Apr 26, 2018
 *      Author: sonulen
 */

#ifndef TEST_TEMPLATE_H_
#define TEST_TEMPLATE_H_

template <class Type>
class TClass {
public:
	TClass(Type value): value(value){};
	void roar ();
	Type get_value();
	TClass<Type> get_obj();
private:
	Type value;
};


// #include "test_template.cpp"

#endif /* TEST_TEMPLATE_H_ */
