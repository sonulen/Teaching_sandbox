# C++
Песочница для изучения C++

## 
| Файл  | Что тестил  | 
|:------------- |:--------------- |
| [empty_base_optiomization.cpp](empty_base_optiomization.cpp) | Оптимизация пустых типов |


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


### [Скотт Мэйерс. Наиболее эффективное использование C++. 35 новых рекомендаций по улучшению ваших программ]()

| Совет  | Что тестил  | 
|:------------- |:--------------- |
| [rule_4](Meyers_Effective_C++_35/rules_4.cpp) | Создание массива объектов без дефолтного ктора |
| [rule_5](Meyers_Effective_C++_35/rules_5.cpp) | Explicit и неявные преобразования |
| [rule_10](Meyers_Effective_C++_35/rule_10.cpp) | Вызов std::terminate при втором исключении в процессе раскручивания стэка |
| [rule_12](Meyers_Effective_C++_35/rule_12.cpp) | Создание копий при throw (использование ктор копирование основанного на стат. типе) |
| [rule_12](Meyers_Effective_C++_35/rule_12_thow.cpp) | Проброс исключения дальше через throw; |
| [rule_14](Meyers_Effective_C++_35/rule_14.cpp) | Обработка неожиданных исключений (при специализации исключений, deprecated с 17) |
| [rule_20](Meyers_Effective_C++_35/rule_20.cpp) | Продление Lifetime локального объекта функции за счет const reference |
| [rule_24](Meyers_Effective_C++_35/rule_24.cpp) | Использование vptr |
| [rule_25](Meyers_Effective_C++_35/rule_25.cpp) | Возвращение ковариантных указателей через интефрейс |
| [rule_27](Meyers_Effective_C++_35/rule_27_1.cpp) | Создание объектов **только** на куче или стеке |
| [rule_27](Meyers_Effective_C++_35/rule_27_2.cpp) | Heap Tracker (отслеживатель объектов в куче) |
| [rule_28](Meyers_Effective_C++_35/rule_28.cpp) | Отличие указателей и умных указателей (неявные приведения) |
