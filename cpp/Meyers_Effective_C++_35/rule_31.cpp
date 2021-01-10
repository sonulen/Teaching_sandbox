#include <utility>
#include <iostream>
#include <cassert>

class GameObject {
    public:
    virtual GameObject* who() = 0;
};

class Earth : public GameObject {
    public:
    Earth* who() override { return this; };
};

class SpaceShip : public GameObject {
    public:
    SpaceShip* who() override { return this; };
};

class Man : public GameObject {
    public:
    Man* who() override { return this; };
};


template <typename T, typename R>
void collapse(T& lhs, R& rhs) {
    std::cout << "Whoops!" << std::endl;
}

template <>
void collapse<Earth,SpaceShip> (Earth& lhs, SpaceShip& rhs){
    std::cout << "Earth win!" << std::endl;
}

template <>
void collapse<Man,SpaceShip> (Man& lhs, SpaceShip& rhs){
    std::cout << "SpaceShip win!" << std::endl;
}

int main() {
    Earth earth;
    SpaceShip ship;
    Man man;

    collapse(earth, ship);
    collapse(ship, earth);
    collapse(man, earth);
    collapse(man, ship);
}
