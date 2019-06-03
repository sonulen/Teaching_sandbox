/*
 * strategy_classic.h
 */

#ifndef MEYERS55_RULES_35_STRATEGY_CLASSIC_H_
#define MEYERS55_RULES_35_STRATEGY_CLASSIC_H_
#include <iostream>

namespace Meyers_Effective_C_55 {

class GameCharacter_classic; // опережающее объявление

class HealthCalcFunc {
public:
	virtual int calc(const GameCharacter_classic&) const {
		std::cout << "HealthCalcFunc::calc()" << std::endl;
		return 1;
	}
	virtual ~HealthCalcFunc() {}
};

class min_Health : public HealthCalcFunc {
public:
	int calc(const GameCharacter_classic&) const override  {
		std::cout << "min_Health::calc()" << std::endl;
		return 1;
	}
	virtual ~min_Health() {}
};

class max_Health : public HealthCalcFunc {
public:
	int calc(const GameCharacter_classic&) const override {
		std::cout << "max_Health::calc()" << std::endl;
		return 1;
	}
	virtual ~max_Health() {}
};

class GameCharacter_classic {
public:
	explicit GameCharacter_classic(HealthCalcFunc& phfc) : pHealth(&phfc) {}

	int healthValue() const {
		return pHealth->calc(*this);
	}
private:
	HealthCalcFunc* pHealth;
};
}


#endif /* MEYERS55_RULES_35_STRATEGY_CLASSIC_H_ */
