#ifndef MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_
#define MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_

#include "iostream"

class rules3 {
public:
	const int& my_num () const {
		std::cout << "const" << std::endl;
		return this->id;
	}

	int& my_num() {
		std::cout << "non const" << std::endl;
		return this->id;
	}

	int id = 2;
};



#endif /* MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_ */
