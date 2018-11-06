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


#endif /* MEYERS55_RULES_37_DEFAULT_VALUE_H_ */
