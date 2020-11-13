/// Создание массива объектов с ктором
#include <algorithm>


class Interface {
    public:
    Interface (int v) : x{v} {};
    private:
    int x = 3;
};

/// Вариант 1. 
namespace variant_1 {
class Object {
  public:
  Object();
  Object(Interface&& interface) {};
};

}

int main() {
    {
        // Вариант 1. Но костыльный
        // Сделать пустой конструктор, создать с ним массив
        // И только потом его заполнить
        using variant_1::Object;
        Object array[10];
        std::fill(array, array + 10, Object{Interface{4}});

        // Вариант 1.1. Тоже самое, но без двойного вызова кторов
        // но на динамике
        std::vector<Object> arr(10, Object{Interface{2}});
    }

    // Но у всех вариантов есть минус - Ктор всегда одинаковый
    return 0;
}
