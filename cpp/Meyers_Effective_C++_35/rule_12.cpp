#include <iostream>
#include <exception>
#include <string>

class MyBaseEx : public std::exception {

    public: 

    MyBaseEx() { std::cout << "MyBaseEx" << std::endl; }
    MyBaseEx(const MyBaseEx&) { std::cout << "MyBaseEx(const MyBaseEx&)" << std::endl; }
    MyBaseEx& operator=(const MyBaseEx&) { std::cout << "operator= MyBaseEx" << std::endl; return *this; }
    virtual ~MyBaseEx() { std::cout << "~MyBaseEx" << std::endl; }
    void where_u() const noexcept {
        std::cout << "MyBaseEx im here: " << this << std::endl;
    }

    const char* what() const noexcept override {
        return "MyBaseEx You got me!";
    }
};

class MyEx : public MyBaseEx {
    public: 
    MyEx() { std::cout << "MyEx" << std::endl; }
    MyEx(const MyEx& ex) : MyBaseEx(ex) { std::cout << "MyEx(const MyEx&)" << std::endl; }
    MyEx& operator=(const MyEx&) { std::cout << "operator= MyEx" << std::endl; return *this; }
    ~MyEx() override { std::cout << "~MyEx" << std::endl; }
    void where_u() const noexcept {
        std::cout << "MyEx im here: " << this << std::endl;
    }

    const char* what() const noexcept override {
        return "MyEx You got me!";
    }
};


void make_mistake() {
    MyEx ex;
    ex.where_u();
    std::cout << "throw!" << std::endl;
    throw ex;
}

void make_ref_mistake() {
    MyEx ex;
    ex.where_u();
    MyBaseEx& re = ex;
    std::cout << "throw!" << std::endl;
    throw re;
}


int main() {
    // #1
    // MyBaseEx
    // MyEx
    // MyEx im here: 0x7ffdc1dad298
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // MyEx(const MyEx&)
    // ~MyEx
    // ~MyBaseEx
    // catch: std::exception
    // MyEx im here: 0x7ffdc1dad2c8
    // ~MyEx
    // ~MyBaseEx
    std::cout << std::endl << "#1"  << std::endl;
    {
        try {
            make_mistake();
        } catch (std::exception e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }
    
    // #2
    // MyBaseEx
    // MyEx
    // MyEx im here: 0x7ffe4999af88
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // MyEx(const MyEx&)
    // ~MyEx
    // ~MyBaseEx
    // catch: MyEx You got me!
    // MyEx im here: 0x1382f40
    // ~MyEx
    // ~MyBaseEx
    std::cout << std::endl << "#2"  << std::endl;
    {
        try {
            make_mistake();
        } catch (std::exception& e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }

    // #3
    // MyBaseEx
    // MyEx
    // MyEx im here: 0x7fff377dca40
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // ~MyEx
    // ~MyBaseEx
    // MyBaseEx(const MyBaseEx&)
    // catch: MyBaseEx You got me!
    // MyEx im here: 0x7fff377dca70
    // ~MyBaseEx
    // ~MyBaseEx
    // Т.к. принимаем по копии создается два объекта MyBaseEx
    std::cout << std::endl << "#3"  << std::endl;
    {
        try {
            make_ref_mistake();
        } catch (MyBaseEx e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }

    // #4
    // MyBaseEx
    // MyEx
    // MyEx im here: 0x7ffc669520b0
    // throw!
    // MyBaseEx(const MyBaseEx&)
    // ~MyEx
    // ~MyBaseEx
    // catch: MyBaseEx You got me!
    // MyEx im here: 0x2091f40
    // ~MyBaseEx
    // Хоть мы и принимаем по ссылке, но при выбросе исключения
    // Статический тип у нас MyBaseEx и создается объект MyBaseEx
    // а не динамический MyEx
    std::cout << std::endl << "#4"  << std::endl; 
    {
        try {
            make_ref_mistake();
        } catch (MyBaseEx& e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }

    return 0;
}
