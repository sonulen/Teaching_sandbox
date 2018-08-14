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
	p3 = &q2;
	p2 = &q2; //на что указывает p можно менять
	// *p2 = 5; //ошибка, число менять уже нельзя
	// *p3 = 5; //ошибка, число менять уже нельзя

	// rules 3
	rules3 obj;
	const int& str = obj.my_num();
	int& str2 = obj.my_num();
	std::cout << str << " " << str2 << std::endl;
}
