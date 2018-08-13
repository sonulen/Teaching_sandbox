#ifndef MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_
#define MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_

#include "string"
#include "iostream"
class rules3 {
public:
	const std::string& my_roar () {
		return this->roar;
	}

	std::string& my_roar() {
		std::cout << "here" << std::endl;
		return
				const_cast<std::string&> (
						static_cast<const rules3> (*this).my_roar()
				);
	}

	const std::string roar = "woof";
};



#endif /* MEYERS55_RULES_3_CONST_AND_NON_CONST_FUNC_H_ */
