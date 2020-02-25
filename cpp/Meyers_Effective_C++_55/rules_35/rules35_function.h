#ifndef SB_MEYERS55_RULES_35_RULES35_FUNCTION_H_
#define SB_MEYERS55_RULES_35_RULES35_FUNCTION_H_

#include "NVI.h"
#include "strategy.h"
#include "strategy_classic.h"

namespace Meyers_Effective_C_55 {

inline void func_for_rules35 () {
	// NVI
	Character& def_unit = *(create_default_unit());
	Character& fat_unit = *(create_fat_unit());
	std::cout << def_unit.what_about_health() << std::endl;
	std::cout << fat_unit.what_about_health() << std::endl;

	// Strategy + function
	GameCharacter one;
	EvilBadGay two (calcHealth);
	HealthCalculator obj_functor;
	EvilBadGay three (obj_functor);
	GameLevel currentLevel;
	EvilBadGay four(std::bind(&GameLevel::health, currentLevel, std::placeholders::_1));

	one.what_with_health();
	two.what_with_health();
	three.what_with_health();
	four.what_with_health();

	// Classic Strategy
	HealthCalcFunc defaultHealthCalc;
	min_Health minCalc;
	max_Health maxCalc;
	GameCharacter_classic obj1 (defaultHealthCalc);
	GameCharacter_classic obj2 (minCalc);
	GameCharacter_classic obj3 (maxCalc);
	obj1.healthValue();
	obj2.healthValue();
	obj3.healthValue();
}
}

#endif /* SB_MEYERS55_RULES_35_RULES35_FUNCTION_H_ */
