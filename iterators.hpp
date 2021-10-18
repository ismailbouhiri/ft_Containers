/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/18 15:53:14 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
namespace ft{

	template<class T>
	class iterator : public std::iterator<random_access_iterator_tag, T>
	{
		private :
			pointer	_Pointer;
		public :
			iterator(void) : _Pointer(nullptr) {};
			iterator(const iterator& it) { *this = it } ;
			~iterator(void);
			iterator& operator=(const iterator& it){ this->_Pointer = it._Pointer; };

			bool operator==(const iterator& it) const { return this->_Pointer == it._Pointer};
			bool operator!=(const iterator& it) const { return this->_Pointer != it._Pointer};

			reference	operator*(void) const { return *_Pointer; };
			pointer		operator->(void) const { return _Pointer; };
			iterator	&operator++(void) { iterator old = this; _Pointer++; return old; };
			iterator 	&operator--(void) { iterator old = this; _Pointer--; return old; };
			iterator 	operator++(int) { _Pointer++; return this; };
			iterator 	operator--(int) { _Pointer--; return this; };

			iterator	&operator+(int n) { _Pointer = _Pointer + n; return this; };
			iterator	&operator-(int n) { _Pointer = _Pointer - n; return this; };

			iterator	&operator+=(int n) { _Pointer + n; return this; };
			iterator	&operator-=(int n) { _Pointer - n; return this; };

			difference_type operator-(const iterator& it) { return this->_Pointer - it._Pointer; };

			bool operator<(const iterator& it) const { return _Pointer < it._Pointer };
			bool operator>(const iterator& it) const { return _Pointer > it._Pointer };
			bool operator<=(const iterator& it) const { return _Pointer <= it._Pointer };
			bool operator>=(const iterator& it) const { return _Pointer >= it._Pointer };
			
			reference operator[](const int& index) const {return _Pointer[index]}
	};

	iterator	&operator-(const int& n, iterator& it) { return it + n; };

	template <class Iterator> 
	class iterator_traits
	{
		typedef typename Iterator::difference_type	 difference_type;
		typedef typename Iterator::value_type		 value_type;
		typedef typename Iterator::pointer			 pointer;
		typedef typename Iterator::reference		 reference;
		typedef typename Iterator::iterator_category iterator_category;
		
	};
	
	template <class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t		 					     difference_type;
		typedef T	 		     					     value_type;
		typedef T*		     						     pointer;
		typedef T&		         					     reference;
		typedef random_access_iterator_tag               iterator_category;
	};
	
	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t		 					     difference_type;
		typedef T	 		     					     value_type;
		typedef const T*		     					 pointer;
		typedef const T&		         			 	 reference;
		typedef random_access_iterator_tag               iterator_category;
	};
}

#endif
