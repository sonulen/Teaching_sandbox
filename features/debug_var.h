#ifndef DEBUG_VAR_H_
#define DEBUG_VAR_H_

#ifdef DEBUG_FLAG
#include "iostream"
#define DEBUG(var) { std::cout << __FILE__ << ":" << __LINE__ << ": " \
	<< #var << " = " << (var)  << std::endl; }
#else
#define DEBUG(var)
#endif


#endif /* DEBUG_VAR_H_ */
