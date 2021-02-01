#include <algorithm>
#include <iostream>

template<typename... bases>
struct Aggregator : bases...
{
    template<typename Visitor>
    void for_each_base(Visitor&& visitor)
    {
        (visitor(static_cast<bases*>(this)), ...);
    }

    template<typename Visitor>
    void for_each_base(Visitor&& visitor) const
    {
        (visitor(static_cast<const bases*>(this)), ...);
    }

    template<typename Visitor>
    static void static_for_each_base(Visitor&& visitor)
    {
        (visitor(static_cast<const bases*>(nullptr)), ...);
    }
};

class Item {
    public:
    virtual int price() const = 0;
};

class Pillow : public Item {
public:
    int price() const override { return 20; }
    int weight() { return 1; }
    static int refurbish() { return 2; }
};

class Radio : public Item {
public:
    int price() const override { return 30; }
    int weight() { return 3; }
    static int refurbish() { return 5; }
};

class Combine : Aggregator<Pillow, Radio> {
    public:
    
    int price() const override { 
        int total = 0;

        for_each_base([&](auto&& base) { 
            using Base = std::decay_t<decltype(*base)>;
            total += this->Base::price(); 
        });

        return total; 
    }

    int weight() { 
        int total = 0;
        for_each_base([&](auto&& base) { total += base->weight(); });
        return total; 
    }

    static int refurbish() { 
        int total = 0;
        static_for_each_base([&](auto&& base)  { 
            using Base = std::decay_t<decltype(*base)>;
            total += Base::refurbish(); 
        });
        return total; 
    }

};

  
int main() { 
    Combine combine;
    std::cout << combine.weight() << std::endl;
    std::cout << combine.price() << std::endl;
    std::cout << Combine::refurbish() << std::endl;
    
    return 0; 
}
