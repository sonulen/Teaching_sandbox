#include "const_and_non_const_func.h"
#include "debug_var.h"

void func_for_rules3 ();

// Псевдомейн
void check_rules () {
	// Константный указатель
	int q1=1;
	int *const p1 = &q1; //инициализация в момент объявления
	*p1 = 5; //само число можно менять
	// p1 = &q; //ошибка

	// Указатель на константу
	int q2=1;
	const int* p2;
	int const* p3;
	(void) p2; (void) p3;
	p3 = &q2;
	p2 = &q2; //на что указывает p можно менять
	// *p2 = 5; //ошибка, число менять уже нельзя
	// *p3 = 5; //ошибка, число менять уже нельзя

	// rules 3
	func_for_rules3 ();
}

void func_for_rules3 () {
	const rules3 const_obj;
	rules3 non_const_obj2;
	const int& num1 = const_obj.my_num();
	int& num2 = non_const_obj2.my_num();
	const_obj.roar();
	non_const_obj2.roar();
	(void) num1; (void) num2;
}
