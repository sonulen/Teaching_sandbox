/*
 * ref_to_static.h
 */

#ifndef MEYERS55_RULES_4_REF_TO_STATIC_H_
#define MEYERS55_RULES_4_REF_TO_STATIC_H_

#include "iostream"
#include "stdint.h"

class Object {
public:
	Object() {
		counter++;
		std::cout << "Object constructor" << std::endl;
	}

	void sing_song () const {
		std::cout << "Kiki, do you love me? Are you riding? "
				"Say you'll never ever leave from beside me" << std::endl;
	}

	uint32_t how_many () {
		return Object::counter;
	}

	~Object() {
		std::cout << "Object destructor" << std::endl;
	}

private:
	static uint32_t counter;
};

Object& getter_object ();

#endif /* MEYERS55_RULES_4_REF_TO_STATIC_H_ */
