#include <iostream>
#include <cstddef>
#include <list>
#include <algorithm>
#include <iomanip>

class HeapTracker {
    public:

    typedef const void* RawAddress;

    virtual ~HeapTracker() = 0;

    static void* operator new(size_t size) noexcept {
        void* memPtr = ::operator new(size);
        addresses.push_front(memPtr);
        return memPtr;
    }

    static void operator delete(void* ptr) noexcept {
        auto it = std::find(addresses.begin(), addresses.end(), ptr);

        if (it != addresses.end()) {
            addresses.erase(it);
            ::operator delete(ptr);
        }
        // Можно было бы бросать исключение, но что то не хочется
    }

    // Про массивы пока просто не думаем

    bool isOnHeap() const {
        // Получим указатель на начало объекта
        // dynamic_cast при касте к void* / const void* / volatile void*
        // Возвращает указатель на начало объекта this (наследника)
        // Но обязательно нужна хоть одна виртуальная функиця (у нас dtor)
        RawAddress startPtr = dynamic_cast<RawAddress>(this);

        auto it = std::find(addresses.begin(), addresses.end(), startPtr);

        return (it != addresses.end());
    }

private:
    static std::list<RawAddress> addresses;
};

std::list<HeapTracker::RawAddress> HeapTracker::addresses;
HeapTracker::~HeapTracker() {}

class UserObject : public HeapTracker {
    public:
    ~UserObject() { std::cout << "~UserObject" << std::endl; }
};

int main() {
    UserObject first;
    UserObject* second = new UserObject;

    std::cout << std::boolalpha;
    std::cout << "is first on heap - " << first.isOnHeap() << std::endl;
    std::cout << "is second on heap - " << second->isOnHeap() << std::endl;
}
