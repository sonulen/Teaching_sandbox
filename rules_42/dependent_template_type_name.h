/*
 * dependent_template_type_name.h
 *
 *  Created on: Dec 8, 2018
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_42_DEPENDENT_TEMPLATE_TYPE_NAME_H_
#define SB_MEYERS55_RULES_42_DEPENDENT_TEMPLATE_TYPE_NAME_H_

#include <vector>
#include <iostream>

template <typename Iter_type>
void print_value (const Iter_type& iter) {
	// Так как тип элементов контейнера за итератором зависят от типа то тоже typename
	typename std::iterator_traits<Iter_type>::value_type temp (*iter);
	std::cout << temp << std::endl;
}

template <typename Type>
void print_values (const Type& container) {
	if (container.size() > 1) {
		// Т.к. итератор зависит от типа контейнера то typename явный
		typename Type::const_iterator iter (container.begin());
		iter++;
		print_value(iter);
	}
}

inline void func_for_rules42 () {
	std::vector<std::string> v;
	v.push_back("zero");
	v.push_back("first");
	v.push_back("second");
	print_values(v);
}

#endif /* SB_MEYERS55_RULES_42_DEPENDENT_TEMPLATE_TYPE_NAME_H_ */
