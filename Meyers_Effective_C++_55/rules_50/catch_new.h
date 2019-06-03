/*
 * catch_new.h
 *
 *  Created on: Jan 20, 2019
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_50_CATCH_NEW_H_
#define SB_MEYERS55_RULES_50_CATCH_NEW_H_

#include <stddef.h>
#include <new>
#include "debug_print.h"

//void* operator new (std::size_t size) throw (std::bad_alloc) {
//	DEBUG(size);
//	void* pMem = malloc(size);
//	if (!pMem) {
//		throw(bad_alloc);
//	}
//	return pMem;
//}

//void* operator new(std::size_t size) {
//	DEBUG(size);
//	if (!size) {
//		size ++;
//	}
//
//	void* pMem = malloc(size);
//
//	return pMem;
//}
//
//void* operator new[](std::size_t size) {
//	DEBUG(size);
//	if (!size) {
//		size ++;
//	}
//
//	void* pMem = malloc(size);
//
//	return pMem;
//}

inline void func_for_rules50 () {
	int* x = new int;
	int* y = new int[4];
	(void) x;
	(void) y;
}
#endif /* SB_MEYERS55_RULES_50_CATCH_NEW_H_ */
