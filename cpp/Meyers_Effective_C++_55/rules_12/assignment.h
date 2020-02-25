/*
 * assignment.h
 */

#ifndef MEYERS55_RULES_12_ASSIGNMENT_H_
#define MEYERS55_RULES_12_ASSIGNMENT_H_

#include "iostream"
#include "algorithm"
namespace Meyers_Effective_C_55 {
class First {
public:
	explicit First (): x(0), y(1) {
		std::cout << "First constructor" << std::endl;
	}

	First (const First& rhs): x(rhs.x), y(rhs.y) {
		std::cout << "First copy constructor" << std::endl;
	}

	First (First&& rhs): x(rhs.x), y(rhs.y) {
		std::cout << "First move constructor" << std::endl;
	}

	First& operator= (const First& rhs) {
		std::cout << "First operator=" << std::endl;
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}

	// move and swap
	First& operator= (First&& rhs) {
		std::cout << "First operator= &&" << std::endl;
		using std::swap;
		swap(this->x, rhs.x);
		swap(this->y, rhs.y);
		return *this;
	}

	First& swap (First& rhs) {
		std::cout << "First swap" << std::endl;
		using std::swap;
		swap(this->x, rhs.x);
		swap(this->y, rhs.y);
		return *this;
	}

	void set_x (const int& rhs) {
		this->x = rhs;
	}

	void set_y (const int& rhs) {
		this->y = rhs;
	}

	~First () {
		std::cout << "First destructor " << std::endl;
	}
private:
	int x;
	int y;
};

// swap с двумя аргументами
void swap (First& lhs, First& rhs) {
	std::cout << "First and First swap" << std::endl;
	lhs.swap(rhs);
}

class Second : public First {
public:
	explicit Second (): z(2), c(3) {
		std::cout << "Second constructor" << std::endl;
	}

	Second (const Second& rhs): First(rhs), z(rhs.z), c(rhs.c) {
		std::cout << "Second copy constructor" << std::endl;
	}

	// copy
	Second& operator= (const Second& rhs) {
		std::cout << "Second operator=" << std::endl;
		this->First::operator =(rhs);
		this->z = rhs.z;
		this->c = rhs.c;
		return *this;
	}

	Second& swap (Second& rhs) {
		this->First::swap(rhs);
		using std::swap;
		swap(this->z, rhs.z);
		swap(this->c, rhs.c);
		return *this;
	}

private:
	int z;
	int c;
};

// Swap с двумя аргументами
void swap (Second& lhs, Second& rhs) {
	std::cout << "Second and Second swap" << std::endl;
	lhs.swap(rhs);
}

inline void func_for_rules12 () {
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
}

#endif /* MEYERS55_RULES_12_ASSIGNMENT_H_ */
