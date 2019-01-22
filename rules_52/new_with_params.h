/*
 * new_with_params.h
 *
 *  Created on: Jan 20, 2019
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_52_NEW_WITH_PARAMS_H_
#define SB_MEYERS55_RULES_52_NEW_WITH_PARAMS_H_

#include <stddef.h>
#include <new>
#include "debug_var.h"

//void* operator new(std::size_t size, int& count) {
//	count++;
//	DEBUG(count);
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
//void* operator new[](std::size_t size, int& count) {
//	count++;
//	DEBUG(count);
//	DEBUG(size);
//	if (!size) {
//		size ++;
//	}
//
//	void* pMem = malloc(size);
//
//	return pMem;
//}

inline void func_for_rules52 () {
//	int counter = 0;
//	int* x = new (counter) int;
//	int* y = new (counter) int[4];
//	(void) x;
//	(void) y;
}


#endif /* SB_MEYERS55_RULES_52_NEW_WITH_PARAMS_H_ */
