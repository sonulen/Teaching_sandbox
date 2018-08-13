#ifndef DEBUG_VAR_H_
#define DEBUG_VAR_H_

#include "iostream"

#ifdef DEBUG_FLAG
#define DEBUG(var) { std::cout << __FILE__ << ":" << __LINE__ << ": " \
	<< #var << " = " << (var)  << std::endl; }
#else
#define DEBUG(var)
#endif


#endif /* DEBUG_VAR_H_ */
