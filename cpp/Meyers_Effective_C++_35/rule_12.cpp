#include <iostream>
#include <exception>
#include <string>

struct Historian {
    std::string val;

    Historian()                                         { std::cout << "sDefaultConstructed" << std::endl; }
    Historian(const std::string& v) : val(v)            { std::cout << "sValueCopyConstructed" << std::endl; }
    Historian(std::string&& v) : val(std::move(v))      { std::cout << "sValueMoveConstructed" << std::endl; }
    Historian(const Historian& o) : val(o.val)          { std::cout << "sCopyConstructed" << std::endl; }
    Historian(Historian&& o) :  val(std::move(o.val))   { std::cout << "sMoveConstructed" << std::endl; }


    Historian& operator=(const std::string& v) {
        std::cout << "sValueCopyAssigned" << std::endl;
        val = v;
        return *this;
    }

    Historian& operator=(std::string&& v) {
        std::cout << "sValueMoveAssigned" << std::endl;
        val = std::move(v);
        return *this;
    }

    Historian& operator=(const Historian& o) {
        std::cout << "sCopyAssigned" << std::endl;
        val = o.val;
        return *this;
    }

    Historian& operator=(Historian&& o) {
        std::cout << "sMoveAssigned" << std::endl;
        val = std::move(o.val);
        return *this;
    }
};

class MyEx : public std::exception {
    Historian h_;
    public: 

    void where_u() const noexcept {
        std::cout << "im here: " << this << std::endl;
    }

    const char* what() const noexcept override {
        return "You got me!";
    }
};

void make_mistake() {
    MyEx ex;
    ex.where_u();
    throw ex;
}

void make_ref_mistake() {
    MyEx ex;
    ex.where_u();
    std::exception& re = ex;
    throw re;
}


int main() {
    std::cout << std::endl << "#1"  << std::endl;
    // Получение по копии:
    // warning: catching polymorphic type 'class std::exception' by value
    // Program stdout:
    // sDefaultConstructed
    // sMoveConstructed
    // catch: std::exception
    {
        try {
            make_mistake();
        } catch (std::exception e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }
    std::cout << std::endl << "#2"  << std::endl;
    // Получение по ссылке:
    // Program stdout:
    // sDefaultConstructed
    // sMoveConstructed
    // catch: std::exception
    {
        try {
            make_mistake();
        } catch (std::exception& e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }

    std::cout << std::endl << "#3"  << std::endl;
    // 
    {
        try {
            make_ref_mistake();
        } catch (std::exception e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }
    std::cout << std::endl << "#4"  << std::endl;
    // 
    {
        try {
            make_ref_mistake();
        } catch (std::exception& e) {
            std::cout << "catch: " << e.what() << std::endl;
            ((MyEx*)&e)->where_u();
        }
    }

    return 0;
}
