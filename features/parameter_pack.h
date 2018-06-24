/*
 * parameter_pack.cpp
 *
 *  Created on: May 4, 2018
 *      Author: sonulen
 */
#include <iostream>

template <typename T>
void bar(T t) {
	(void) t;
	std::cout << "Bar = " << t << std::endl;
}

void foo2() {
	std::cout << "Last" << std::endl;
}

template <typename Car, typename... Cdr>
void foo2(Car car, Cdr... cdr)
{
  bar(car);
  foo2(cdr...);
}

//Example: foo2 (1,2,3,4,5,"3");
