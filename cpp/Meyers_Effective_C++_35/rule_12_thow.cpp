#include <iostream>
#include <exception>
#include <string>

class MyBaseEx : public std::exception {

    public: 

    MyBaseEx() { std::cout << "MyBaseEx" << std::endl; }
    MyBaseEx(const MyBaseEx&) { std::cout << "MyBaseEx(const MyBaseEx&)" << std::endl; }
    MyBaseEx& operator=(const MyBaseEx&) { std::cout << "operator= MyBaseEx" << std::endl; return *this; }
    virtual ~MyBaseEx() { std::cout << "~MyBaseEx" << std::endl; }

    const char* what() const noexcept override {
        return "MyBaseEx You got me!";
    }
};


void make_mistake() {
    try {
        MyBaseEx ex;
        std::cout << "throw!" << std::endl;
        throw ex;
    } catch (MyBaseEx& ex) {
        std::cout << "First" << std::endl;
        throw;
    }
}

void make_mistake_copy() {
    try {
        MyBaseEx ex;
        std::cout << "throw!" << std::endl;
        throw ex;
    } catch (MyBaseEx& ex) {
        std::cout << "First" << std::endl;
        throw ex;
    }
}



int main() {
    // #1
    // MyBaseEx
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // ~MyBaseEx
    // First
    // Second
    // ~MyBaseEx
    std::cout << "#1" << std::endl;
    try {
        make_mistake();
    } catch  (MyBaseEx& ex) {
        std::cout << "Second" << std::endl;
    }

    std::cout << std::endl;

    // #2
    // MyBaseEx
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // ~MyBaseEx
    // First
    // MyBaseEx(const MyBaseEx&)
    // ~MyBaseEx
    // Second
    // ~MyBaseEx
    // Разница из-за оператора throw просто пробрасывает исключение это же дальше
    // а throw ex генерирует новое
    std::cout << "#2" << std::endl;
    try {
        make_mistake_copy();
    } catch  (MyBaseEx& ex) {
        std::cout << "Second" << std::endl;
    }

    return 0;
}
