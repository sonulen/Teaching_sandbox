#ifndef MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_
#define MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_

#include "iostream"
#include "debug_print.h"

namespace Meyers_Effective_C_55 {

class rules3 {
public:
	void sing_song () const {
		std::cout << "Kiki, do you love me? Are you riding? "
				"Say you'll never ever leave from beside me" << std::endl;
	}

	void roar () const {
		std::cout << "const roar" << std::endl;
		this->sing_song();
	}

	// Не константный метод использует константный
	void roar () {
		std::cout << "non const roar" << std::endl;
		static_cast<const rules3>(*this).roar();
	}

	const int& my_num () const {
		std::cout << "const" << std::endl;
		return this->id;
	}

	// Не константный метод использует константный и возвращает ссылку на объект
	int& my_num() {
		std::cout << "non const" << std::endl;
		return const_cast<int&> (static_cast<const rules3>(*this).my_num());
	}

	int id = 2;
};

inline void func_for_rules3 () {
	const rules3 const_obj;
	rules3 non_const_obj2;
	const int& num1 = const_obj.my_num();
	(void) num1;
	int& num2 = non_const_obj2.my_num();
	const_obj.roar();
	non_const_obj2.roar();
	// WHY: почему тут ломается num2?
	DEBUG_FULL_PRINT(num1);
	DEBUG_FULL_PRINT(num2);
	num2 = 3;
	DEBUG_FULL_PRINT(num1);
	DEBUG_FULL_PRINT(num2);
}
}
#endif /* MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_ */
