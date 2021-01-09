#include <iostream>

template <class T>
class SmartPtr {
public:
    SmartPtr (T* realPrt = nullptr) : ptr(realPrt) {};

    T* operator->() const { return ptr; }

    template <class newType>
    operator SmartPtr<newType>() { return ptr; }

    template <class newType>
    operator SmartPtr<newType>&() { return ptr; }

private:
    T* ptr;
};

class Animal {
public:
    Animal() {
        std::cout << "Animal" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "~Animal" << std::endl;
    }

    virtual void voice() {
        std::cout << "voice Animal" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        std::cout << "Cat" << std::endl;
    }
    ~Cat() override {
        std::cout << "~Cat" << std::endl;
    }

    void voice() override {
        std::cout << "voice Cat" << std::endl;
    }
};

class Serval : public Cat {
public:
    Serval() {
        std::cout << "Serval" << std::endl;
    }
    ~Serval() override {
        std::cout << "~Serval" << std::endl;
    }

    void voice() override {
        std::cout << "voice Serval" << std::endl;
    }
};

void make_to_speak(Animal& animal) {
    std::cout << "Animal = "; 
    animal.voice();
}

void make_to_speak(Cat& cat) {
    std::cout << "Cat = "; 
    cat.voice();
}

void make_to_speak(SmartPtr<Cat>& cat) {
    std::cout << "Cat = "; 
    cat->voice();
}

void make_to_speak(SmartPtr<Animal>& animal) {
    std::cout << "Animal = "; 
    animal->voice();
}

int main() {
    Serval serval;
    make_to_speak(serval);

    SmartPtr<Serval> pS (new Serval);
    make_to_speak(pS); //  error: call of overloaded 'make_to_speak(SmartPtr<Serval>&)' is ambiguous
    // Не будет работать, т.к. умный указатель != обычному указателю
    // И с точки зрения компилятора все операторы неявного преобразования
    // равноценны. и выбрать он не может.
}
