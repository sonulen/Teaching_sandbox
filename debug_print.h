#ifndef DEBUG_VAR_H_
#define DEBUG_VAR_H_

#ifdef DEBUG_BUILD
#include <iostream>

template<typename ...Args>
void print(const Args&  ...args)
{
	((std::cout << (args) << " " ), ...) << "\n";
}

/**
	Example:
	\code
	include "debug_print.h"

	int main() {
		DEBUG_PRINT("HELLO");
		DEBUG_PRINT("HELLO",2);
		std::complex<float> x (2,3);
		DEBUG_PRINT("HELLO", 2, x);
		DEBUG_PRINT("HELLO", " INT =", 2, "COMPLEX =", x);
		DEBUG_FULL_PRINT("HELLO", " INT =", 2, "COMPLEX =", x);

		while(1);
		return 0;
	}
	\endcode
 */
#define DEBUG_PRINT(args...) pt::print(args)

#define DEBUG_FULL_PRINT(args...) { \
	std::cout << __FILE__ << " " << __LINE__ << ": " ;\
	pt::print(args); }
#else
#define DEBUG_PRINT(...)
#define DEBUG_FULL_PRINT(...)
#endif

#endif /* DEBUG_VAR_H_ */
