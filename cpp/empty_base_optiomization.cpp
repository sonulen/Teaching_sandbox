#include <utility>
#include <iostream>
#include <cassert>
 
struct Empty {}; // empty class
 
struct X {
    int i;
    [[no_unique_address]] Empty e;
};

struct Y {
    int i;
    Empty e;
};

struct Base {}; // empty class
 
struct Derived : Base {
    int i;
};
 
int main()
{
    std::cout << std::boolalpha;

    // the size of any object of empty class type is at least 1
    std::cout << "Empty sizeof = " << sizeof(Empty) << " & is empty = " <<  std::is_empty_v<Empty> << std::endl;

    // empty member optimized out
    std::cout << "X sizeof = " << sizeof(X) << " & is empty = " <<  std::is_empty_v<X> << std::endl;
    // but
    std::cout << "Y sizeof = " << sizeof(Y) << " & is empty = " <<  std::is_empty_v<Y> << std::endl;

    // the size of any object of empty class type is at least 1
    std::cout << "Base sizeof = " << sizeof(Base) << " & is empty = " <<  std::is_empty_v<Base> << std::endl;

    // empty base optimization applies
    std::cout << "Derived sizeof = " << sizeof(Derived) << " & is empty = " <<  std::is_empty_v<Derived> << std::endl;

    // Program stdout
    // Empty    sizeof = 1   & is empty = true
    // X        sizeof = 4   & is empty = false
    // Y        sizeof = 8   & is empty = false
    // Base     sizeof = 1   & is empty = true
    // Derived  sizeof = 4   & is empty = false

}
