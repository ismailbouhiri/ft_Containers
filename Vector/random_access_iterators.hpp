	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/19 14:40:02 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "../tools/tools.hpp"
#include <iostream>
namespace ft {

	template<class T>
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public :	
			typedef	T*      		pointer;
			typedef	T&				reference;
			typedef	ptrdiff_t		difference_type;
		private :
			pointer	_Pointer;
		public :
			iterator(void) : _Pointer(nullptr) {};
			iterator(pointer ptr) : _Pointer(ptr) {};
			iterator(const iterator& it) { *this = it; } ;
			~iterator(void){};
			iterator& operator=( const iterator& it) { this->_Pointer = it._Pointer; return *this; };
			operator iterator<const T>() const{ return iterator<const T>(_Pointer); }
			bool operator==(const iterator& it) const { return this->_Pointer == it._Pointer; };
			bool operator!=(const iterator& it) const { return this->_Pointer != it._Pointer; };

			reference	operator*(void) const { return *_Pointer; };
			pointer		operator->(void) const { return _Pointer; };
			iterator	operator++(int) {iterator old(*this); _Pointer++; return old; };
			iterator 	operator--(int) {iterator old(*this); _Pointer--; return old; };
			iterator 	&operator++(void) { _Pointer++; return *this; };
			iterator 	&operator--(void) { _Pointer--; return *this; };

			iterator	operator+(int n) { return (_Pointer + n); };
			iterator	operator-(int n) { return (_Pointer - n); };

			iterator	&operator+=(int n) { _Pointer = _Pointer + n; return *this; };
			iterator	&operator-=(int n) { _Pointer = _Pointer - n; return *this; };

			difference_type operator-(const iterator& it) { return _Pointer - it._Pointer; };

			bool operator<(const iterator& it) const { return (_Pointer < it._Pointer); };
			bool operator>(const iterator& it) const { return (_Pointer > it._Pointer); };
			bool operator<=(const iterator& it) const { return (_Pointer <= it._Pointer); };
			bool operator>=(const iterator& it) const { return (_Pointer >= it._Pointer); };
			
			reference operator[](const int& index) const { return _Pointer[index]; };
	};
	template <class type> 
	iterator<type>	operator+(typename ft::iterator<type>::difference_type n, ft::iterator<type>& it) { return it + n; };
}

#endif
