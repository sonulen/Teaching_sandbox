#include <cmath>
#include <iostream>
#include <memory>
#include <type_traits>

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

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog" << std::endl;
    }
    ~Dog() override {
        std::cout << "~Dog" << std::endl;
    }

    void voice() override {
        std::cout << "voice Dog" << std::endl;
    }
};

class Abstract_fabric {
public:
    virtual Animal* create() = 0;
};

class Animal_fabric : public Abstract_fabric {
public:
    Animal* create() override {
        return new Animal;
    }
};

class Cat_fabric : public Animal_fabric {
public:
    Cat* create() override {
        return new Cat;
    }
};

class Dog_fabric : public Animal_fabric {
public:
    Dog* create() override {
        return new Dog;
    }
};

int main() {
    Animal_fabric animf;
    Dog_fabric    dogf;
    Cat_fabric    catf;

    int step = 0;

    auto test = [&step](Abstract_fabric&& fabric) {
        std::cout << ++step << std::endl;
        std::unique_ptr<Animal> o(fabric.create());
        o->voice();
    };

    test(Animal_fabric{});
    test(Animal_fabric{});
    test(Cat_fabric{});

    return 0;
}
