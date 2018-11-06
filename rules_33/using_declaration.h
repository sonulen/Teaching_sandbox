/*
 * using_declaration.h
 */

#ifndef MEYERS55_RULES_33_USING_DECLARATION_H_
#define MEYERS55_RULES_33_USING_DECLARATION_H_

#include <iostream>

class Base {
public:
	virtual void mf1 () = 0;
	virtual void mf1 (int) {
		std::cout << "Base::mf1(int)" << std::endl;
	}

	virtual ~Base() {};
private:
};

class Derived : public Base {
public:
	// Если убрать то mf1(int) будет не доступна, так как не будет наследоваться потому что скроется
	using Base::mf1;

	void mf1 () override {
		std::cout << "Derived::mf1()" << std::endl;
	}

	virtual ~Derived() {};
private:
};


#endif /* MEYERS55_RULES_33_USING_DECLARATION_H_ */
