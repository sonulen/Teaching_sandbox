/*
 * strategy.h
 */

#ifndef MEYERS55_RULES_35_STRATEGY_H_
#define MEYERS55_RULES_35_STRATEGY_H_
#include <iostream>
#include <functional>
class GameCharacter;

int defaultHealthCalc(const GameCharacter&) {
	std::cout << "defaultHealthCalc" << std::endl;
	return 0;
}

short calcHealth(const GameCharacter&) {
	std::cout << "short calcHealth" << std::endl;
	return 0;
}

struct HealthCalculator {
	int operator() (const GameCharacter&) const {
		std::cout << "HealthCalculator::operator()" << std::endl;
		return 0;
	}
};

class GameLevel {
public:
	float health(const GameCharacter&) const {
		std::cout << "GameLevel::health()" << std::endl;
		return 0;
	}
};

class GameCharacter {
public:
	// HealthCalcFunction - это любая вызываемая сущность, которой можно
	// передать в качестве параметра нечто, совместимое с GameCharacter,
	// и которая возвращает нечто, совместимое с int
	typedef std::function<int (const GameCharacter&)> HealthCalcFunc;

	explicit GameCharacter (HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {

	}

	void what_with_health () {
		this->healthFunc(*this);
	}

	HealthCalcFunc healthFunc;
};


class EvilBadGay: public GameCharacter {
public:
	EvilBadGay (HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(hcf) {};
};

#endif /* MEYERS55_RULES_35_STRATEGY_H_ */
