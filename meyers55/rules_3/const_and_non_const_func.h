#ifndef MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_
#define MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_

#include "iostream"

class rules3 {
public:
	void sing_song () {
		std::cout << "Kiki, do you love me? Are you riding? \
					Say you'll never ever leave from beside me" << std::endl;
	}

	void roar () const {
		std::cout << "const roar" << std::endl;
	}

	void roar () {
		std::cout << "non const roar" << std::endl;
	}

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
