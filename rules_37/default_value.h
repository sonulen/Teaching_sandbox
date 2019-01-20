/*
 * default_value.h
 */

#ifndef MEYERS55_RULES_37_DEFAULT_VALUE_H_
#define MEYERS55_RULES_37_DEFAULT_VALUE_H_

#include <iostream>
#include <stdint.h>

enum class Colors : uint8_t {
	RED = 3,
	BLUE,
	GREEN
};

std::string print_color (Colors color) {
	if (color == Colors::RED) {
		return "RED";
	} else if (color == Colors::BLUE) {
		return "BLUE";
	} else if (color == Colors::GREEN) {
		return "Green";
	}
	return "undefined behaviour";
}

class Shape {
public:
	virtual void u_color (Colors color_ = Colors::RED) {
		std::cout << "Color = " << print_color(color_) << std::endl;
	}
};

class Rectangle : public Shape {
public:
	// Функция u_color связывается динамически
	// Но вот само значение по умолчанию связывается статически
	// Отсюда и появляется волшебство
	void u_color (Colors color_ = Colors::BLUE) override {
		std::cout << "Color = " << print_color(color_) << std::endl;
	}
};

inline void func_for_rules37 () {
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


#endif /* MEYERS55_RULES_37_DEFAULT_VALUE_H_ */
