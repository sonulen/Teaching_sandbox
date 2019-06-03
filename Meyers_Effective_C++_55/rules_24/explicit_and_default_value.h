/*
 * explicit_and_default_value.cpp
 */

#ifndef MEYERS55_RULES_24_EXPLICIT_AND_DEFAULT_VALUE_CPP_
#define MEYERS55_RULES_24_EXPLICIT_AND_DEFAULT_VALUE_CPP_

#include <stdint.h>
#include "debug_print.h"

enum values : uint16_t {
	ONE = 6,
	TWO,
	THREE,
	AND,
	FOUR
};

class rational {
public:
	//	Не будет работать из за expilicit
	// rational obj2 = x;
	explicit rational (uint16_t x, uint16_t y = 1) : v1(x), v2(y) {
		DEBUG(v1);
		DEBUG(v2);
	}

	uint16_t v1 = 0;
	uint16_t v2 = 0;
};

inline void func_for_rules24 () {
	values x = values::FOUR;
	values y = values::THREE;
	DEBUG (sizeof(x));
	rational obj (x);
	rational obj2 (x,y);
	(void) obj; (void) obj2;
}

#endif /* MEYERS55_RULES_24_EXPLICIT_AND_DEFAULT_VALUE_CPP_ */
