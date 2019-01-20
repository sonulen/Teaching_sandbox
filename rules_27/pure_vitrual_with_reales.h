/*
 * pure_vitrual_with_reales.h
 */

#ifndef MEYERS55_RULES_27_PURE_VITRUAL_WITH_REALES_H_
#define MEYERS55_RULES_27_PURE_VITRUAL_WITH_REALES_H_

#include "iostream"

class interface {
public:
	void start_song () {
		this->mysong();
	}

	virtual void mysong () = 0;
};

void interface::mysong() {
	std::cout << "My baby left today" << std::endl <<
				"He’s outside, in the rain"	<< std::endl;
}

class mywindow : public interface {
public:
	void mysong () final {
		std::cout << "Not ";
		this->interface::mysong();
	}
};

mywindow* create_mywindow () {
	return new mywindow();
}

inline void func_for_rules27 () {
	if (mywindow* pobj = create_mywindow()) {
		pobj->mysong();
	}
}

#endif /* MEYERS55_RULES_27_PURE_VITRUAL_WITH_REALES_H_ */
