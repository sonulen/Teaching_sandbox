# C++
Песочница для изучения C++

## Tricks (sandbox)

* Вывод для отладки - [Debug_print](tricks/debug_print.h)
* SFINAE is_pointer реализация - [is_pointer](tricks/is_pointer_impl.h)

## Books

### [Скотт Мэйерс. Эффективное использование C++. 55 верных советов улучшить структуру и код ваших программ](Meyers_Effective_C++_55/README.md)

| Совет  | Что тестил  | 
|:------------- |:--------------- |
| [rules_3](Meyers_Effective_C++_55/rules_3/) | Const и non-const методы. const_cast. |
| [rules_4](Meyers_Effective_C++_55/rules_4/) | Ref to static. Singleton. |
| [rules_7](Meyers_Effective_C++_55/rules_7/) | Виртуальные конструктры и деструкторы при наследовании |
| [rules_12](Meyers_Effective_C++_55/rules_12/) | Наследование и реализация конструкторов копирования и своего swap. |
| [rules_15](Meyers_Effective_C++_55/rules_15/) | Smart pointers со своей функцией-деструктор. |
| [rules_24](Meyers_Effective_C++_55/rules_24/) | explicit и конструктор со значением по умолчанию |
| [rules_25](Meyers_Effective_C++_55/rules_25/) | Свой std::swap для не шаблонного пользовательского класса |
| [rules_27](Meyers_Effective_C++_55/rules_27/) | pure virtual function with default implementation |
| [rules_33](Meyers_Effective_C++_55/rules_33/) | Using-объявление функционала базового класса |
| [rules_35:NVI](Meyers_Effective_C++_55/rules_35/NVI.h) | Non-virtual interface idiom |
| [rules_35:Strategy](Meyers_Effective_C++_55/rules_35/strategy.h) | Паттерн Стартегия через функтор |
| [rules_35:Strategy classic](Meyers_Effective_C++_55/rules_35/strategy_classic.h) | Паттерн Стартегия через функц. объект |
| [rules_37](Meyers_Effective_C++_55/rules_37) | Волшебство значения по умолчанию, динамического и статического связывания |
| [rules_41](Meyers_Effective_C++_55/rules_41) | Использование неявного интерфейса |
| [rules_42](Meyers_Effective_C++_55/rules_42) | Использование вложенного зависимого от шаблона имени типа |
| [rules_47](Meyers_Effective_C++_55/rules_47) | Использование iterator_traits |
| [rules_50](Meyers_Effective_C++_55/rules_50) | Перегрузка глобальных new new[] с целью запрета на использование |
| [rules_52](Meyers_Effective_C++_55/rules_52) | Перегрузка глобальных new new[] с входными параметрами |

