// set_unexpected example
#include <iostream>       // std::cerr
#include <exception>      // std::set_unexpected

void myunexpected () {
  std::cerr << "unexpected called\n";
  throw 0;     // throws int (in exception-specification)
}

void myfunction () throw (int) {  /// Deprecated in C++17 (ISO C++17 does not allow dynamic exception specifications)
  throw 'x';   // throws char (not in exception-specification)
}

int main (void) {
  std::set_unexpected (myunexpected);
  try {
    myfunction();
  }
  catch (int) { std::cerr << "caught int\n"; }
  catch (...) { std::cerr << "caught some other exception type\n"; }
  return 0;
}
