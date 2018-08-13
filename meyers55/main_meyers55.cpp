#include "const_and_non_const_func.h"
#include "debug_var.h"

void check_rules () {
	// rules 3
	rules3 obj;
	const std::string& str = obj.my_roar();
	std::string& str2 = obj.my_roar();
	std::cout << str << " " << str2 << std::endl;
}
