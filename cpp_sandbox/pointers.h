/*
 * pointers.h
 */

#ifndef FEATURES_POINTERS_H_
#define FEATURES_POINTERS_H_

namespace Other_feature {

void check_const_pointers () {
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
}
}

#endif /* FEATURES_POINTERS_H_ */
