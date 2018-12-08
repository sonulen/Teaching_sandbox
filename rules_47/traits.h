/*
 * traits.h
 *
 *  Created on: Dec 8, 2018
 *      Author: sonulen
 */

#ifndef SB_MEYERS55_RULES_47_TRAITS_H_
#define SB_MEYERS55_RULES_47_TRAITS_H_
#include <iostream>
#include <iterator>


// Своя попытка дедуцирования типа
struct base {};
struct deque_type : public base {};
struct list_type : public base {};

template<typename Type>
struct type_deduction {
  typedef typename Type::type_info type_info;
};


/*
	Так как std struct iterator_traits требует еще несколько полей
	пришлось их заколхозить.
	Иначе вызывается __iterator_traits<type, typename = __void_t<>>
 */
template< class Value_type >
class deque {
public:
	typedef deque_type type_info;

	class iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
	typedef Value_type                         	value_type;
	typedef ptrdiff_t                   		difference_type;
	typedef Value_type*                        	pointer;
	typedef Value_type&                        	reference;
	};
};

template< class Value_type >
class list {
public:
	typedef list_type type_info;

	class iterator {
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef Value_type                         	value_type;
		typedef ptrdiff_t                   		difference_type;
		typedef Value_type*                        	pointer;
		typedef Value_type&                        	reference;
	};
};



template< class BDIter >
void w_type(BDIter, std::bidirectional_iterator_tag)
{
    std::cout << "bidirectional iterator\n";
}

template <class RAIter>
void w_type(RAIter, std::random_access_iterator_tag)
{
    std::cout << "random-access iterator\n";
}

template< class Iter >
void what_type_of_access (Iter iter)
{
	w_type(iter,
        typename std::iterator_traits<Iter>::iterator_category());
}

template <class Container>
void who(Container, deque_type)
{
    std::cout << "Deque\n";
}

template <class Container>
void who(Container, list_type)
{
    std::cout << "List\n";
}

template< class Container >
void type_of_container (Container cont) {
	who (cont, typename type_deduction<Container>::type_info());
}

#endif /* SB_MEYERS55_RULES_47_TRAITS_H_ */
