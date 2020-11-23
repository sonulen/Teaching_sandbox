/// Создание массива объектов с ктором
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <utility>

class Interface {
    public:
    Interface () = default;
    Interface (int v) : x{v} {};
    int x = 3;
};

/// Вариант 1. 
class Object {
  public:
  
  Object() {
      std::cout << "Object()" << std::endl;
  }
  
  Object(const Object&) {
      std::cout << "Object(const Object&)" << std::endl;
  }

  Object(Interface&& interface): interface_ {std::move(interface)} {
      std::cout << "Object(Interface&& interface)" << std::endl;
  };

  Object& operator= (const Object&) {
      std::cout << "operator= (const Object&)" << std::endl;
      return *this;
  }

  ~Object() {
      std::cout << "~Object()" << std::endl;
  }

  private:
  Interface interface_;
};

// Для 4го варианта
template<typename T, T... ints>
auto create(std::integer_sequence<T, ints...> int_seq) {
    return std::array<Object, sizeof...(ints)> { {Object(Interface(ints))...} };
}

template<std::size_t N>
auto create() {
    return create(std::make_index_sequence<N>{});
}

// Мэйерс пишет: "вообще говоря не существует способов передать 
// аргументы конструктору элементов массива"
int main() {
    // Вариант 1. Но костыльный
    // Сделать пустой конструктор, создать с ним массив
    // И только потом его заполнить через operator=
    {
        std::cout << "#1" << std::endl;
        Object arr[10];
        std::fill(arr, arr + 10, Object{Interface{4}});
    }
    // Вариант 2. На статике выделить буффер и в него placement new объектов
    // Но тут большой минус - деструкторы объектов надо вызвать самому.
    // Или создавать умные указатели, но это отдельная история.
    {
        std::cout << "#2" << std::endl;
        int count = 10;
        std::uint8_t buffer[sizeof(Object) * count];
        Object (&arr)[10] = (Object (&)[10]) buffer;

        for (int i = 0; i < count; i++) {
            new (&arr[i]) Object{Interface{i}};
        }

        for (auto& el : arr) {
            el.~Object();
        }
    }
    // Вариант 3. Вектор умеет создавать объекты с конструктора копирования сразу
    {
        std::cout << "#3" << std::endl;
        std::vector<Object> arr(10, Object{Interface{2}});
    }
    // Вариант 4. Сделать через Parameter pack. На статике и rvo оптимизации.
    {
        std::cout << "#4" << std::endl;
        auto arr = create<10>();
    }

    return 0;
}
