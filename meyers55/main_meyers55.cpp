#include "debug_var.h"
#include "const_and_non_const_func.h"
#include "ref_to_static.h"
#include "virtual_constructor_destructor.h"
#include "assignment.h"
#include "destr_in_smart_ptr.h"
#include "explicit_and_default_value.h"

void func_for_rules3 ();
void func_for_rules4 ();
void func_for_rules7 ();
void func_for_rules12 ();
void func_for_rules15 ();
void func_for_rules24 ();

// Псевдомейн
void check_rules () {
	// rules 3
	// func_for_rules3 ();
	// rules 4
	// func_for_rules4 ();
	// rules 7
	// func_for_rules7 ();
	// rules 12
	//func_for_rules12 ();
	// rules 15
	//func_for_rules15();
	// rules 24
	func_for_rules24();
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

void func_for_rules12 () {
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

void func_for_rules15 () {
	Holder obj;
	obj.obj.roar();
	obj.obj2->roar();
}

void func_for_rules24 () {
	values x = values::FOUR;
	values y = values::THREE;
	DEBUG (sizeof(x));
	rational obj (x);
	rational obj2 (x,y);
	(void) obj; (void) obj2;
}
