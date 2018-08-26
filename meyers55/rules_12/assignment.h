/*
 * assignment.h
 */

#ifndef MEYERS55_RULES_12_ASSIGNMENT_H_
#define MEYERS55_RULES_12_ASSIGNMENT_H_

#include "iostream"
#include "algorithm"

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


class Second : public First {
public:
	explicit Second (): z(2), c(3) {
		std::cout << "Second constructor" << std::endl;
	}

	Second (const Second& rhs): First(rhs), z(rhs.z), c(rhs.c) {
		std::cout << "Second copy constructor" << std::endl;
	}

	// swap and copy
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

#endif /* MEYERS55_RULES_12_ASSIGNMENT_H_ */
