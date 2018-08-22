/*
 * assignment.h
 */

#ifndef MEYERS55_RULES_12_ASSIGNMENT_H_
#define MEYERS55_RULES_12_ASSIGNMENT_H_

#include "iostream"
#include "algorithm"

class First {
public:
	First (): x(0), y(1) {
		std::cout << "First constructor" << std::endl;
	}

	First (const First& rhs): x(rhs.x), y(rhs.y) {
		std::cout << "First copy constructor" << std::endl;
	}

	First (First&& rhs): x(rhs.x), y(rhs.y) {
		std::cout << "First move constructor" << std::endl;
	}

	// или обычный через = лучше? как выбрать?
	// copy and swap
	First& operator= (First rhs) {
		std::cout << "First operator=" << std::endl;
		using namespace std;
		swap(this->x, rhs.x);
		swap(this->y, rhs.y);
		return *this;
	}

	// move and swap
	First& operator= (First&& rhs) {
		std::cout << "First operator=" << std::endl;
		using namespace std;
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

class Second : public First {

private:
	int z;
	int c;
};



#endif /* MEYERS55_RULES_12_ASSIGNMENT_H_ */
