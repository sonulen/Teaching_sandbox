#include "const_and_non_const_func.h"
#include "debug_var.h"

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
	const rules3 obj;
	rules3 obj2;
	const int& num1 = obj.my_num();
	int& num2 = obj2.my_num();
	(void) num1; (void) num2;
}
