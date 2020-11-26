// Запрет неявного преобразования
using size_t = decltype(sizeof 0);

class Base {
public:
    bool operator==(Base rhs) {
        return true;
    }

    int operator[](size_t i) const {
        return 6;
    }
};

namespace v1 {
class Array : public Base {
public:
    Array(int x) {};
};
}

namespace v2 {
class Array : public Base {
    public:

    class ArraySize {
        public:
        ArraySize(int x) {};
    };

    Array(ArraySize size) {};
};
}

namespace v3 {
class Array : public Base {
public:
    explicit Array(int x) {};
};
}


int main() {
    // Неявное приведения инта к массиву
    {
        using v1::Array;
        Array a = 10;
        Array b(20);
        if (a == b) {
            // 
        }
    }
    
    {
        // Этот способ нужен если explicit по какой-то причине не доступен
        // Неявное преобразование здесь запрещается из-за того что требуется 2 неявных преобразований
        // а ++ запрещают этого. максимум 1.
        using v2::Array;
        Array a = 10; //< error: conversion from 'int' to non-scalar type 'v2::Array' requested
        Array b(20);
        if (a == b[2]) { //< error: no match for 'operator==' (operand types are 'v2::Array' and 'int')
            // 
        }
    }
    {
        using v3::Array;
        Array a = 10; //< error: conversion from 'int' to non-scalar type 'v3::Array' requested
        Array b(20);
        if (a == b[2]) { //< error: no match for 'operator==' (operand types are 'v3::Array' and 'int')
            // 
        }
    }

    return 0;
}
