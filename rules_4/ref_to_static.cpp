/*
 * ref_to_static.cpp
 */
#include "ref_to_static.h"

uint32_t Object::counter = 0;

Object& getter_object () {
	static Object singleton;
	return singleton;
}

