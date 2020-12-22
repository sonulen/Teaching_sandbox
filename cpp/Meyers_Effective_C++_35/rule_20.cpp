#include <iostream>

class Object {
public:
    Object() { std::cout << "Ctor" << std::endl; }
    Object(const Object&) { std::cout << "Copy ctor" << std::endl; }
    const Object& operator= (const Object&) { std::cout << "Copy =" << std::endl; return *this; }
    ~Object() { std::cout << "Dtor" << std::endl; }

    std::string s = "empty";
};

Object myfunction (){
  Object return_v;
  return_v.s = "infunction";
  return return_v;
}


// Более интересный пример. Бесплатный виртуальный деструктор (не надо так)
class Base {
public:
    ~Base() { std::cout << "Base dtor\n"; }
};

class Foo : public Base {
public:
    // Note: No virtual dtors
    ~Foo() { std::cout << "Foo dtor\n"; }
};

Foo  return_foo()  { return {}; }

int main (void) {
  // its ok because it is an official C++ feature 
  // to extend the life time of a temporary object to the life time
  // of the const reference which refers to it.
  const auto& r = myfunction();
  // Output:
  // Ctor
  // String is = infunction
  // Dtor
  std::cout << "String is = " << r.s << std::endl;

  // Output:
  // Foo dtor
  // Base dtor
  const Base &b {return_foo()};
  return 0;
}
