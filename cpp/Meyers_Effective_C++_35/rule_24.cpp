#include <iostream>

using namespace std;

class Base {
    public:
    virtual void first(){
        cout<< "Base first" << endl;
    }

    virtual void second(){
        cout<< "Base second" << endl;
    }    

    virtual void third(){
        cout<< "Base third" << endl;
    }      
};

class Derived : public Base {
    public:

    void first() override {
        cout<< "Derived first" << endl;
    }

    void second() override {
        cout<< "Derived second" << endl;
    }

    void third() override {
        cout<< "Derived third" << endl;
    }
};

void use_vptr (void* bptr) {
    /// Указатель на начало объекта, где и лежит vptr
    int* vptr = (int*) bptr; 
    cout << "vptr on : " << vptr << endl;

    /// Разыменовываем vptr получаем адрес самой таблицы
    int* vtable = (int*) (*vptr);
    cout << "vtable on : " << vtable << endl;

    typedef void (*func_ptr)( void );

    // Сдвиг на 2 т.к. в системе указатель 8 байт
    for (int i = 0; i <= 4; i += 2) {
        cout << "call : " << vtable + i << " | ";
        ( ( func_ptr ) vtable[i] )();
    }
}

int main() {
    Derived d;
    Base b;

    cout << "Размер int в системе: " << sizeof(int) << endl;
    cout << "Размер указателя в системе: " <<  sizeof(int*) << endl;
    
    cout<< "1. Base!" << endl;
    use_vptr(&b);
    cout<< "2. Derived!" << endl;
    use_vptr(&d);

    cout<< "End!" << endl;
}
