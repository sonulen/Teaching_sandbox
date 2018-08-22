#include "debug_var.h"
#include "const_and_non_const_func.h"
#include "ref_to_static.h"
#include "virtual_constructor_destructor.h"

void func_for_rules3 ();
void func_for_rules4 ();
void func_for_rules7 ();

// Псевдомейн
void check_rules () {
	// rules 3
	// func_for_rules3 ();
	// rules 4
	// func_for_rules4 ();
	// rules 7
	func_for_rules7 ();

}

void func_for_rules3 () {
	const rules3 const_obj;
	rules3 non_const_obj2;
	const int& num1 = const_obj.my_num();
	int& num2 = non_const_obj2.my_num();
	const_obj.roar();
	non_const_obj2.roar();
	// WHY: почему тут ломается num2?
	DEBUG(num1);
	DEBUG(num2);
	num2 = 3;
	DEBUG(num1);
	DEBUG(num2);
}

void func_for_rules4 () {
	getter_object().sing_song();
	getter_object().sing_song();
	getter_object().sing_song();
	DEBUG(getter_object().how_many());
}

void func_for_rules7 () {
	Parent obj1;
	Son obj2;
	Daughter obj3;
	Parent* obj_son = new Son();
	delete obj_son;
	(void) obj1; (void) obj2; (void) obj3;
	(void) obj_son;
}
