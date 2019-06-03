/*
 * specific_swap.h
 */

#ifndef MEYERS55_RULES_25_SPECIFIC_SWAP_H_
#define MEYERS55_RULES_25_SPECIFIC_SWAP_H_

#include "algorithm"

//namespace std {
//	template<>
//	void swap<Muclass> (Muclass& a, Muclass& b) {
//		a.swap(b);
//	}
//}

namespace Meyers_Effective_C_55 {

class Muclass {
public:

	friend void swap(Muclass& a, Muclass& b) {
		a.swap(b);
	}

	void swap(Muclass& rhs) {
		using std::swap;
		swap(this->x, rhs.x);
	}

	int x = 0;
};

inline void func_for_rules25 () {
	Muclass ob1, ob2;
	ob2.x = 2;
	using std::swap;
	swap (ob1,ob2);
	DEBUG_FULL_PRINT (ob1.x);
	DEBUG_FULL_PRINT (ob2.x);
}
}
#endif /* MEYERS55_RULES_25_SPECIFIC_SWAP_H_ */
