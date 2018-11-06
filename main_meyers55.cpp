#include "rules.h"

// Псевдомейн
void check_rules () {
	// rules 3
	// func_for_rules3 ();
	// rules 4
	// func_for_rules4 ();
	// rules 7
	// func_for_rules7 ();
	// rules 12
	//func_for_rules12 ();
	// rules 15
	//func_for_rules15();
	// rules 24
	//func_for_rules24();
	// rules 25
	//func_for_rules25();
	// rules 27
	//func_for_rules27();
	// rules 33
	//func_for_rules33();
	// rules 35
	//func_for_rules35();
	// rules 37
	func_for_rules37();
}

void func_for_rules3 () {
	const rules3 const_obj;
	rules3 non_const_obj2;
	const int& num1 = const_obj.my_num();
	int& num2 = non_const_obj2.my_num();
	const_obj.roar();
	non_const_obj2.roar();
	// WHY: почему тут ломается num2?
	DEBUG(num1);
	DEBUG(num2);
	num2 = 3;
	DEBUG(num1);
	DEBUG(num2);
}

void func_for_rules4 () {
	getter_object().sing_song();
	getter_object().sing_song();
	getter_object().sing_song();
	DEBUG(getter_object().how_many());
}

void func_for_rules7 () {
	Parent obj1;
	Son obj2;
	Daughter obj3;
	Parent* obj_son = new Son();
	delete obj_son;
	(void) obj1; (void) obj2; (void) obj3;
	(void) obj_son;
}

void func_for_rules12 () {
	First obj1;
	obj1.set_x(2);
	obj1.set_y(2);
	First obj2;
	obj2 = obj1;
	First obj3(obj2);

	// wat?
	// First obj4(First());

	Second obj_second;
	obj_second.set_x(12);
	Second obj2_second(obj_second);
	obj_second.set_x(111);
	obj2_second = obj_second;
	obj_second.set_y(1919);
	obj_second.swap(obj2_second);
	obj_second.set_y(1919);

	using std::swap;
	swap(obj_second, obj2_second);

}

void func_for_rules15 () {
	Holder obj;
	obj.obj.roar();
	obj.obj2->roar();
}

void func_for_rules24 () {
	values x = values::FOUR;
	values y = values::THREE;
	DEBUG (sizeof(x));
	rational obj (x);
	rational obj2 (x,y);
	(void) obj; (void) obj2;
}

void func_for_rules25 () {
	Muclass ob1, ob2;
	ob2.x = 2;
	using std::swap;
	swap (ob1,ob2);
	DEBUG (ob1.x);
	DEBUG (ob2.x);
}

void func_for_rules27 () {
	if (mywindow* pobj = create_mywindow()) {
		pobj->mysong();
	}
}

void func_for_rules33 () {
	Derived object;
	object.mf1();
	object.mf1(2);
}

void func_for_rules35 () {
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

void func_for_rules37 () {
	Shape obj1;
	Rectangle obj2;
	Shape* p_base = nullptr;
	p_base = &obj1;
	obj1.u_color();
	p_base->u_color();
	p_base = &obj2;
	obj2.u_color();
	p_base->u_color();
	Rectangle* p_rect = &obj2;
	p_rect->u_color();
}
