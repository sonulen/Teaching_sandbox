#include <iostream>
#include <exception>

class Bad
{
    public:
        // Added the noexcept(false) so the code keeps its original meaning.
        // Post C++11 destructors are by default `noexcept(true)` and
        // this will (by default) call terminate if an exception is
        // escapes the destructor.
        //
        // But this example is designed to show that terminate is called
        // if two exceptions are propagating at the same time.
        ~Bad() noexcept(false)
        {
            throw 1;
        }
};

void bad_f(bool throwable = true) {
    std::cout << "\t bad_f():" << std::endl;
    if (throwable) throw "second";
}


// Program returned: 139
// Program stdout:
// #1
// 	 bad_f():
// 	 All ok!
// catched after ~Bad()
// #2. Вот почему исключения из dtor плохая идея:
// 	 bad_f():
// Catch terminate!
int main() {
    std::set_terminate([](){ std::cout << "Catch terminate!" << std::endl; });

    std::cout << "#1" << std::endl;

    try {
        Bad bad;

        bad_f(false);

        std::cout << "\t All ok!" << std::endl;

    } catch (...) {
        std::cout << "catched after ~Bad()" << std::endl;
    }
    
    std::cout << "#2. Вот почему исключения из dtor плохая идея:" << std::endl;

    try {
        Bad bad;

        bad_f();

        std::cout << "All ok!" << std::endl;
        // Т.к. bad_f бросает исключение -> происходит выход из секции try
        // Пытается уничтожится Bad и генерирует новое исключение:
        // terminate called after throwing an instance of 'int'
        // и если исключение генерируется в процессе stack unwinding
        // вызывается terminate

        // Стандарт:
        // If any function that is called directly by the stack unwinding mechanism, 
        // after initialization of the exception object and before the start of the exception handler, 
        // exits with an exception, std::terminate is called.
    } catch (...) {
        std::cout << "Не поймаем ничего" << std::endl;
    }

    return 0;
}
